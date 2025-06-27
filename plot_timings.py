import matplotlib.pyplot as plt
import os
log_file = "jit_output.log"
phase_times = {}

with open(log_file, "r") as f:
    for line in f:
        if "took" in line:
            parts = line.strip().split()
            phase = line.strip().split(" took")[0]
            time_us = int(parts[-2])
            phase_times[phase] = time_us / 1000  # microseconds to ms

phases = list(phase_times.keys())
times = [phase_times[p] for p in phases]

plt.figure(figsize=(10, 6))
bars = plt.bar(phases, times, color='lightblue', edgecolor='black')
plt.xlabel("Compiler Phases")
plt.ylabel("Time (ms)")
plt.title("JIT Compiler Phase Performance")
plt.grid(axis='y', linestyle='--', alpha=0.6)

for bar in bars:
    yval = bar.get_height()
    plt.text(bar.get_x() + bar.get_width()/2, yval + 0.5, f"{yval:.2f}", ha='center')

plt.tight_layout()
plt.savefig("jit_timing_chart.png")  # Save instead of show
os.system("explorer.exe jit_timing_chart.png")

