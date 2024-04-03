# 95ms | 16.86mb
# 60.09% | 87.76%
class Solution:
    def answerQueries(self, nums: list[int], queries: list[int]) -> list[int]:
        result = []
        nums.sort()

        self.running_sum = []
        rs = 0
        for num in nums:
            rs += num
            self.running_sum.append(rs)

        for query in queries:
            rs_idx = self.binarySearch(query)
            result.append(rs_idx + 1)
        return result

    def binarySearch(self, q):
        start = 0
        end = len(self.running_sum) - 1
        while start <= end:
            mid = (start + end) // 2
            if self.running_sum[mid] == q:
                return mid
            elif self.running_sum[mid] < q:
                start = mid+1
            else:
                end = mid - 1

        if self.running_sum[mid] > q:
            return mid - 1
        return mid
