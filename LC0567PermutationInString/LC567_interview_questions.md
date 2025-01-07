# Interview Questions Based on `checkInclusion` Code

## 1. Sliding Window Technique
**Question:**
Explain the sliding window technique used in the `checkInclusion` function. How does it ensure we only process the necessary characters in `s2`?
	-  The sliding window technique maintains a fixed-length window over s2 equal to the length of s1. 
	   Instead of recalculating the character frequencies for every substring, it updates the frequency count for: 
	   the character added to the window (s2[r]) and he character removed from the window (s2[l]).
       This ensures that only two characters are processed at each step, reducing redundant computations 
**Follow-up:**
- What are the advantages of using a sliding window over checking all substrings explicitly?
- Can this technique be generalized for other problems?

---

## 2. Character Frequency Optimization
**Question:**
Why does the solution use two arrays (`s1Count` and `s2Count`) of size 26? 
How does this help optimize the solution compared to using a map or dictionary?
	- Since there are only 26 lower-case letters, each letter is mapped to index 0 to 25, thus giving constant look-up time

**Follow-up:**
- How would you adapt the solution if the input strings could contain Unicode characters?
- Answer: replace array with hashmap or dictionary. could lead to more space used and more loop-up time
- What would be the impact of using an unordered map instead of fixed-size arrays?
- Answer: Space: The unordered map dynamically grows based on the unique characters, which could save space for sparse inputs but increase memory usage for dense ones.
Time: Hash map operations have average O(1) time but can degrade to O(n) in the worst case, making them less predictable compared to constant-time array access.
---

## 3. Matches Counter
**Question:**
Describe the purpose of the `matches` variable. Under what conditions is it incremented or decremented?

**Follow-up:**
- How does `matches` improve the efficiency of the algorithm?
- Could this algorithm work without using the `matches` variable? If yes, what would be the trade-offs?

---

## 4. Edge Cases and Complexity
**Question:**
What edge cases does the `checkInclusion` function handle? How does the edge case check (`if (s1.length() > s2.length())`) ensure correctness?

**Follow-up:**
- What happens if `s1` or `s2` is empty? How would you handle this scenario in a production environment?
- Analyze the time and space complexity of this function.

---

## 5. Extensions and Variations
**Question:**
How would you modify the function to return all starting indices of permutations of `s1` in `s2` instead of just a boolean?

**Follow-up:**
- How would the complexity change in this variation?
- Could you adapt this solution for checking permutations across multiple input strings (e.g., `s1` against an array of strings)?
