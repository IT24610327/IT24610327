# SE4060 - Lab Sheet 08 - MPI

Student ID: IT24610327

## Exercise 2 - Parallel Sum

Parallelized the summation of numbers from 1 to 10,000,000 using MPI.

Expected total:

50000005000000

### Results

| Processes | Execution Time (seconds) |
|----------:|-------------------------:|
| 1 | 0.0252542 |
| 2 | 0.0140285 |
| 4 | 0.0483329 |
| 8 | 0.0300036 |

## Exercise 3 - Monte Carlo Pi

Calculated Pi using the Monte Carlo method with 10,000,000 samples.

### Results

| Processes | Estimated Pi | Execution Time (seconds) |
|----------:|-------------:|-------------------------:|
| 1 | 3.14183 | 3.33500 |
| 2 | 3.14105 | 1.92921 |
| 4 | 3.14138 | 1.93441 |
| 8 | 3.14107 | 1.94588 |

## Exercise 4 - Performance Graphs

Created graphs for:

- Execution Time vs Number of Processors
- Speedup vs Number of Processors

for both the parallel summation and Monte Carlo Pi programs.

## Exercise 5 - MPI Message Matching and Buffered Send

### Source Mismatch

Process 0 sends a message to Process 1, but Process 1 attempts to receive a message from Process 2.

Since the source does not match, MPI_Recv waits for the expected message and the program hangs.

### Buffered Send

Reimplemented message passing using MPI_Bsend and an attached MPI buffer.

## Exercise 6 - MPI_ANY_SOURCE

MPI_ANY_SOURCE allows the receiver to accept a matching message from any sending process instead of requiring a specific source.

Output:

Process 0 sent 42  
Process 1 received 42 from process 0

## Exercise 7 - MPI_Bsend with MPI_ANY_SOURCE

Reimplemented the previous exercise using MPI_Bsend together with MPI_ANY_SOURCE.

Output:

Process 0 buffered sent 42  
Process 1 received 42 from process 0
