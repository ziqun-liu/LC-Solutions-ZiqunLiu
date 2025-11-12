def getMinimumHeight(tree_nodes, tree_from, tree_to, max_operations):
    subheight = [0] * (tree_nodes + 1)  # number of node n's children 
    adj = [[] for _ in range(tree_nodes + 1)]
    for i in range(tree_nodes - 1):
        adj[tree_from[i]].append(tree_to[i])

    def sub_height(treenode):
        for nxt in adj[treenode]:
            subheight[treenode] = max(subheight[treenode], sub_height(nxt))
            
        return subheight[treenode] + 1
        
    sub_height(1)
    
    def attempt(treenode, H, curr):
        res = 0
        if curr < H:
            for nxt in adj[treenode]:
                res += attempt(nxt, H, curr + 1)
        else:
            for nxt in adj[treenode]:
                res += 1 + attempt(nxt, H, 1)
        return res

    left = 1
    right = subheight[1]
    while left < right:
        mid = (left + right) // 2
        res = attempt(1, mid, 1)
        if res > max_operations:
            left = mid + 1
        else:
            right = mid

    return left