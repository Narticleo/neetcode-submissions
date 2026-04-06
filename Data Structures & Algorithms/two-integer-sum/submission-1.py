class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = {}
        for i, num in enumerate(nums):
            hash[num] = i
        
        for i, num in enumerate(nums):
            if target-num in hash and i != hash[target-num]:
                return [i, hash[target-num]]
        return [0,0]