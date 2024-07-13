import matplotlib.pyplot as plt
with open("output.txt", "r") as file:
    execution_times = [float(line.strip()) for line in file]
colors = ['red', 'blue', 'green']
process =["SCHED OTHER","SCHED RR","SCHED FIFO"]
for i in range(3):
    s="Process"+process[i]+" with Prioirty "+str(i+1)
    plt.hist(
        execution_times,
        bins=20,
        edgecolor="k",
        color=colors[i],
        label=s,
        alpha=0.5
    )
plt.xlabel("Execution Time (seconds)")
plt.ylabel("Frequency")
plt.title("Execution Time Distribution")
plt.legend()
plt.show()
