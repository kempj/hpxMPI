
enum MPI_Datatype { 
    MPI_CHAR,
    MPI_UNSIGNED_CHAR,
    MPI_BYTE,
    MPI_SHORT,
    MPI_UNSIGNED_SHORT,
    MPI_INT,
    MPI_UNSIGNED,
    MPI_LONG,
    MPI_UNSIGNED_LONG,
    MPI_LONG_LONG_INT,
    MPI_FLOAT,
    MPI_DOUBLE,
    MPI_LONG_DOUBLE
};

struct MPI_Status {
    int MPI_SOURCE;
    int MPI_TAG;
    int MPI_ERROR;
    //int count;
    //int cancelled;
};
