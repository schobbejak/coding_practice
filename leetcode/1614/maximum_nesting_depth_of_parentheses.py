class Solution:
    def maxDepth(self, s: str) -> int:
        count = 0
        maxCount = 0
        for c in s:
            if c == '(':
                count += 1
            elif c == ')':
                count -= 1

            maxCount = max(count, maxCount)

        return maxCount
