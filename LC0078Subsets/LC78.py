class Solution:
    # Time: O(N * 2^N), Space: O(N)
    def backtrack(self, i: int, res: list[int], subset: list[int], nums: list[int]):
        if i == len(nums):
            res.append(subset.copy())
            return

        # Include nums[i]
        subset.append(nums[i])
        self.backtrack(i + 1, res, subset, nums)

        # Exclude nums[i]
        subset.pop()
        self.backtrack(i + 1, res, subset, nums)



def main():
    sol = Solution()
    nums = [1, 2, 3]
    res = []
    sol.backtrack(0, res, [], nums)

    print("All subsets:")
    for subset in res:
        print("{", " ".join(map(str, subset)), "}")

if __name__ == "__main__":
    main()
