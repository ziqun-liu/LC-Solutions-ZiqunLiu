from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def quick_select(l, r):
            ptr = l
            for i in range(l, r):
                if nums[i] <= nums[r]:
                    nums[ptr], nums[i] = nums[i], nums[ptr]
                    ptr += 1
            nums[ptr], nums[r] = nums[r], nums[ptr]

            if ptr < len(nums) - k:
                return quick_select(ptr + 1, r)
            elif ptr > len(nums) - k:
                return quick_select(l, ptr - 1)
            else:
                return nums[ptr]

        return quick_select(0, len(nums) - 1)
