# Brute force
class Solution:
	def count(self, nums: List[int]):
		"""
		Time O(N^2)
		"""
		n = len(nums)
		cnt = 0

		for i in range(n):
			for j in range(i + 1, n):
				if nums[i] > nums[j]:
					cnt += 1

		return cnt


# Recursion
class Solution:
	def count_cross_inversion(self, nums1, nums2):
		cnt = 0
		for n1 in nums1:
			for n2 in nums2:
				if n1 > n2:
					cnt += 1

		return cnt


	def count(self, nums: List[int]):
		"""
		T(n) = 2 * T(n / 2) + n^2
		Using master's theorem, time is O(N^2)
		"""
		if len(nums) <= 1:
            return 0

		mid = len(nums) // 2
		x = self.count(nums[:mid])
		y = self.count(nums[mid:])

		z = self.count_cross_inversion(nums[:mid], nums[mid:])

		return x + y + z


# Sort
class Solution:
	def count_cross_inversion(self, nums1, nums2):
		cnt = 0
		i = j = 0

		while i < len(nums1) and j < len(nums2):
			if nums1[i] > nums2[j]:
				cnt += len(nums1) - i
				j += 1
			else:
				i += 1

		return cnt

	def count(self, nums):
		"""
		T(n) = 2T(n/2) + n log n + n
             = 2T(n/2) + O(n log n)
        By recursion tree, time is O(n log² n)
		"""
		if len(nums) <= 1:
			return 0

		mid = len(nums) // 2
		x = self.count(nums[:mid])
		y = self.count(nums[mid:])

		left = sorted(nums[:mid])
		right = sorted(nums[mid:])

		z = self.count_cross_inversion(left, right)

		return x + y + z














