class Solution:
	def permute(self, nums):
		res = []
		self.backtrack([], nums, res, set())
		return res

	def backtrack(self, ds, nums, res, used):
		if len(ds) == len(nums):
			res.append(ds.copy())
			return

		for i in range(len(nums)):
			if i not in used:
				ds.append(nums[i])
				used.add(i)
				self.backtrack(ds, nums, res, used)
				ds.pop()
				used.remove(i)

class Solution:
	def permute(self, nums):
		res = []
		self.backtrack(0, nums, res)
		return res

	def backtrack(self, ind, nums, res):
		if ind == len(nums):
			res.append(nums.copy())
			return

		for i in range(len(nums)):
			# 交换当前位置和选中位置的元素
			nums[ind], nums[j] = nums[j], nums[ind]
			# 递归处理下一个位置
			self.backtrack(i + 1, nums, res)
			# 回溯：交换回来
			nums[ind], nums[j] = nums[j], nums[ind]