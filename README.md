# Push_swap

Sorting algorithm challenge using two stacks (`a` and `b`) and a restricted instruction set.
42 Roma Luiss project.

---

## 🧩 Project goal

Create a program that sorts a list of integers using only specific stack operations, printing the sequence of moves that lead to a sorted stack.

---

## 🧠 Algorithm Overview

### Input Handling & Indexing

* Parses input numbers, checks for duplicates and integer overflow.
* If the list is already sorted, exits immediately.
* Builds stack `a` as a linked list of nodes containing both `value` and a normalized `index`.
* The `index` represents the element's rank in the sorted array (from 0 to n-1).

### Sorting Strategy

Two distinct approaches are used depending on input size:

#### Small inputs (≤5 elements)

* **2 elements:** one `sa` if needed.
* **3 elements:** minimal set of swaps and rotations based on value order.
* **4/5 elements:** repeatedly push smallest elements to stack `b`, sort remaining 3, then push back with `pa`.

#### Large inputs (>5 elements)

Implements a **binary radix sort** based on the indexed values:

1. Find the maximum index and determine the number of bits required.
2. For each bit position `i` (starting from LSB):

   * Push all elements with bit `i` == 0 to stack `b`.
   * Rotate others in `a`.
3. Push all elements from `b` back to `a`.
4. Repeat for the next bit until stack `a` is sorted.

This achieves roughly `O(n * log n)` time complexity using only allowed moves.

---

## ⚙️ Allowed operations

`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`

---

## 🧩 Radix Sort Visualization

Below is a simplified representation of one bit-pass during the radix sorting process:

```
Initial stack A: [3, 0, 2, 1]
Bit position: 0

Check LSB of each index:
3 (11) → bit0=1 → rotate A
0 (00) → bit0=0 → push to B
2 (10) → bit0=0 → push to B
1 (01) → bit0=1 → rotate A

Stacks after pass:
A: [3, 1]
B: [2, 0]

Then push everything back from B → A (pa pa)
Next bit → repeat.
```

Each iteration refines order by binary significance until stack `a` is fully sorted.

---

## 📦 Tech stack

* C (linked lists, bitwise operations)
* Custom `libft` (atoi, split, utils)
* Makefile, manual memory management

---

## ✅ Status

Completed and validated at **84%**.
