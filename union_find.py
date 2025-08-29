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



def main():
    sol = DisjointSet(7)
    sol.union_by_rank(1, 2)
    sol.union_by_rank(2, 3)
    sol.union_by_rank(4, 5)
    sol.union_by_rank(6, 7)
    sol.union_by_rank(5, 6)
    print("Same") if sol.find_parent(3) == sol.find_parent(7) else print("Different")

    sol.union_by_rank(3, 7)
    print("Same") if sol.find_parent(3) == sol.find_parent(7) else print("Different")



if __name__ == "__main__":
    main()