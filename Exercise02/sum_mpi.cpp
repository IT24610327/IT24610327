#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int rank, size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const long long N = 10000000;

    long long chunk = N / size;

    long long start = rank * chunk + 1;
    long long end;

    if (rank == size - 1)
        end = N;
    else
        end = (rank + 1) * chunk;

    long long local_sum = 0;

    double start_time = MPI_Wtime();

    for (long long i = start; i <= end; i++)
    {
        local_sum += i;
    }

    long long total_sum = 0;

    MPI_Reduce(
        &local_sum,
        &total_sum,
        1,
        MPI_LONG_LONG,
        MPI_SUM,
        0,
        MPI_COMM_WORLD
    );

    double end_time = MPI_Wtime();

    if (rank == 0)
    {
        cout << "Number of Processes: " << size << endl;
        cout << "Total Sum: " << total_sum << endl;
        cout << "Execution Time: "
             << end_time - start_time
             << " seconds" << endl;
    }

    MPI_Finalize();

    return 0;
}
