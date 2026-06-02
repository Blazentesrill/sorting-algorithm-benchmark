# sorting-algorithm-benchmark
A C implementation and empirical analysis of three classic sorting algorithms — **Insertion Sort**, **Quick Sort**, and **Merge Sort** — benchmarked across five input types at N=100,000 and analyzed using log-scale comparison counts.
 
---
 
## Algorithms Implemented
 
| Algorithm | Best Case | Average Case | Worst Case | Metric Tracked |
|---|---|---|---|---|
| Insertion Sort | O(n) | O(n²) | O(n²) | Comparisons |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | Comparisons |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | Assignments |
 
---
 
## Input Types
 
Each algorithm was tested against five different input distributions:
 
| Code | Description |
|---|---|
| `A` | Ascending (already sorted) |
| `D` | Descending (reverse sorted) |
| `R` | Random (values 1–N) |
| `S` | Shuffled permutation |
| `E` | Equal (all ones) |
 
---
 
## Results at N = 100,000
 
| Input Type | Merge Sort | Quick Sort | Insertion Sort |
|---|---|---|---|
| Ascending | 1,668,928 | 4,999,950,000 | 99,999 |
| Descending | 1,668,928 | 4,999,950,000 | 5,000,049,999 |
| Shuffled | 1,668,928 | 1,376,201 | 2,499,440,321 |
| Random | 1,668,928 | 1,661,000 | 2,492,525,283 |
| Equal | 1,668,928 | 4,999,995,000 | 2,497,365,817 |
 
**Key observations:**
- Merge Sort produces identical operation counts regardless of input — consistent O(n log n)
- Quick Sort (first-element pivot) degrades to O(n²) on sorted and equal inputs — classic worst-case behavior
- Insertion Sort excels on nearly-sorted data but explodes quadratically on reverse-sorted input
- On random/shuffled data, Quick Sort and Merge Sort perform comparably
---
 
## Build & Run
 
Requires `gcc` and `bash`.
 
```bash
# Compile and run via shell script
./project1.sh <N> <InputType> <SortType>
```
 
**Input type flags:** `A` `D` `R` `S` `E`
 
**Sort type flags:**
- `I` — Insertion Sort (print operation count)
- `i` — Insertion Sort (print sorted array)
- `Q` — Quick Sort (print operation count)
- `q` — Quick Sort (print sorted array)
- `M` — Merge Sort (print operation count)
- `m` — Merge Sort (print sorted array)
- `P` — Print unsorted array
**Examples:**
```bash
# Run Merge Sort on 1000 random elements, print count
echo "1000 R M" | ./project1.sh
 
# Run Quick Sort on ascending input, print sorted array
echo "500 A q" | ./project1.sh
 
# Pipe multiple test cases
echo "100000 A I
100000 A Q
100000 A M" | ./project1.sh
```
 
---
 
## Project Structure
 
```
sorting-algorithm-benchmark/
├── project1.c      # All sorting algorithm implementations
├── project1.sh     # Compile and run script
├── table1.txt      # Benchmark results at N=100,000
├── table2.txt      # Benchmark results across varying N
└── README.md
```
 
---
 
## Skills Demonstrated
 
- Algorithm implementation from scratch in C (no library sort functions)
- Empirical complexity analysis across multiple input distributions
- Identifying best/average/worst-case behavior through real data
- Log-scale data interpretation
- Bash scripting for compilation and execution automation
- Understanding of O(n²) vs O(n log n) tradeoffs in practice
 
