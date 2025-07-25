class RecursionPatterns:

	# 1. Print all subsequences
	def print_all(self, ind, arr, nums):
		if ind == len(nums):
			print(arr)

		arr.append(nums[ind])
		self.print_all(ind + 1, arr, nums)

		arr.pop()
		self.print_all(ind + 1, arr, nums)


	# 2. Print all subsequences whose sum is k
	def print_sum_k(self, ind, ds, sub_sum, nums, k):
		if ind == len(nums):
			if sub_sum == k:
				print(ds)
			return

		ds.append(nums[ind])
		sub_sum += nums[ind]
		self.print_sum_k(ind + 1, ds, sub_sum, nums, k)

		ds.pop()
		sub_sum -= nums[ind]
		self.print_sum_k(ind + 1, ds, sub_sum, nums, k)


	# 3. Print ANY subsequences whose sum is k
	# print one res => return T/F to avoid further recursion calls
	def print_any_sum_k(self, ind, ds, sub_sum, nums, k):
		if ind == len(nums):
			if sub_sum == k:
				print(ds)
				return True
			return False

		ds.append(nums[ind])
		sub_sum += nums[ind]
		if self.print_sum_k(ind + 1, ds, sub_sum, nums, k):
			return True

		ds.pop()
		sub_sum -= nums[ind]
		if self.print_sum_k(ind + 1, ds, sub_sum, nums, k):
			return True

		return False


	# 4. Count subsequences whose sum is k
	# COUNT => return 1, return 0, add
	def print_any_sum_k(self, ind, sub_sum, nums, k):
		if ind == len(nums):
			if sub_sum == k:
				return 1
			return 0

		sub_sum += nums[ind]
		take = self.print_sum_k(ind + 1, ds, sub_sum, nums, k)

		sub_sum -= nums[ind]
		not_take = self.print_sum_k(ind + 1, ds, sub_sum, nums, k)

		return take + not_take


if __name__ == "__main__":
	nums = [1, 2, 1]