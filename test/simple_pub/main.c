#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>
#include <zmq.h>

int main(void) {

    void *context = zmq_ctx_new();
    void *socketSub = zmq_socket(context, ZMQ_REQ);
    int rc = -1;
    rc = zmq_bind(socketSub, "tcp://*:5959");
    printf("connect:%d\n", rc);
    
    while(1){
        printf("제발 받아라...\n");
        
        zmq_msg_t out_msg;
        char message[1000] = "testing\n";
        zmq_msg_init_size(&out_msg, strlen(message));
        memcpy(zmq_msg_data(&out_msg), message, strlen(message));
        // zmq_send(socketPub, &out_msg, 0, 0);
        rc = zmq_send (socketSub, "JK", 2, 0);
        printf("send %d\n\n", rc);
        
        char buf [256];
        int nbytes = zmq_recv (socketSub, buf, 256, 0);
        printf("I recv %d bytes\n\n", nbytes);
        
    }
    
}