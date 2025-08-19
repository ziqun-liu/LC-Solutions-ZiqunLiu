#### 构建图

- 对于`word1`中的第`ptr`个字母`l1`，让它指向`word2`中第`ptr`个字母`l2`
- 让`l1`作为`l2`的依赖
- 用拓扑排序，可以得到按照依赖先后的顺序
- 这道题的概念是：利用`words`构建依赖（图），利用依赖排序，核对`words`的顺序是否与依赖的顺序一致

#### 两种情况返回 `""`

- `word1` 的前几个字母是`word2`，即 `len(word1) > len(word2) and word1.startswith(word2)`
- 构建的图中有循环，即有字母

```python
class Solution:
    def alienOrder(self, words: List[str]) -> str:
        """
        Return "" if:
        1. longer string appears before shorter string
        2. cycle detected
        """
        # Count all unique characters that appear in the words
        chars_in_words = set()
        for word in words:
            for char in word:
                chars_in_words.add(char)

        V = len(chars_in_words)  # The number of vertices in the graph

        # 建立字符和索引的双向映射
        char_to_idx = {char: i for i, char in enumerate(chars_in_words)}
        idx_to_char = {i: char for char, i in char_to_idx.items()}

        # Construct graph adj
        adj = [[] for _ in range(V)]

        for i in range(len(words) - 1):
            word1, word2 = words[i], words[i + 1]

            if len(word1) > len(word2) and word1.startswith(word2):
                return ""

            size = min(len(word1), len(word2))
            for ptr in range(size):
                if word1[ptr] != word2[ptr]:
                    adj[char_to_idx[word1[ptr]]].append(char_to_idx[word2[ptr]])
                    break

        # Topological sort
        res_indices = []
        if not self.topo_sort(V, adj, res_indices):
            return ""

        return ''.join(idx_to_char[idx] for idx in res_indices)

    def topo_sort(self, V, adj, res):
        dq = deque()
        in_degree = [0 for _ in range(V)]

        for node in range(V):
            for neighbor in adj[node]:
                in_degree[neighbor] += 1

        for i in range(V):
            if in_degree[i] == 0:
                dq.append(i)

        while dq:
            node = dq.popleft()
            res.append(node)
            for neighbor in adj[node]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    dq.append(neighbor)

        return len(res) == V
```

