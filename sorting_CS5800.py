class MergeSort:
    def sort(self, nums: list, n: int):
        if n == 0 or n == 1:
            return nums
            
        mid = n // 2
        sorted_left = self.sort(nums[:mid], mid)
        sorted_right = self.sort(nums[mid:], n - mid)
        
        return self.merge(sorted_left, sorted_right)
    
    def merge(self, nums1: list, nums2: list):
        res = [0] * (len(nums1) + len(nums2))
        
        ptr = 0
        p1 = 0
        p2 = 0
        
        while p1 < len(nums1) and p2 < len(nums2):
            if nums1[p1] <= nums2[p2]:
                res[ptr] = nums1[p1]
                p1 += 1
            else:
                res[ptr] = nums2[p2]
                p2 += 1
            ptr += 1
        
        # 处理剩余元素
        while p1 < len(nums1):
            res[ptr] = nums1[p1]
            p1 += 1
            ptr += 1
            
        while p2 < len(nums2):
            res[ptr] = nums2[p2]
            p2 += 1
            ptr += 1
            
        return res

    def merge_sort(self, nums: int):
    	self.sort(nums, len(nums))
    	return nums


class SelectionSortRecursive
    
    def selection(self, nums: list, start: int, n: int):
        if start >= n - 1:
            return
            
        # 在 nums[start:n] 中找最小值
        smallest = start
        for i in range(start + 1, n):
            if nums[i] < nums[smallest]:
                smallest = i
                
        # 交换到当前位置
        nums[start], nums[smallest] = nums[smallest], nums[start]
        
        # 递归处理剩余部分
        self.selection(nums, start + 1, n)
    
    def selection_sort(self, nums: list):
        self.selection(nums, 0, len(nums))
        return nums


class SelectionSortIterative:
	def selection_sort(self, nums: list):
		n = len(nums)

		for i in range(n):
			smallest = nums[i]
			
			for j in range(i + 1, n):
				if nums[j] < nums[smallest]:
					smallest = j

			nums[smallest], nums[i] = nums[i], nums[smallest]

		return nums


class QuickSort:
	def median_of_three(self, nums: list, low: int, high: int):
	    mid = (low + high) // 2

	    # 确保 nums[low] 最小
        if nums[mid] < nums[low]:
            nums[low], nums[mid] = nums[mid], nums[low]
        if nums[high] < nums[low]:
            nums[low], nums[high] = nums[high], nums[low]

        # 确保中位数在 high 位置
        if nums[mid] < nums[high]:
            nums[mid], nums[high] = nums[high], nums[mid]

	def partition(self, nums: list, low: int, high: int):
        self.median_of_three(nums, low, high)

		pivot = nums[high]
		i = low - 1
		
		for j in range(low, high):
			if nums[j] <= pivot:
				nums[i + 1], nums[j] = nums[j], nums[i + 1]
				i += 1

		nums[i + 1], nums[high] = nums[high], nums[i + 1]

		return i + 1

	def sort(self, nums: list, low: int, high: int):
		if low >= high:
    		return

		pivot_ind = self.partition(nums, low, high)
		self.sort(nums, low, pivot_ind - 1)
		self.sort(nums, pivot_ind + 1, high)

	def quick_sort(self, nums: list):
        self.sort(nums, 0, len(nums) - 1)
        return nums


class HeapSort:
    def __init__(self, nums: list):
        self.nums = nums[:]
        self.n = len(self.nums)

    def has_left_child(self, i: int):
        return 2 * i + 1 < self.n
    
    def has_right_child(self, i: int):
        return 2 * i + 2 < self.n
    
    def has_parent(self, i: int):
        return i > 0
    
    def parent(self, i: int):
        return (i - 1) // 2
    
    def left(self, i: int):
        return 2 * i + 1
    
    def get_right_child_index(self, i: int):
        return 2 * i + 2
    
    def heapify(self, i: int):
        """向下堆化：确保以i为根的子树满足最大堆性质"""
        largest = i
        left = self.left(i)
        right = self.right(i)
        
        # 找到i、left、right中的最大值
        if left < self.n and self.nums[left] > self.nums[largest]:
            largest = left
        if right < self.n and self.nums[right] > self.nums[largest]:
            largest = right
        
        # 如果最大值不是i，交换并继续堆化
        if largest != i:
            self.nums[i], self.nums[largest] = self.nums[largest], self.nums[i]
            self.heapify(largest)
    
    def insert(self, k: int):
        """插入元素并维护堆性质"""
        # 扩展数组
        self.nums.append(k)
        self.n += 1
        
        # 向上堆化
        i = self.n - 1
        while (self.has_parent(i) and self.nums[self.parent(i)] < self.nums[i]):
            parent_idx = self.parent(i)
            self.nums[i], self.nums[parent_idx] = self.nums[parent_idx], self.nums[i]
            i = parent_idx
    
    def delete_max(self):
        """删除最大元素（堆顶）"""
        if self.n == 0:
            return None
            
        # 保存要删除的最大值
        max_val = self.nums[0]
        
        # 将最后一个元素移到根部
        self.nums[0] = self.nums[self.n - 1]
        self.n -= 1
        
        # 缩小数组
        if self.n > 0:
            self.nums = self.nums[:self.n]
            # 向下堆化恢复堆性质
            self.heapify(0)
        else:
            self.nums = []
            
        return max_val
    
    def build_max_heap(self):
        """从任意数组构建最大堆"""
        # 从最后一个非叶子节点开始，向下堆化
        for i in range((self.n // 2) - 1, -1, -1):
            self.heapify(i)
    
    def heap_sort(self):
        """堆排序"""
        # 构建最大堆
        self.build_max_heap()
        
        # 依次取出最大元素
        original_n = self.n
        for i in range(self.n - 1, 0, -1):
            # 将最大元素（根）移到末尾
            self.nums[0], self.nums[i] = self.nums[i], self.nums[0]
            # 减小堆的大小
            self.n -= 1
            # 重新堆化
            self.heapify(0)
        
        # 恢复数组大小
        self.n = original_n
        return self.nums
