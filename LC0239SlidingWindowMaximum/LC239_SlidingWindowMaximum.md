# Sliding Window Maximum - Interview Questions

## 1. What is the purpose of using a deque (double-ended queue) in this problem?
**Answer:**
A deque is used to efficiently store indices of elements within the current sliding window while maintaining the **monotonic decreasing order** of their values. This ensures:
- The maximum value of the current window is always at the front of the deque.
- Indices that are no longer within the bounds of the sliding window or cannot be part of the maximum are removed from the deque.

---

## 2. What is the time complexity of this solution, and why?
**Answer:**
The time complexity is \(O(n)\), where \(n\) is the size of the input array `nums`. Each element is:
- Added to the deque at most once.
- Removed from the deque at most once.

Thus, each operation on the deque (push or pop) happens \(O(1)\) times per element, leading to an overall linear time complexity.

---

## 3. How would you modify the algorithm if the input array contains negative numbers?
**Answer:**
The algorithm already works for negative numbers without modification. It relies on comparisons between array elements, and the presence of negative values does not affect the comparison logic in maintaining the deque or computing the maximum for the sliding window.

---

## 4. Can you describe edge cases to test this algorithm?
**Answer:**
- **Empty array:** `nums = []` and `k = 0`. The output should be an empty vector.
- **Window size equals array size:** `nums = [1, 3, 5, 7]` and `k = 4`. The output should be `[7]`.
- **Window size = 1:** `nums = [4, 3, 2, 1]` and `k = 1`. The output should be the array itself, `[4, 3, 2, 1]`.
- **All elements are the same:** `nums = [2, 2, 2, 2]` and `k = 2`. The output should be `[2, 2, 2]`.
- **Large `k`:** `nums = [1, 2, 3]` and `k = 5`. This should raise an error or return an empty result since the window size is larger than the array size.

---

## 5. How would you handle this problem if the sliding window size `k` can vary during runtime?
**Answer:**
To handle varying window sizes:
1. Use a loop to reinitialize the deque each time the window size `k` changes.
2. Ensure the deque logic (adding/removing indices and maintaining monotonic order) is adapted dynamically for each new value of `k`.
3. This may slightly increase the runtime due to repeated reinitializations but retains the overall \(O(n)\) complexity for each fixed window size.

---
