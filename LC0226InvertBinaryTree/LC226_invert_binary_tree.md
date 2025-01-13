# Invert Binary Tree - Potential Interview Questions and Answers

### Question 1: 
**What are the different ways to invert a binary tree? Which is the most efficient?**

#### Answer:
There are three common ways to invert a binary tree:
1. **Recursive Depth-First Search (DFS):**
   - Use recursion to traverse the tree and invert the left and right subtrees.
   - Time Complexity: O(n)
   - Space Complexity: O(h), where h is the height of the tree (O(log n) for balanced trees, O(n) for skewed trees).

2. **Iterative Depth-First Search (DFS):**
   - Use a stack to simulate the recursive call stack for a DFS traversal.
   - Time Complexity: O(n)
   - Space Complexity: O(h).

3. **Iterative Breadth-First Search (BFS):**
   - Use a queue to traverse the tree level by level, swapping children for each node.
   - Time Complexity: O(n)
   - Space Complexity: O(w), where w is the maximum width of the tree.

**The most efficient approach depends on the tree structure and constraints:**
- Recursive DFS is simpler to implement and generally preferred unless the tree depth is large (risking stack overflow).
- Iterative BFS avoids stack overflow and is more memory-efficient for shallow but wide trees.

---

### Question 2:
**What are the time and space complexities of inverting a binary tree using BFS?**

#### Answer:
- **Time Complexity:** O(n)
  - Every node is visited once, and swapping its children takes O(1).
  - Traversing all n nodes results in O(n) time complexity.

- **Space Complexity:** O(w), where w is the maximum width of the tree.
  - The queue can hold up to w nodes at the widest level of the tree.
  - For a complete binary tree, the maximum width is approximately n/2, leading to O(n) space complexity in the worst case.
  - For a skewed tree, the space complexity is O(1).

---

### Question 3:
**What are the trade-offs between the recursive and iterative approaches to invert a binary tree?**

#### Answer:
| **Aspect**                 | **Recursive Approach**            | **Iterative Approach**               |
|----------------------------|------------------------------------|--------------------------------------|
| **Simplicity**             | Easier to implement, shorter code | Slightly more complex                |
| **Space Complexity**       | O(h) (call stack)                 | O(w) (queue or stack)                |
| **Risk of Stack Overflow** | Yes, for deep trees               | No                                   |
| **Preferred Use Case**     | Shallow or balanced trees          | Deep or wide trees                   |

The recursive approach is preferred when the tree is balanced and the depth is small, while the iterative approach is safer for large or highly unbalanced trees.

---

### Question 4:
**Explain how swapping children at each node affects the traversal order in BFS and DFS.**

#### Answer:
- **In BFS:**
  - Nodes are processed level by level. Swapping the children of a node does not affect the order of traversal, as the queue ensures that all nodes at the current level are processed before moving to the next level.

- **In DFS:**
  - The swapping of children directly affects the order of traversal because it changes the sequence in which the left and right subtrees are visited. For example:
    - In a pre-order DFS, swapping children means the original right subtree is visited before the original left subtree.

Swapping only changes the structure of the tree, not the traversal mechanism.

---

### Question 5:
**What edge cases should you consider when solving this problem?**

#### Answer:
1. **Empty Tree:** 
   - Input: `root == nullptr`
   - Output: `nullptr` (return immediately).

2. **Single Node Tree:**
   - Input: A tree with only one node.
   - Output: The same tree, as there are no children to swap.

3. **Skewed Tree (Linked List Structure):**
   - Input: A tree where all nodes have only one child (either left or right).
   - Output: The tree structure remains skewed but in the opposite direction.

4. **Balanced Tree:**
   - Input: A complete or perfect binary tree.
   - Output: A complete or perfect binary tree with children inverted at all levels.

5. **Large Tree:**
   - Ensure your solution handles deep trees without stack overflow (e.g., iterative BFS may be preferred).

