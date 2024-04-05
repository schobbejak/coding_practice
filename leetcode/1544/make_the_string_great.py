# 30ms | 16.47mb
# 93.52% | 91.17%
class Solution:
    def makeGood(self, s: str) -> str:
        pointer = 1
        while pointer < len(s):
            if s[pointer].lower() == s[pointer-1].lower() and s[pointer] != s[pointer-1]:
                s = s[:pointer-1] + s[pointer+1:]
                pointer = max(pointer - 2, 0)
            pointer += 1
        return s
