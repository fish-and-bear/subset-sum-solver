import time
import subprocess
import matplotlib.pyplot as plt
import pandas as pd

# Function to generate input data
def generate_input_data(set_size, target_sum):
    test_set = list(range(1, set_size + 1))
    input_data = f"1\n{target_sum}\n{' '.join(map(str, test_set))}\n"
    with open("input.txt", "w") as f:
        f.write(input_data)

# Function to measure runtime of the C solver
def measure_runtime(set_sizes, target_sum):
    runtimes = []
    for size in set_sizes:
        generate_input_data(size, target_sum)
        start_time = time.time()
        subprocess.run(["./subset_sum_solver"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        end_time = time.time()
        runtimes.append(end_time - start_time)
    return runtimes

# Define set sizes and target sum for testing
set_sizes = [5, 10, 15, 20, 25, 30]
target_sum = 30

# Measure runtimes
runtimes = measure_runtime(set_sizes, target_sum)

# Create DataFrame for runtime data
runtime_data = {'Set Size': set_sizes, 'Running Time (seconds)': runtimes}
df = pd.DataFrame(runtime_data)

# Format the Set Size column as integers
df['Set Size'] = df['Set Size'].map('{:.0f}'.format)

# Plotting the results
plt.figure(figsize=(10, 6))
plt.plot(set_sizes, runtimes, marker='o')
plt.xlabel('Set Size')
plt.ylabel('Running Time (seconds)')
plt.title('Running Time of Iterative Backtracking Solver')
plt.grid(True)
plt.savefig('runtime_graph.png')
plt.show()

# Creating the table with visual aesthetics
fig, ax = plt.subplots(figsize=(6, 4))  # set size frame
ax.axis('tight')
ax.axis('off')
table = ax.table(cellText=df.values, colLabels=df.columns, cellLoc='center', loc='center', bbox=[0, 0, 1, 1])
table.auto_set_font_size(False)
table.set_fontsize(10)
table.scale(1.2, 1.2)
plt.savefig('runtime_table.png')
plt.show()

# Optional: Save the DataFrame to a CSV file for further analysis
#df.to_csv('runtime_data.csv', index=False)
