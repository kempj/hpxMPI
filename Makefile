HPX_BUILD_TYPE=hpx_application
CC=g++
OPT= -O3
CFLAGS=

all: mpi-test	


mpi-test: mpi-test.cpp
	$(CC) $(FLAGS) mpi-test.cpp -o mpi-test `pkg-config --cflags --libs $(HPX_BUILD_TYPE)` 


