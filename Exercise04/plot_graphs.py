import matplotlib.pyplot as plt

processors = [1, 2, 4, 8]

sum_times = [0.0252542, 0.0140285, 0.0483329, 0.0300036]
sum_speedup = [1.0000, 1.8002, 0.5225, 0.8417]

pi_times = [3.33500, 1.92921, 1.93441, 1.94588]
pi_speedup = [1.0000, 1.7287, 1.7240, 1.7139]

plt.figure()
plt.plot(processors, sum_times, marker='o')
plt.xlabel("Number of Processors")
plt.ylabel("Execution Time (seconds)")
plt.title("MPI Sum - Time vs Number of Processors")
plt.grid()
plt.savefig("Exercise04/sum_time.png")
plt.close()

plt.figure()
plt.plot(processors, sum_speedup, marker='o')
plt.xlabel("Number of Processors")
plt.ylabel("Speedup")
plt.title("MPI Sum - Speedup")
plt.grid()
plt.savefig("Exercise04/sum_speedup.png")
plt.close()

plt.figure()
plt.plot(processors, pi_times, marker='o')
plt.xlabel("Number of Processors")
plt.ylabel("Execution Time (seconds)")
plt.title("Monte Carlo Pi - Time vs Number of Processors")
plt.grid()
plt.savefig("Exercise04/pi_time.png")
plt.close()

plt.figure()
plt.plot(processors, pi_speedup, marker='o')
plt.xlabel("Number of Processors")
plt.ylabel("Speedup")
plt.title("Monte Carlo Pi - Speedup")
plt.grid()
plt.savefig("Exercise04/pi_speedup.png")
plt.close()

print("Graphs generated successfully.")
