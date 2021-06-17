PROJECT(simple_pub C)
## use pkg-config support 
find_package(PkgConfig)                 # load in pkg-config support
pkg_check_modules(PC_ZeroMQ QUIET zmq)  # use pkg-config to get hints for 0mq locations

## use zmq library
find_path(ZeroMQ_INCLUDE_DIR            # use the hint from above to find where 'zmq.hpp' is located
        NAMES zmq.h
        PATHS ${PC_ZeroMQ_INCLUDE_DIRS}
)
find_library(ZeroMQ_LIBRARY             # use the hint from about to find the location of libzmq
        NAMES zmq
        PATHS ${PC_ZeroMQ_LIBRARY_DIRS}
)

## use thread
find_package( Threads )

##use opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS}) 


## Use Protobuf
# find_package(Protobuf REQUIRED)
# if(PROTOBUF_FOUND)
#     message(STATUS "protobuf library found")
# else()
#     message(FATAL_ERROR "protobuf library is needed but cant be found")
# endif()

# include_directories(${PROTOBUF_INCLUDE_DIRS})
# INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
# PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS "../../protobuf/sensors.proto" )



# 실행파일 만들기
set(SOURCE_Simple_pub main.c
    )
add_executable(Simple_pub ${SOURCE_Simple_pub} 
    # ${PROTO_SRCS} ${PROTO_HDRS}                 # Google Protocol Buffer
    # ${OpenCV_INCLUDE_DIRS}                      # OpenCV
    )
target_include_directories(Simple_pub PUBLIC 
    ${ZeroMQ_INCLUDE_DIR}   # ZeroMQ
    ) # add the include directory to our compile directives
target_link_libraries(Simple_pub PUBLIC 
    ${ZeroMQ_LIBRARY}               # ZeroMQ
    # ${OpenCV_LIBS}                  # OpenCV
    # ${PROTOBUF_LIBRARIES}           # Google Protocol Buffer
    ) # at the 0mq library to our link directive


