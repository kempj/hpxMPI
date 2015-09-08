if [ $# -gt "0" ]
then
    N=$1
    #./mpi-test -c -l 2 -0 -x 127.0.0.1:7910 --hpx:run-hpx-main &
    echo "./mpi-test -c -l $N -0 -x 127.0.0.1:7910 --hpx:run-hpx-main &"
    ./mpi-test -c -l $N -0 -x 127.0.0.1:7910 --hpx:run-hpx-main &

    for i in `seq 1 $((N-1))`;
    do
        port=$((7910 + i))
        #./mpi-test -w -1 --hpx:run-hpx-main -x 127.0.0.1:7911
        echo "./mpi-test -w -$i --hpx:run-hpx-main -x 127.0.0.1:$port &"
        ./mpi-test -w -$i --hpx:run-hpx-main -x 127.0.0.1:$port &
    done
fi
