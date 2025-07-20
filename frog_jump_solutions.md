
# 🐸 Frog Jump Problem

## Problem Description

A frog wants to climb a staircase with `n` steps.  
Given an integer array `heights`, where `heights[i]` contains the height of the `i`th step.  
To jump from step `i` to step `j`, the frog uses energy `abs(heights[i] - heights[j])`.  
The frog can jump **1 or 2 steps ahead** (if such a step exists).  

**Goal:**  
Return the **minimum amount of energy** required to go from step `0` to step `n-1`.

一只青蛙想要爬上一个有 n 个台阶的楼梯。给定一个整数数组 heights，其中 heights[i] 表示第 i 个台阶的高度。
要从第 i 个台阶跳到第 j 个台阶，青蛙需要消耗 abs(heights[i] - heights[j]) 的能量，其中 abs() 表示绝对值差。
青蛙可以从任意台阶向前跳跃一步或两步（前提是目标台阶存在）。
返回青蛙从第 0 个台阶到达第 (n-1) 个台阶所需的最少能量。

---

## 🧪 Examples

```
Input:  heights = [2, 1, 3, 5, 4]
Output: 2
Explanation: 0 -> 2 (|2-3| = 1), 2 -> 4 (|3-4| = 1) → Total = 2

Input:  heights = [7, 5, 1, 2, 6]
Output: 9
Explanation: 0 -> 1 (|7-5| = 2), 1 -> 3 (|5-2| = 3), 3 -> 4 (|2-6| = 4) → Total = 9
```

---

## 🔁 1. Recursion (Brute Force)

```python
class Solution1:
    def frogJump(self, heights):
        return self.f(len(heights) - 1, heights)

    def f(self, ind, heights):
        if ind == 0:
            return 0

        jump_one = self.f(ind - 1, heights) + abs(heights[ind] - heights[ind - 1])
        jump_two = float('inf')
        if ind > 1:
            jump_two = self.f(ind - 2, heights) + abs(heights[ind] - heights[ind - 2])

        return min(jump_one, jump_two)
```

- ⏱ Time: `O(2^n)` - 2 sub-problems at every position
- 💾 Space: `O(n)` (call stack)

---

## 🧠 2. Memoization (Top-Down DP)

```python
class Solution2:
    def frogJump(self, heights):
        dp = [-1] * len(heights)
        return self.f(len(heights) - 1, dp, heights)

    def f(self, ind, dp, heights):
        if ind == 0:
            return 0

        if dp[ind] != -1:
            return dp[ind]

        jump_one = self.f(ind - 1, dp, heights) + abs(heights[ind] - heights[ind - 1])
        jump_two = float('inf')
        if ind > 1:
            jump_two = self.f(ind - 2, dp, heights) + abs(heights[ind] - heights[ind - 2])

        dp[ind] = min(jump_one, jump_two)
        return dp[ind]
```

- ⏱ Time: `O(n)` - n sub-problems
- 💾 Space: `O(n)` (DP array + call stack)

---

## 📊 3. Tabulation (Bottom-Up DP)

```python
class Solution3:
    def frogJump(self, heights):
        n = len(heights)
        dp = [0] * n

        for i in range(1, n):
            jump_one = dp[i - 1] + abs(heights[i] - heights[i - 1])
            jump_two = dp[i - 2] + abs(heights[i] - heights[i - 2]) if i > 1 else float('inf')
            dp[i] = min(jump_one, jump_two)

        return dp[-1]
```

- ⏱ Time: `O(n)` - for loop
- 💾 Space: `O(n)` - dp array n

---

## 🧮 4. Space Optimized Tabulation (O(1) Space)

```python
class Solution4:
    def frogJump(self, heights):
        n = len(heights)
        if n <= 1:
            return 0

        prev2 = 0
        prev = abs(heights[1] - heights[0])

        for i in range(2, n):
            jump_one = prev + abs(heights[i] - heights[i - 1])
            jump_two = prev2 + abs(heights[i] - heights[i - 2])
            curr = min(jump_one, jump_two)

            prev2 = prev
            prev = curr

        return prev
```

- ⏱ Time: `O(n)`
- 💾 Space: `O(1)` - no array
