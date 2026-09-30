#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int number;

    int buffer_size = sizeof(int) + MPI_BSEND_OVERHEAD;
    char* buffer = new char[buffer_size];

    MPI_Buffer_attach(buffer, buffer_size);

    if (rank == 0)
    {
        number = 42;

        MPI_Bsend(
            &number,
            1,
            MPI_INT,
            1,
            0,
            MPI_COMM_WORLD
        );

        cout << "Process 0 buffered sent "
             << number << endl;
    }

    else if (rank == 1)
    {
        MPI_Status status;

        MPI_Recv(
            &number,
            1,
            MPI_INT,
            MPI_ANY_SOURCE,
            0,
            MPI_COMM_WORLD,
            &status
        );

        cout << "Process 1 received "
             << number
             << " from process "
             << status.MPI_SOURCE
             << endl;
    }

    void* detached_buffer;
    int detached_size;

    MPI_Buffer_detach(
        &detached_buffer,
        &detached_size
    );

    delete[] buffer;

    MPI_Finalize();
    return 0;
}
