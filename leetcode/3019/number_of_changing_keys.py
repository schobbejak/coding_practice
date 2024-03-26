class Solution:
    def countKeyChanges(self, s: str) -> int:
        s = s.lower()
        prev_c = s[0]
        count = 0
        for c in s[1:]:
            if not c == prev_c:
                prev_c = c
                count += 1

        return count
