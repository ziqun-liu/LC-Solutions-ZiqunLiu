class DisjointSet:
    def __init__(self, n: int) -> None:
        self.ranks = [0] * (n + 1)
        self.parents = list(range(n + 1))
        self.sizes = [1] * (n + 1)

    def find_parent(self, node: int) -> int:
        if node == self.parents[node]:
            return node
        self.parents[node] = self.find_parent(self.parents[node])
        return self.parents[node]

    def union_by_rank(self, u: int, v: int) -> None:
        ancestor_u = self.find_parent(u)
        ancestor_v = self.find_parent(v)

        if ancestor_u == ancestor_v:  # Cycle / in same component
            return

        if self.ranks[ancestor_u] < self.ranks[ancestor_v]:
            self.parents[ancestor_u] = ancestor_v  # Attach u to v
        elif self.ranks[ancestor_v] < self.ranks[ancestor_u]:
            self.parents[ancestor_v] = ancestor_u  # Attach v to u
        else:
            self.parents[ancestor_v] = ancestor_u
            self.ranks[ancestor_u] += 1  # Only increment rank if the ranks of u and the ranks of v are equal

    def union_by_size(self, u: int, v: int) -> None:
        ancestor_u = self.find_parent(u)
        ancestor_v = self.find_parent(v)

        if ancestor_u == ancestor_v:  # Cycle / in same component
            return

        if self.sizes[ancestor_u] <= self.sizes[ancestor_v]:
            self.parents[ancestor_u] = ancestor_v
            self.sizes[ancestor_v] += self.sizes[ancestor_u]
        else:
            self.parents[ancestor_v] = ancestor_u
            self.sizes[ancestor_u] += self.sizes[ancestor_v]

class Solution:
    @staticmethod
    def kruskal_mst(n: int, edges: list) -> tuple:
        """
        使用Kruskal算法寻找最小生成树

        Args:
            n: 节点数量 (节点编号从1到n)
            edges: 边列表，每条边格式为 [u, v, weight]

        Returns:
            tuple: (最小生成树的边列表, 最小权重和)
        """
        # 按权重对边进行排序
        edges.sort(key=lambda x: x[2])

        # 初始化并查集
        dsu = DisjointSet(n)

        mst_edges = []  # 最小生成树的边
        total_weight = 0  # 最小生成树的总权重

        # 遍历排序后的边
        for u, v, weight in edges:
            # 如果这条边连接的两个节点不在同一连通分量中，则加入MST
            if dsu.find_parent(u) != dsu.find_parent(v):
                dsu.union_by_rank(u, v)  # 合并两个连通分量
                mst_edges.append([u, v, weight])
                total_weight += weight

        return mst_edges, total_weight

    @staticmethod
    def print_mst(mst_edges: list, total_weight: int) -> None:
        """打印最小生成树结果"""
        print("最小生成树的边:")
        for u, v, weight in mst_edges:
            print(f"  {u} -- {v} : {weight}")
        print(f"最小生成树总权重: {total_weight}")


def main():
    dsu = DisjointSet(7)
    dsu.union_by_rank(1, 2)
    dsu.union_by_rank(2, 3)
    dsu.union_by_rank(4, 5)
    dsu.union_by_rank(6, 7)
    dsu.union_by_rank(5, 6)
    print("Same") if dsu.find_parent(3) == dsu.find_parent(7) else print("Different")

    dsu.union_by_rank(3, 7)
    print("Same") if dsu.find_parent(3) == dsu.find_parent(7) else print("Different")

    # Kruskal算法示例
    print("\n=== Kruskal算法示例1 ===")
    n1 = 4
    edges1 = [
        [1, 2, 10],
        [1, 3, 6],
        [1, 4, 5],
        [2, 4, 15],
        [3, 4, 4]
    ]

    mst_edges1, total_weight1 = Solution.kruskal_mst(n1, edges1)
    Solution.print_mst(mst_edges1, total_weight1)


    print("\n=== Kruskal算法示例2 ===")
    n2 = 5
    edges2 = [
        [1, 2, 2],
        [1, 3, 3],
        [1, 4, 3],
        [2, 3, 4],
        [2, 5, 3],
        [3, 4, 5],
        [3, 5, 1],
        [4, 5, 1]
    ]

    mst_edges2, total_weight2 = Solution.kruskal_mst(n2, edges2)
    Solution.print_mst(mst_edges2, total_weight2)

if __name__ == "__main__":
    main()