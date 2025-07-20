class Solution:
   def backtrack(self, i, cum_sum, target, nums):
       """
       递归回溯函数，计算满足目标和的子集数量
       
       参数:
       i: 当前处理的元素索引
       cum_sum: 当前子集的累计和
       target: 目标和
       nums: 输入数组
       
       返回值:
       满足条件的子集数量
       """
       # 剪枝：如果当前累计和已经超过目标和，直接返回0
       if cum_sum > target:
           return 0

       # 基准情况：已经处理完所有元素
       if i == len(nums):
           # 如果累计和等于目标和，找到一个满足条件的子集
           return 1 if cum_sum == target else 0

       # 选择包含当前元素：将当前元素加入子集
       include = self.backtrack(i + 1, cum_sum + nums[i], target, nums)
       
       # 选择不包含当前元素：跳过当前元素
       exclude = self.backtrack(i + 1, cum_sum, target, nums)

       # 返回两种选择的结果之和
       return include + exclude
   
   def count_subsets_with_sum(self, nums, target):
       """
       主函数：计算数组中所有子集中和为target的子集数量
       
       参数:
       nums: 输入的非负整数数组
       target: 目标和
       
       返回值:
       满足条件的子集数量
       """
       return self.backtrack(0, 0, target, nums)

def main():
   """
   测试函数
   """
   # 创建Solution实例
   solution = Solution()
   
   # 测试用例1
   nums1 = [1, 2, 1]
   target1 = 3
   result1 = solution.count_subsets_with_sum(nums1, target1)
   print(f"数组 {nums1} 中和为 {target1} 的子集数量: {result1}")
   # 预期输出: 2 (子集 [1,2] 和 [2,1])
   
   # 测试用例2
   nums2 = [3, 34, 4, 12, 5, 2]
   target2 = 9
   result2 = solution.count_subsets_with_sum(nums2, target2)
   print(f"数组 {nums2} 中和为 {target2} 的子集数量: {result2}")
   # 预期输出: 2 (子集 [4,5] 和 [3,4,2])

if __name__ == '__main__':
   main()