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
        MPI_Recv(
            &number,
            1,
            MPI_INT,
            2,
            0,
            MPI_COMM_WORLD,
            MPI_STATUS_IGNORE
        );

        cout << "Process 1 received " << number << endl;
    }

    MPI_Finalize();
    return 0;
}
