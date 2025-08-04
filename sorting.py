# Insertion Sort
# TC Avg case O(N^2) worst case O(N^2) best case O(N)
# SC O(1)
class Solution:
	def insertion_sort(self, nums):
		for i in range(len(nums)):
			j = i
			while j > 0 and nums[j - 1] > nums[j]:
				nums[j - 1], nums[j] = nums[j], nums[j - 1]
				j -= 1

		return nums


# Selection Sort
# TC Avg case O(N^2) worst case O(N^2) best case O(N^2)
# SC O(1)
class Solution:
	def selection_sort(self, nums):
		for i in range(len(nums) - 1):
			min_ind = i
			for j in range(i, range(nums)):
				if nums[j] < nums[min_ind]:
					min_ind = j
			nums[min_ind], nums[i] = nums[i], nums[min_ind]

		return nums


# Bubble Sort
# TC Avg case O(N^2) worst case O(N^2) best case O(N)
# SC O(1)
class Solution:
	def bubble_sort(self, nums):
		for i in range(len(nums) - 1, -1, -1):
			swapped = False
			for j in range(i):
				if nums[j] > nums[j + 1]:
					nums[j], nums[j + 1] = nums[j + 1], nums[j]
					swapped = True
			if not swapped:
				break

		return nums


# Merge Sort
# TC O(NlogN) SC O(N)
class Solution:
    def divide(self, low, high, nums):
        if low == high:
            return

        mid = (high + low) // 2
        self.divide(low, mid, nums)
        self.divide(mid + 1, high, nums)
        self.merge(low, mid, high, nums)

    def merge(self, low, mid, high, nums):
        temp = []
        l, r = low, mid + 1
        
        while l <= mid and r <= high:
            if nums[l] <= nums[r]:
                temp.append(nums[l])
                l += 1
            else:
                temp.append(nums[r])
                r += 1

        while l <= mid:
            temp.append(nums[l])
            l += 1
        while r <= high:
            temp.append(nums[r])
            r += 1

        for i in range(low, high + 1):
            nums[i] = temp[i - low]

    def mergeSort(self, nums):
        self.divide(0, len(nums) - 1, nums)
