
# The Subset Sum Solver

## Prerequisites

Ensure you have the following installed on your local machine:
- GCC (GNU Compiler Collection)
- Python 3.x
- pip (Python package installer)

## Step-by-Step Instructions

### 1. Compile the C Code

Compile the C code using GCC:

```sh
gcc -o subset_sum_solver subset_sum_solver.c
```

You can run the `subset_sum_solver.c` code directly with the following input file format.

### Input File Format

Create an `input.txt` file with the following format:

```
<number_of_sets>
<target_sum>
<set_elements_separated_by_spaces>
```

Example `input.txt`:

```
1
22
3 21 17 14 8 1 9 34 5 11
```

Run the compiled C code:

```sh
./subset_sum_solver
```

### 2. Install Python Dependencies

Install the required Python packages using pip:

```sh
pip install pandas matplotlib
```

### 3. Run the Python Script

Execute the Python script to generate the performance graphs and tables:

```sh
python generate_visualizations.py
```

This will generate two images, `runtime_graph.png` and `runtime_table.png`, displaying the performance graph and the table of results, respectively.
