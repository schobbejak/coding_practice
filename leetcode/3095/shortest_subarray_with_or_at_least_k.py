# 39ms | 16.66mb
# 97.71% | 22.44%
class Solution:
    def minimumSubarrayLength(self, nums: list[int], k: int) -> int:
        if max(nums) >= k:
            return 1

        smallest = -1

        for size in range(2, len(nums)+1):
            for subarray_i in range(len(nums) - size + 1):
                subarray = nums[subarray_i:subarray_i+size]
                or_result = 0
                for elem in subarray:
                    or_result = or_result | elem
                if or_result >= k:
                    return size

        return smallest
