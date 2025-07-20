
In a perfect binary tree of height $h$:

- At level 0 (root): $2^0 = 1$ node
- At level 1: $2^1 = 2$ nodes
- At level 2: $2^2 = 4$ nodes
- At level $h$: $2^h$ nodes

The total number of nodes is the sum:

$$n = 2^0 + 2^1 + 2^2 + \ldots + 2^h$$

This is a geometric series with first term $a = 1$ and common ratio $r = 2$.

For a geometric series with these properties, the sum formula is:

$$\text{Sum} = \frac{a(1-r^{(h+1)})}{1-r}$$

Substituting our values:

$$n = \frac{1(1-2^{(h+1)})}{1-2}$$

$$n = \frac{1-2^{(h+1)}}{-1}$$

$$n = 2^{(h+1)} - 1$$

To find the number of nodes at the last level ($2^h$) in terms of $n$:

$$n = 2^{(h+1)} - 1$$

$$n + 1 = 2^{(h+1)}$$

$$n + 1 = 2 \cdot 2^h$$

$$2^h = \frac{n+1}{2}$$

Therefore, the number of nodes at the last level is exactly $\frac{n+1}{2}$.