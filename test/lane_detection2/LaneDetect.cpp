/*------------------------------------------------------------------------------------------*\
   Lane Detection

   General idea and some code modified from:
   chapter 7 of Computer Vision Programming using the OpenCV Library. 
   by Robert Laganiere, Packt Publishing, 2011.

   This program is free software; permission is hereby granted to use, copy, modify, 
   and distribute this source code, or portions thereof, for any purpose, without fee, 
   subject to the restriction that the copyright notice may not be removed 
   or altered from any source or altered source distribution. 
   The software is released on an as-is basis and without any warranties of any kind. 
   In particular, the software is not guaranteed to be fault-tolerant or free from failure. 
   The author disclaims all warranties with regard to this software, any use, 
   and any consequent failure, is purely the responsibility of the user.
 
   Copyright (C) 2013 Jason Dorweiler, www.transistor.io


Notes: 

	Add up number on lines that are found within a threshold of a given rho,theta and 
	use that to determine a score.  Only lines with a good enough score are kept. 

	Calculation for the distance of the car from the center.  This should also determine
	if the road in turning.  We might not want to be in the center of the road for a turn. 
	
	Several other parameters can be played with: min vote on houghp, line distance and gap.  Some
	type of feed back loop might be good to self tune these parameters. 

	We are still finding the Road, i.e. both left and right lanes.  we Need to set it up to find the
	yellow divider line in the middle. 

	Added filter on theta angle to reduce horizontal and vertical lines. 

	Added image ROI to reduce false lines from things like trees/powerlines
\*------------------------------------------------------------------------------------------*/

/*====================================
에러 대응 방법
1. Failed to load module "canberra-gtk-module"
   => sudo apt install libcanberra-gtk-module libcanberra-gtk3-module
======================================*/
#pragma once
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/videoio/videoio_c.h>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/imgproc/imgproc_c.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/core/core.hpp"

#include <iostream>
#include <vector>
#include <stdio.h>
#include "linefinder.h"

#define PI 3.1415926

using namespace cv;
using namespace std;

// 출처: https://github.com/jdorweiler/lane-detection/blob/master/LaneDetect.cpp
// 출처: https://raw.githubusercontent.com/berak/opencv_smallfry/4fdcfb7ec0712d617b37d42a16af52ed848a25e1/demo/cpp/datamatrix.cpp

#undef NDEBUG
#include <assert.h>

#if CV_SSE2
#include <xmmintrin.h>
#endif

using namespace cv;
using namespace std;

struct CV_EXPORTS DataMatrixCode
{
	char msg[4];
	Mat original;
	Mat corners;
};

class Sampler
{
public:
	Mat im;
	Point o;
	Point c, cc;
	Mat perim;
	Point fcoord(float fx, float fy);
	Point coord(int ix, int iy);
	Sampler(const Mat &_im, const Point &_o, const Point &_c, const Point &_cc);
	uchar getpixel(int ix, int iy);
	int isinside(int x, int y);
	int overlap(Sampler &other);
	int hasbars();
	void timing();
	Mat extract();
	Sampler() {}
	~Sampler() {}
};

class code
{ // used in this file only
public:
	char msg[4];
	Mat original;
	Sampler sa;
};

unsigned char cblk[256] = {34, 19, 36, 36, 51, 19, 51, 51, 66, 19, 36, 36, 66, 19, 66, 66, 49, 19, 36, 36, 51, 19, 51, 51, 49, 19, 36, 36,
						   49, 19, 49, 49, 32, 19, 36, 36, 51, 19, 51, 51, 66, 19, 36, 36, 66, 19, 66, 66, 32, 19, 36, 36, 51, 19, 51, 51, 32, 19, 36, 36, 32, 19, 32, 32,
						   17, 19, 36, 36, 51, 19, 51, 51, 66, 19, 36, 36, 66, 19, 66, 66, 49, 19, 36, 36, 51, 19, 51, 51, 49, 19, 36, 36, 49, 19, 49, 49, 17, 19, 36, 36,
						   51, 19, 51, 51, 66, 19, 36, 36, 66, 19, 66, 66, 17, 19, 36, 36, 51, 19, 51, 51, 17, 19, 36, 36, 17, 19, 17, 17, 2, 19, 2, 36, 2, 19, 2, 51, 2, 19,
						   2, 36, 2, 19, 2, 66, 2, 19, 2, 36, 2, 19, 2, 51, 2, 19, 2, 36, 2, 19, 2, 49, 2, 19, 2, 36, 2, 19, 2, 51, 2, 19, 2, 36, 2, 19, 2, 66, 2, 19, 2, 36, 2, 19,
						   2, 51, 2, 19, 2, 36, 2, 19, 2, 32, 2, 19, 2, 36, 2, 19, 2, 51, 2, 19, 2, 36, 2, 19, 2, 66, 2, 19, 2, 36, 2, 19, 2, 51, 2, 19, 2, 36, 2, 19, 2, 49, 2, 19,
						   2, 36, 2, 19, 2, 51, 2, 19, 2, 36, 2, 19, 2, 66, 2, 19, 2, 36, 2, 19, 2, 51, 2, 19, 2, 36, 2, 19, 2, 34};
unsigned char ccblk[256] = {34, 17, 2, 17, 19, 19, 2, 17, 36, 36, 2, 36, 19, 19, 2, 17, 51, 51, 2, 51, 19, 19, 2, 51, 36, 36, 2, 36, 19, 19, 2, 17,
							66, 66, 2, 66, 19, 19, 2, 66, 36, 36, 2, 36, 19, 19, 2, 66, 51, 51, 2, 51, 19, 19, 2, 51, 36, 36, 2, 36, 19, 19, 2, 17, 49, 49, 2, 49, 19, 19, 2, 49, 36,
							36, 2, 36, 19, 19, 2, 49, 51, 51, 2, 51, 19, 19, 2, 51, 36, 36, 2, 36, 19, 19, 2, 49, 66, 66, 2, 66, 19, 19, 2, 66, 36, 36, 2, 36, 19, 19, 2, 66, 51, 51,
							2, 51, 19, 19, 2, 51, 36, 36, 2, 36, 19, 19, 2, 17, 32, 32, 2, 32, 19, 19, 2, 32, 36, 36, 2, 36, 19, 19, 2, 32, 51, 51, 2, 51, 19, 19, 2, 51, 36, 36, 2,
							36, 19, 19, 2, 32, 66, 66, 2, 66, 19, 19, 2, 66, 36, 36, 2, 36, 19, 19, 2, 66, 51, 51, 2, 51, 19, 19, 2, 51, 36, 36, 2, 36, 19, 19, 2, 32, 49, 49, 2, 49,
							19, 19, 2, 49, 36, 36, 2, 36, 19, 19, 2, 49, 51, 51, 2, 51, 19, 19, 2, 51, 36, 36, 2, 36, 19, 19, 2, 49, 66, 66, 2, 66, 19, 19, 2, 66, 36, 36, 2, 36, 19,
							19, 2, 66, 51, 51, 2, 51, 19, 19, 2, 51, 36, 36, 2, 36, 19, 19, 2, 34};
#if CV_SSE2
static const Point pickup[64] = {{7, 6}, {8, 6}, {7, 5}, {8, 5}, {1, 5}, {7, 4}, {8, 4}, {1, 4}, {1, 8}, {2, 8}, {1, 7}, {2, 7}, {3, 7}, {1, 6}, {2, 6}, {3, 6}, {3, 2}, {4, 2}, {3, 1}, {4, 1}, {5, 1}, {3, 8}, {4, 8}, {5, 8}, {6, 1}, {7, 1}, {6, 8}, {7, 8}, {8, 8}, {6, 7}, {7, 7}, {8, 7}, {4, 7}, {5, 7}, {4, 6}, {5, 6}, {6, 6}, {4, 5}, {5, 5}, {6, 5}, {2, 5}, {3, 5}, {2, 4}, {3, 4}, {4, 4}, {2, 3}, {3, 3}, {4, 3}, {8, 3}, {1, 3}, {8, 2}, {1, 2}, {2, 2}, {8, 1}, {1, 1}, {2, 1}, {5, 4}, {6, 4}, {5, 3}, {6, 3}, {7, 3}, {5, 2}, {6, 2}, {7, 2}};
static const uchar Alog[256] = {1, 2, 4, 8, 16, 32, 64, 128, 45, 90, 180, 69, 138, 57, 114, 228, 229, 231, 227, 235, 251, 219, 155, 27,
								54, 108, 216, 157, 23, 46, 92, 184, 93, 186, 89, 178, 73, 146, 9, 18, 36, 72, 144, 13, 26, 52, 104, 208, 141, 55, 110, 220, 149, 7, 14, 28,
								56, 112, 224, 237, 247, 195, 171, 123, 246, 193, 175, 115, 230, 225, 239, 243, 203, 187, 91, 182, 65, 130, 41, 82, 164, 101, 202, 185, 95,
								190, 81, 162, 105, 210, 137, 63, 126, 252, 213, 135, 35, 70, 140, 53, 106, 212, 133, 39, 78, 156, 21, 42, 84, 168, 125, 250, 217, 159, 19,
								38, 76, 152, 29, 58, 116, 232, 253, 215, 131, 43, 86, 172, 117, 234, 249, 223, 147, 11, 22, 44, 88, 176, 77, 154, 25, 50, 100, 200, 189, 87,
								174, 113, 226, 233, 255, 211, 139, 59, 118, 236, 245, 199, 163, 107, 214, 129, 47, 94, 188, 85, 170, 121, 242, 201, 191, 83, 166, 97, 194,
								169, 127, 254, 209, 143, 51, 102, 204, 181, 71, 142, 49, 98, 196, 165, 103, 206, 177, 79, 158, 17, 34, 68, 136, 61, 122, 244, 197, 167, 99,
								198, 161, 111, 222, 145, 15, 30, 60, 120, 240, 205, 183, 67, 134, 33, 66, 132, 37, 74, 148, 5, 10, 20, 40, 80, 160, 109, 218, 153, 31, 62,
								124, 248, 221, 151, 3, 6, 12, 24, 48, 96, 192, 173, 119, 238, 241, 207, 179, 75, 150, 1};
static const uchar Log[256] = {(uchar)-255, 255, 1, 240, 2, 225, 241, 53, 3, 38, 226, 133, 242, 43, 54, 210, 4, 195, 39,
							   114, 227, 106, 134, 28, 243, 140, 44, 23, 55, 118, 211, 234, 5, 219, 196, 96, 40, 222, 115, 103, 228, 78, 107, 125,
							   135, 8, 29, 162, 244, 186, 141, 180, 45, 99, 24, 49, 56, 13, 119, 153, 212, 199, 235, 91, 6, 76, 220, 217, 197, 11, 97,
							   184, 41, 36, 223, 253, 116, 138, 104, 193, 229, 86, 79, 171, 108, 165, 126, 145, 136, 34, 9, 74, 30, 32, 163, 84, 245,
							   173, 187, 204, 142, 81, 181, 190, 46, 88, 100, 159, 25, 231, 50, 207, 57, 147, 14, 67, 120, 128, 154, 248, 213, 167,
							   200, 63, 236, 110, 92, 176, 7, 161, 77, 124, 221, 102, 218, 95, 198, 90, 12, 152, 98, 48, 185, 179, 42, 209, 37, 132,
							   224, 52, 254, 239, 117, 233, 139, 22, 105, 27, 194, 113, 230, 206, 87, 158, 80, 189, 172, 203, 109, 175, 166, 62, 127,
							   247, 146, 66, 137, 192, 35, 252, 10, 183, 75, 216, 31, 83, 33, 73, 164, 144, 85, 170, 246, 65, 174, 61, 188, 202, 205,
							   157, 143, 169, 82, 72, 182, 215, 191, 251, 47, 178, 89, 151, 101, 94, 160, 123, 26, 112, 232, 21, 51, 238, 208, 131,
							   58, 69, 148, 18, 15, 16, 68, 17, 121, 149, 129, 19, 155, 59, 249, 70, 214, 250, 168, 71, 201, 156, 64, 60, 237, 130,
							   111, 20, 93, 122, 177, 150};
#endif

#define dethresh 0.92f
#define eincO (2 * dethresh)	  // e increment orthogonal
#define eincD (1.414f * dethresh) // e increment diagonal

#define Ki(x) _mm_set_epi32((x), (x), (x), (x))
#define Kf(x) _mm_set_ps((x), (x), (x), (x))

#if CV_SSE2
static const int CV_DECL_ALIGNED(16) absmask[] = {0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff};
#define _mm_abs_ps(x) _mm_and_ps((x), *(const __m128 *)absmask)
#endif

Sampler::Sampler(const Mat &_im, const Point &_o, const Point &_c, const Point &_cc)
{
	im = _im;
	o = _o;
	c = _c;
	cc = _cc;
	perim = Mat(4, 1, CV_32SC2);
	perim.at<Point>(0, 0) = fcoord(-.2f, -.2f);
	perim.at<Point>(1, 0) = fcoord(-.2f, 1.2f);
	perim.at<Point>(2, 0) = fcoord(1.2f, 1.2f);
	perim.at<Point>(3, 0) = fcoord(1.2f, -.2f);
	// printf("Sampler %d,%d %d,%d %d,%d\n", o.x, o.y, c.x, c.y, cc.x, cc.y);
}

Point Sampler::fcoord(float fx, float fy)
{
	Point r;
	r.x = (int)(o.x + fx * (cc.x - o.x) + fy * (c.x - o.x));
	r.y = (int)(o.y + fx * (cc.y - o.y) + fy * (c.y - o.y));
	return r;
}

Point Sampler::coord(int ix, int iy)
{
	return fcoord(0.05f + 0.1f * ix, 0.05f + 0.1f * iy);
}

uchar Sampler::getpixel(int ix, int iy)
{
	Point pt = coord(ix, iy);
	if ((0 <= pt.x) && (pt.x < im.cols) && (0 <= pt.y) && (pt.y < im.rows))
		return im.at<uchar>(pt.y, pt.x);
	else
		return 0;
}

int Sampler::isinside(int x, int y)
{
	Point2f pt;
	pt.x = (float)x;
	pt.y = (float)y;
	if ((0 <= pt.x) && (pt.x < im.cols) && (0 <= pt.y) && (pt.y < im.rows))
		return pointPolygonTest(perim, pt, 0) < 0;
	else
		return 0;
}

int Sampler::overlap(Sampler &other)
{
	for (int i = 0; i < 4; i++)
	{
		Point p;
		p = other.perim.at<Point>(i, 0);
		if (isinside(p.x, p.y))
			return 1;
		p = perim.at<Point>(i, 0);
		if (other.isinside(p.x, p.y))
			return 1;
	}
	return 0;
}

int Sampler::hasbars()
{
	return getpixel(9, 1) > getpixel(9, 0);
}

void Sampler::timing()
{
	/*uchar light, dark = getpixel(9, 0);
  for (int i = 1; i < 3; i += 2) {
    light = getpixel(9, i);
    // if (light <= dark)
    //  goto endo;
    dark = getpixel(9, i + 1);
    // if (up <= down)
    //  goto endo;
  }*/
}

Mat Sampler::extract()
{
	// return a 10x10 CvMat for the current contents, 0 is black, 255 is white
	// Sampler has (0,0) at bottom left, so invert Y
	Mat r(10, 10, CV_8UC1);
	for (int x = 0; x < 10; x++)
		for (int y = 0; y < 10; y++)
			r.at<uchar>(9 - y, x) = (getpixel(x, y) < 128) ? 0 : 255;
	return r;
}

#if CV_SSE2
static void apron(Mat v)
{
	int r = v.rows;
	int c = v.cols;
	v.row(0).setTo(0x22);
	v.row(1).setTo(0x22);
	v.row(r - 2).setTo(0x22);
	v.row(r - 1).setTo(0x22);
	v.col(0).setTo(0x22);
	v.col(1).setTo(0x22);
	v.col(c - 2).setTo(0x22);
	v.col(c - 1).setTo(0x22);
}

static void cfollow(const Mat &src, Mat &dst)
{
	int sx, sy;
	const uchar *vpd = src.ptr<uchar>();
	for (sy = 0; sy < src.rows; sy++)
	{
		short *wr = dst.ptr<short>(sy);
		for (sx = 0; sx < src.cols; sx++)
		{
			int x = sx;
			int y = sy;
			float e = 0;
			int ontrack = true;
			int dir;

			while (ontrack)
			{
				dir = vpd[y * src.step[0] + x];
				int xd = ((dir & 0xf) - 2);
				int yd = ((dir >> 4) - 2);
				e += (dir == 0x22) ? 999 : ((dir & 1) ? eincD : eincO);
				x += xd;
				y += yd;
				if (e > 10.)
				{
					float d = (float)(((x - sx) * (x - sx)) + ((y - sy) * (y - sy)));
					ontrack = d > (e * e);
				}
			}
			if ((24 <= e) && (e < 999))
			{
				// printf("sx=%d, sy=%d, x=%d, y=%d\n", sx, sy, x, y);
				*wr++ = (short)(x - sx);
				*wr++ = (short)(y - sy);
			}
			else
			{
				*wr++ = 0;
				*wr++ = 0;
			}
		}
	}
}

static uchar gf256mul(uchar a, uchar b)
{
	return Alog[(Log[a] + Log[b]) % 255];
}

static int decode(Sampler &sa, code &cc)
{
	uchar binary[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	uchar b = 0;
	int sum;

	sum = 0;

	for (int i = 0; i < 64; i++)
		sum += sa.getpixel(1 + (i & 7), 1 + (i >> 3));
	uchar mean = (uchar)(sum / 64);
	for (int i = 0; i < 64; i++)
	{
		b = (b << 1) + (sa.getpixel(pickup[i].x, pickup[i].y) <= mean);
		if ((i & 7) == 7)
		{
			binary[i >> 3] = b;
			b = 0;
		}
	}

	// Compute the 5 RS codewords for the 3 datawords

	uchar c[5] = {0, 0, 0, 0, 0};
	{
		uchar a[5] = {228, 48, 15, 111, 62};
		int k = 5;
		for (int i = 0; i < 3; i++)
		{
			uchar t = binary[i] ^ c[4];
			for (int j = k - 1; j != -1; j--)
			{
				if (t == 0)
					c[j] = 0;
				else
					c[j] = gf256mul(t, a[j]);
				if (j > 0)
					c[j] = c[j - 1] ^ c[j];
			}
		}
	}

	if ((c[4] == binary[3]) &&
		(c[3] == binary[4]) &&
		(c[2] == binary[5]) &&
		(c[1] == binary[6]) &&
		(c[0] == binary[7]))
	{
		uchar x = 0xff & (binary[0] - 1);
		uchar y = 0xff & (binary[1] - 1);
		uchar z = 0xff & (binary[2] - 1);
		cc.msg[0] = x;
		cc.msg[1] = y;
		cc.msg[2] = z;
		cc.msg[3] = 0;
		cc.sa = sa;
		cc.original = sa.extract();
		return 1;
	}
	else
	{
		return 0;
	}
}

static deque<Point> trailto(const Mat &v, int x, int y, const Mat &terminal)
{
	Point np;
	/* Return the last 10th of the trail of points following v from (x,y)
   * to terminal
   */
	Vec2w w = terminal.at<Vec2w>(y, x);
	int ex = x + w[0];
	int ey = y + w[1];
	deque<Point> r;
	while ((x != ex) || (y != ey))
	{
		np.x = x;
		np.y = y;
		r.push_back(np);
		int dir = v.at<int>(y, x);
		int xd = ((dir & 0xf) - 2);
		int yd = ((dir >> 4) - 2);
		x += xd;
		y += yd;
	}

	int l = (int)(r.size() * 9 / 10);
	while (l--)
		r.pop_front();
	return r;
}
#endif

deque<DataMatrixCode> findDataMatrix(const Mat &im)
{
#if CV_SSE2
int cnt = 0;
	int r = im.rows;
	int c = im.cols;
	cout << "step " << cnt++ <<endl; //

	Mat thresh(r, c, CV_8UC1);
	Mat vecpic(r, c, CV_8UC1);
	Mat vc(r, c, CV_8UC1);
	Mat vcc(r, c, CV_8UC1);
	Mat cxy(r, c, CV_16SC2);
	Mat ccxy(r, c, CV_16SC2);

	adaptiveThreshold(im, thresh, 255.0, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 13, 1.0);
	{
	cout << "step " << cnt++ <<endl; //
		int x, y;
		int sstride = thresh.step[0];
		int sw = thresh.cols; // source width
		printf("thresh.rows=%d, thresh.cols=%d\n", thresh.rows, thresh.cols);
		// for (y = 2; y < thresh.rows - 2; y++)
		for (y = 2; y < 4; y++)
		{
			uchar *ps = thresh.ptr<uchar>(y);
			uchar *pd = vecpic.ptr<uchar>(y);
			uchar *pvc = vc.ptr<uchar>(y);
			uchar *pvcc = vcc.ptr<uchar>(y);
			// for (x = 0; x < sw; x++)
			for (x = 0; x < sw; x++)
			{
				uchar v =
					(0x01 & ps[-2 * sstride]) |
					(0x02 & ps[-sstride + 1]) |
					(0x04 & ps[2]) |
					(0x08 & ps[sstride + 1]) |
					(0x10 & ps[2 * sstride]) |
					(0x20 & ps[sstride - 1]) |
					(0x40 & ps[-2]) |
					(0x80 & ps[-sstride - 1]);
				*pd++ = v;
				*pvc++ = cblk[v];
				*pvcc++ = ccblk[v];
				ps++;
			}
		}
		apron(vc);
		apron(vcc);
	}

	cfollow(vc, cxy);
	cfollow(vcc, ccxy);

	deque<Point> candidates;
	{
		int x, y;
		int rows = cxy.rows;
		int cols = cxy.cols;
		for (y = 0; y < rows; y++)
		{
			const short *cd = (const short *)cxy.ptr<ushort>(y);
			const short *ccd = (const short *)ccxy.ptr<ushort>(y);
			for (x = 0; x < cols; x += 4, cd += 8, ccd += 8)
			{
				__m128i v = _mm_loadu_si128((const __m128i *)cd);
				__m128 cyxyxA = _mm_cvtepi32_ps(_mm_srai_epi32(_mm_unpacklo_epi16(v, v), 16));
				__m128 cyxyxB = _mm_cvtepi32_ps(_mm_srai_epi32(_mm_unpackhi_epi16(v, v), 16));
				__m128 cx = _mm_shuffle_ps(cyxyxA, cyxyxB, _MM_SHUFFLE(2, 0, 2, 0));
				__m128 cy = _mm_shuffle_ps(cyxyxA, cyxyxB, _MM_SHUFFLE(3, 1, 3, 1));
				__m128 cmag = _mm_sqrt_ps(_mm_add_ps(_mm_mul_ps(cx, cx), _mm_mul_ps(cy, cy)));
				__m128 crmag = _mm_rcp_ps(cmag);
				__m128 ncx = _mm_mul_ps(cx, crmag);
				__m128 ncy = _mm_mul_ps(cy, crmag);

				v = _mm_loadu_si128((const __m128i *)ccd);
				__m128 ccyxyxA = _mm_cvtepi32_ps(_mm_srai_epi32(_mm_unpacklo_epi16(v, v), 16));
				__m128 ccyxyxB = _mm_cvtepi32_ps(_mm_srai_epi32(_mm_unpackhi_epi16(v, v), 16));
				__m128 ccx = _mm_shuffle_ps(ccyxyxA, ccyxyxB, _MM_SHUFFLE(2, 0, 2, 0));
				__m128 ccy = _mm_shuffle_ps(ccyxyxA, ccyxyxB, _MM_SHUFFLE(3, 1, 3, 1));
				__m128 ccmag = _mm_sqrt_ps(_mm_add_ps(_mm_mul_ps(ccx, ccx), _mm_mul_ps(ccy, ccy)));
				__m128 ccrmag = _mm_rcp_ps(ccmag);
				__m128 nccx = _mm_mul_ps(ccx, ccrmag);
				__m128 nccy = _mm_mul_ps(ccy, ccrmag);

				__m128 dot = _mm_mul_ps(_mm_mul_ps(ncx, nccx), _mm_mul_ps(ncy, nccy));
				// iscand = (cmag > 30) & (ccmag > 30) & (numpy.minimum(cmag, ccmag) * 1.1 > numpy.maximum(cmag, ccmag)) & (abs(dot) < 0.25)
				__m128 iscand = _mm_and_ps(_mm_cmpgt_ps(cmag, Kf(30)), _mm_cmpgt_ps(ccmag, Kf(30)));

				iscand = _mm_and_ps(iscand, _mm_cmpgt_ps(_mm_mul_ps(_mm_min_ps(cmag, ccmag), Kf(1.1f)), _mm_max_ps(cmag, ccmag)));
				iscand = _mm_and_ps(iscand, _mm_cmplt_ps(_mm_abs_ps(dot), Kf(0.25f)));

				unsigned int CV_DECL_ALIGNED(16) result[4];
				_mm_store_ps((float *)result, iscand);
				int ix;
				Point np;
				for (ix = 0; ix < 4; ix++)
				{
					if (result[ix])
					{
						np.x = x + ix;
						np.y = y;
						candidates.push_back(np);
					}
				}
			}
		}
	}

	deque<code> codes;
	size_t i, j, k;
	while (!candidates.empty())
	{
		Point o = candidates.front();
		candidates.pop_front();
		deque<Point> ptc = trailto(vc, o.x, o.y, cxy);
		deque<Point> ptcc = trailto(vcc, o.x, o.y, ccxy);
		for (j = 0; j < ptc.size(); j++)
		{
			for (k = 0; k < ptcc.size(); k++)
			{
				code cc;
				Sampler sa(im, o, ptc[j], ptcc[k]);
				for (i = 0; i < codes.size(); i++)
				{
					if (sa.overlap(codes[i].sa))
					{
						sa.perim.release();
						goto endo;
					}
				}
				if (codes.size() > 0)
				{
					//printf("searching for more\n");
				}
				if (decode(sa, cc))
				{
					codes.push_back(cc);
					goto endo;
				}

				sa.perim.release();
			}
		}
	endo:; // end search for this o
	}

	deque<DataMatrixCode> rc;
	for (i = 0; i < codes.size(); i++)
	{
		DataMatrixCode cc;
		strcpy(cc.msg, codes[i].msg);
		cc.original = codes[i].original;
		cc.corners = codes[i].sa.perim;
		rc.push_back(cc);
	}
	return rc;
#else
	(void)im;
	deque<DataMatrixCode> rc;
	return rc;
#endif
}

void findDataMatrix(InputArray _image,
					vector<string> &codes,
					OutputArray _corners,
					OutputArrayOfArrays _dmtx)
{
	int cnt = 0;
	cout << "step " << cnt++ <<endl; //

	Mat image = _image.getMat();
	cout << "step " << cnt++ <<endl; //
	deque<DataMatrixCode> rc = findDataMatrix(image);
	cout << "step " << cnt++ <<endl; //
	int i, n = (int)rc.size();
	Mat corners;
	cout << "step " << cnt++ <<endl; //

	if (_corners.needed())
	{
		_corners.create(n, 4, CV_32SC2);
		corners = _corners.getMat();
	}
	cout << "step " << cnt++ <<endl; //

	if (_dmtx.needed())
		_dmtx.create(n, 1, CV_8U);

	codes.resize(n);
	cout << "step " << cnt++ <<endl; //

	for (i = 0; i < n; i++)
	{
		DataMatrixCode &rc_i = rc[i];
		codes[i] = string(rc_i.msg);

		if (corners.data)
		{
			const Point *srcpt = rc_i.corners.ptr<Point>();
			Point *dstpt = corners.ptr<Point>(i);
			for (int k = 0; k < 4; k++)
				dstpt[k] = srcpt[k];
		}

		if (_dmtx.needed())
		{
			_dmtx.create(rc_i.original.rows, rc_i.original.cols, rc_i.original.type(), i);
			Mat dst = _dmtx.getMat(i);
			Mat(rc_i.original).copyTo(dst);
		}
	}
	cout << "step " << cnt++ <<endl; //
}

void drawDataMatrixCodes(InputOutputArray _image,
						 const vector<string> &codes,
						 InputArray _corners)
{
	Mat image = _image.getMat();
	Mat corners = _corners.getMat();
	int i, n = corners.rows;

	if (n > 0)
	{
		CV_Assert(corners.depth() == CV_32S &&
				  corners.cols * corners.channels() == 8 &&
				  n == (int)codes.size());
	}

	for (i = 0; i < n; i++)
	{
		Scalar c(0, 255, 0);
		Scalar c2(255, 0, 0);
		const Point *pt = (const Point *)corners.ptr(i);

		for (int k = 0; k < 4; k++)
			line(image, pt[k], pt[(k + 1) % 4], c);
		//int baseline = 0;
		//Size sz = getTextSize(code_text, CV_FONT_HERSHEY_SIMPLEX, 1, 1, &baseline);
		putText(image, codes[i], pt[0], CV_FONT_HERSHEY_SIMPLEX, 0.8, c2, 1, CV_AA, false);
	}
}

int main(int argc, char *argv[])
{
	int houghVote = 200;
	string arg = argv[1];
	bool showSteps = argv[2];

	string window_name = "Processed Video";
	namedWindow(window_name, CV_WINDOW_KEEPRATIO); //resizable window;
	VideoCapture capture(arg);
	printf("captuer: %s\n", arg.c_str());

	if (!capture.isOpened()) //if this fails, try to open as a video camera, through the use of an integer param
	{
		capture.open(atoi(arg.c_str()));
		printf("capture is not opened!\n");
	}

	double dWidth = capture.get(CV_CAP_PROP_FRAME_WIDTH);	//get the width of frames of the video
	double dHeight = capture.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	std::cout << "Frame Size = " << dWidth << "x" << dHeight << std::endl;

	Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));

	// VideoWriter oVideoWriter("LaneDetection_result.avi", CV_FOURCC('P', 'I', 'M', '1'), 20, frameSize, true); //initialize the VideoWriter object
	VideoWriter oVideoWriter("LaneDetection_result.avi", CV_FOURCC('X','V','I','D'), 20, frameSize, true); //initialize the VideoWriter object

	Mat image;
	image = imread(argv[1]);
	int cnt = 0;
	while (1)
	{
		capture >> image;
		image.resize(image.cols/2, image.rows/2); //

		printf("image: width=%d, height=%d\n", image.cols, image.rows);

		capture >> image;
		if (image.empty())
			break;
		cout << "step " << cnt++ <<endl; //

		Mat gray;
		cvtColor(image, gray, CV_RGB2GRAY);
		cout << "step " << cnt++ <<endl; //
		vector<string> codes;
		Mat corners;
		findDataMatrix(gray, codes, corners, Mat());
		cout << "step " << cnt++ <<endl; //
		drawDataMatrixCodes(image, codes, corners);
		cout << "step " << cnt++ <<endl; //

		Rect roi(0, image.cols / 3, image.cols - 1, image.rows - image.cols / 3); // set the ROI for the image
		Mat imgROI = image(roi);
		// Display the image
		if (showSteps)
		{
			namedWindow("Original Image");
			imshow("Original Image", imgROI);
			imwrite("original.bmp", imgROI);
		}
		cout << "step " << cnt++ <<endl; //

		// Canny algorithm
		Mat contours;
		Canny(imgROI, contours, 50, 250);
		Mat contoursInv;
		threshold(contours, contoursInv, 128, 255, THRESH_BINARY_INV);

		// Display Canny image
		if (showSteps)
		{
			namedWindow("Contours");
			imshow("Contours1", contoursInv);
			imwrite("contours.bmp", contoursInv);
		}

		/* 
	Hough tranform for line detection with feedback
	Increase by 25 for the next frame if we found some lines.  
	This is so we don't miss other lines that may crop up in the next frame
	but at the same time we don't want to start the feed back loop from scratch. 
*/
		std::vector<Vec2f> lines;
		if (houghVote < 1 or lines.size() > 2)
		{ // we lost all lines. reset
			houghVote = 200;
		}
		else
		{
			houghVote += 25;
		}
		while (lines.size() < 5 && houghVote > 0)
		{
			HoughLines(contours, lines, 1, PI / 180, houghVote);
			houghVote -= 5;
		}
		std::cout << houghVote << "\n";
		Mat result(imgROI.size(), CV_8U, Scalar(255));
		imgROI.copyTo(result);

		// Draw the limes
		std::vector<Vec2f>::const_iterator it = lines.begin();
		Mat hough(imgROI.size(), CV_8U, Scalar(0));
		while (it != lines.end())
		{

			float rho = (*it)[0];	// first element is distance rho
			float theta = (*it)[1]; // second element is angle theta

			if (theta > 0.09 && theta < 1.48 || theta < 3.14 && theta > 1.66)
			{ // filter to remove vertical and horizontal lines

				// point of intersection of the line with first row
				Point pt1(rho / cos(theta), 0);
				// point of intersection of the line with last row
				Point pt2((rho - result.rows * sin(theta)) / cos(theta), result.rows);
				// draw a white line
				line(result, pt1, pt2, Scalar(255), 8);
				line(hough, pt1, pt2, Scalar(255), 8);
			}

			//std::cout << "line: (" << rho << "," << theta << ")\n";
			++it;
		}

		// Display the detected line image
		if (showSteps)
		{
			namedWindow("Detected Lines with Hough");
			imshow("Detected Lines with Hough", result);
			imwrite("hough.bmp", result);
		}
		// Create LineFinder instance
		LineFinder ld;

		// Set probabilistic Hough parameters
		ld.setLineLengthAndGap(60, 10);
		ld.setMinVote(4);

		// Detect lines
		std::vector<Vec4i> li = ld.findLines(contours);
		Mat houghP(imgROI.size(), CV_8U, Scalar(0));
		ld.setShift(0);
		ld.drawDetectedLines(houghP);
		std::cout << "First Hough"
				  << "\n";

		if (showSteps)
		{
			namedWindow("Detected Lines with HoughP");
			imshow("Detected Lines with HoughP", houghP);
			imwrite("houghP.bmp", houghP);
		}

		// bitwise AND of the two hough images
		bitwise_and(houghP, hough, houghP);
		Mat houghPinv(imgROI.size(), CV_8U, Scalar(0));
		Mat dst(imgROI.size(), CV_8U, Scalar(0));
		threshold(houghP, houghPinv, 150, 255, THRESH_BINARY_INV); // threshold and invert to black lines

		if (showSteps)
		{
			namedWindow("Detected Lines with Bitwise");
			imshow("Detected Lines with Bitwise", houghPinv);
		}

		Canny(houghPinv, contours, 100, 350);
		li = ld.findLines(contours);
		// Display Canny image
		if (showSteps)
		{
			namedWindow("Contours");
			imshow("Contours2", contours);
			imwrite("contours.bmp", contoursInv);
		}

		// Set probabilistic Hough parameters
		ld.setLineLengthAndGap(5, 2);
		ld.setMinVote(1);
		ld.setShift(image.cols / 3);
		ld.drawDetectedLines(image);

		std::stringstream stream;
		stream << "Lines Segments: " << lines.size();

		putText(image, stream.str(), Point(10, image.rows - 10), 2, 0.8, Scalar(0, 0, 255), 0);
		imshow(window_name, image);
		imwrite("processed.bmp", image);

		oVideoWriter.write(image); //writer the frame into the file
		
		char key = (char)waitKey(10);
		lines.clear();
	}

	oVideoWriter.release();
}
