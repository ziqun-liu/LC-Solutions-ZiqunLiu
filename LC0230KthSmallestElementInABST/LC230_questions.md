### Why `curr || !stack.empty()`?
1. curr checks if there is a current node to process:
- When curr != nullptr, it means there are still unvisited nodes in the current branch of the tree.
- During the traversal, curr is used to traverse down the left subtree. When it reaches the leftmost node, `curr` becomes `nullptr`.

2. `!stack.empty()` checks if there are nodes in the stack:
- The stack is used to store the path of nodes (to simulate recursion). When the left subtree traversal is complete, nodes are popped from the stack to backtrack and process the parent node or move to the right subtree.
- If the stack is not empty, it means there are still nodes that haven't been fully processed.