#include <mpi.h>
#include <iostream>
#include <random>

using namespace std;

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int rank, size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const long long TOTAL_POINTS = 10000000;

    long long points_per_process = TOTAL_POINTS / size;

    mt19937 generator(rank + 12345);
    uniform_real_distribution<double> distribution(0.0, 1.0);

    long long local_inside = 0;

    double start_time = MPI_Wtime();

    for (long long i = 0; i < points_per_process; i++)
    {
        double x = distribution(generator);
        double y = distribution(generator);

        if ((x * x + y * y) <= 1.0)
        {
            local_inside++;
        }
    }

    long long total_inside = 0;

    MPI_Reduce(
        &local_inside,
        &total_inside,
        1,
        MPI_LONG_LONG,
        MPI_SUM,
        0,
        MPI_COMM_WORLD
    );

    double end_time = MPI_Wtime();

    if (rank == 0)
    {
        double pi =
            4.0 * total_inside /
            (points_per_process * size);

        cout << "Number of Processes: " << size << endl;
        cout << "Estimated Pi: " << pi << endl;
        cout << "Execution Time: "
             << end_time - start_time
             << " seconds" << endl;
    }

    MPI_Finalize();

    return 0;
}
