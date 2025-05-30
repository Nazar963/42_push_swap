# Push_Swap: Radix Sort Implementation 🔢

[![42 School](https://img.shields.io/badge/42-School-blue)](https://42firenze.it/)
[![GitHub license](https://img.shields.io/github/license/Nazar963/42_push_swap)](https://github.com/Nazar963/42_push_swap/blob/main/LICENSE)
[![Build Status](https://img.shields.io/github/actions/workflow/status/Nazar963/42_push_swap/.github/workflows/build.yml?branch=main)](https://github.com/Nazar963/42_push_swap/.github/workflows/build.yml)

A stack sorting algorithm project implementing radix sort with two stacks (A and B), featuring efficient number sorting with constrained operations.

![Push_Swap Operations](https://raw.githubusercontent.com/Nazar963/push_swap/main/images/demo.gif)

## Table of Contents 📖
- [Project Overview](#project-overview)
- [Radix Sort Implementation](#radix-sort-implementation)
- [Performance Analysis](#performance-analysis)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Testing](#testing)
- [Limitations](#limitations)
- [Resources](#resources)
- [Acknowledgments](#acknowledgments)
- [License](#license)

## Project Overview

Push_Swap is a 42 School project that challenges students to sort random integers using two stacks (A and B) with a limited set of operations. The goal is to develop an algorithm that sorts numbers with the **minimum number of operations** possible.

**Key Constraints**:
- Only 11 allowed operations
- Stack A initially contains random integers
- Stack B is initially empty
- Operations include push, swap, and rotate commands
- Goal: Sort stack A in ascending order

**Operations Set**:
```c
sa : swap a        - swap first 2 elements at top of stack a
sb : swap b        - swap first 2 elements at top of stack b
ss : sa and sb at the same time
pa : push a        - move top element from b to a
pb : push b        - move top element from a to b
ra : rotate a      - shift all elements of stack a up by 1
rb : rotate b      - shift all elements of stack b up by 1
rr : ra and rb at the same time
rra: reverse rotate a - shift all elements of stack a down by 1
rrb: reverse rotate b - shift all elements of stack b down by 1
rrr: rra and rrb at the same time
```

## Radix Sort Implementation

### Algorithm Overview
Radix sort is a non-comparative sorting algorithm that processes numbers digit by digit. This implementation uses binary representation (bits) to sort numbers:

![push_swap Example](https://raw.githubusercontent.com/Nazar963/42_push_swap/main/images/sample_image.png)

### Key Steps
1. **Normalization**:
   - Convert negative numbers to positive using offset
   - Assign each number a unique index (0 to N-1)

2. **Bitwise Processing**:
   ```c
    size = ft_lstsize(*stack_a) + 1;
    while (--size)
    {
        if (*(int *)((*stack_a)->content) & (1 << i))
            ft_rotate_a(stack_a, 0);
        else
            ft_push_b(stack_a, stack_b);
    }
   ```

3. **Complexity**:
   - Time Complexity: O(n * k) where k is number of bits
   - Space Complexity: O(n)

## Performance Analysis

### Operation Count Results
| Stack Size | Target (125%) | Radix Implementation | Status |
|------------|---------------|----------------------|--------|
| 100        | ≤ 700         | ~1100                | ⚠️ Within 150% |
| 500        | ≤ 5500        | ~8000                | ⚠️ Within 145% |
| 5          | ≤ 12          | ≤ 12                 | ✅ Optimal |
| 3          | ≤ 3           | ≤ 3                  | ✅ Optimal |

### Strengths
- **Consistent Performance**: Always completes in O(n log n) operations
- **Simplicity**: Straightforward implementation
- **Deterministic**: Same input always produces same operation count
- **Stable Sort**: Preserves order of equal elements

### Limitations
- **Suboptimal for Small Sets**: Comparative algorithms often better for n < 50
- **No Custom Optimization**: Doesn't adapt to partially sorted inputs
- **Higher Operation Count**: Compared to hybrid approaches like quick-sort + insertion

## Features

### Core Functionality
- **Radix Sort Algorithm**: Bitwise number processing
- **Input Validation**: Handles duplicates, non-integers, and overflows
- **Error Handling**: Clean error messages for invalid input
- **Operation Counter**: Displays total moves used

## Installation

### Requirements
- GNU Make
- GCC

### Compilation
```bash
git clone https://github.com/Nazar963/42_push_swap.git
cd 42_push_swap

# Compile main program
make
```

## Usage

### Basic Sorting
```bash
# Generate random numbers and sort
ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")
./push_swap $ARG | wc -l

# With checker validation
ARG="4 2 1 3 5"
./push_swap $ARG | ./checker $ARG
```
## Testing

### Performance Test
```bash
# Test 100 numbers (100 runs)
for i in {1..100}; do
    ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")
    ./push_swap $ARG | wc -l
done | sort -n

# Expected result distribution:
# Min: 900-1000
# Median: 1050-1150
# Max: 1200-1300
```

### Memory Check
```bash
valgrind --leak-check=full ./push_swap 4 2 1 3 5
```

### Recommended Testers
- [push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer)
- [push_swap Tester](https://github.com/lmalki-h/push_swap_tester)
- [42 Push Swap Tester](https://github.com/LeoFu9487/push_swap_tester)

## Limitations

While radix sort is a valid solution:
1. **Not Optimal for Small Sets**: 
   - For 5 numbers: Radix uses ~12 operations vs optimal 8-12
   - For 100 numbers: 1100 operations vs 700 target

2. **Fails 100% Requirements**:
   - Requires ≤ 700 ops for 100 numbers (125% of target)
   - Radix typically achieves 1100 ops (≈150% of target)

3. **Alternative Approaches**:
   - Hybrid quick-sort + insertion sort
   - Chunk-based sorting algorithms
   - Adaptive algorithms for partially sorted stacks

## Resources

1. [Radix Sort Visualization](https://www.cs.usfca.edu/~galles/visualization/RadixSort.html)
2. [Push_Swap Algorithm Guide](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
3. [Non-Comparative Sorting](https://www.geeksforgeeks.org/radix-sort/)

## Acknowledgments

- **42 School** for the challenging project
- **Donald Knuth** for The Art of Computer Programming
- **Peer reviewers** at 42 Network
- **Open source community** for testing tools

## 🤝 Contributing
Feel free to submit issues or pull requests if you have suggestions for improving the test suite or adding more test cases.

## License
This project is licensed under the MIT License - see [LICENSE](LICENSE) for details.

## 📧 Contact
For questions or feedback, please open an issue in the repository.

## ⭐ Star this repository if you found it helpful!
[![GitHub stars](https://img.shields.io/github/stars/Nazar963/42_push_swap?style=social)](https://github.com/Nazar963/42_push_swap/stargazers)

---

🧮 *"Elegant in theory, challenging in practice"*  
[![42 School](https://img.shields.io/badge/42-profile-blue)](https://profile-v3.intra.42.fr/users/naal-jen)
[![GitHub Profile](https://img.shields.io/badge/GitHub-Nazar963-lightgrey)](https://github.com/Nazar963)
[![GitHub Follow](https://img.shields.io/github/followers/Nazar963?style=social)](https://github.com/Nazar963)

---

Good luck with your push_swap project at 42! 🚀