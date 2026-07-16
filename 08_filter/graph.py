import matplotlib.pyplot as plt
times = []
clean_values = []
noisy_values = []
filtered_values = []

with open("filtering_result.txt", "r") as f:
    for line in f:
        if "time" in line:
            parts = line.split(":")
            value =  float(parts[1])
            times.append(value)
        elif "clean_value:" in line:
            parts = line.split(":")
            value = float(parts[1])
            clean_values.append(value)
        elif "noisy_value:" in line:
            parts = line.split(":")
            value = float(parts[1])
            noisy_values.append(value)
        elif "filtered_value:" in line:
            parts = line.split(":")
            value = float(parts[1])
            filtered_values.append(value)

plt.plot(times, noisy_values, label="Noisy Signal", alpha=0.7)
plt.plot(times, clean_values, label="Clean Signal", linewidth=2)
plt.plot(times, filtered_values, label="Filtered Signal", linewidth=2)

plt.xlabel("Time (s)")
plt.ylabel("Value")
plt.title("Low-Pass Filter: Noisy vs Clean vs Filtered")
plt.legend()
plt.grid(True)
plt.show()
