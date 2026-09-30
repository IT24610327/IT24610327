#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int number;

    if (rank == 0)
    {
        number = 42;

        MPI_Send(
            &number,
            1,
            MPI_INT,
            1,
            0,
            MPI_COMM_WORLD
        );

        cout << "Process 0 sent " << number << endl;
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

    MPI_Finalize();
    return 0;
}
