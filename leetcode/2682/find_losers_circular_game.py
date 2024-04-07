# 51ms | 16.52mb
# 49.81% | 78.33%
class Solution:
    def circularGameLosers(self, n: int, k: int) -> list[int]:
        winners = [False for x in range(n)]
        current_friend = 0
        current_k = 1

        playing = True
        while playing:
            if winners[current_friend]:
                playing = False
                continue

            winners[current_friend] = True
            current_friend = (current_friend + current_k * k) % n
            current_k += 1

        losers = []
        for i, player in enumerate(winners):
            if not player:
                losers.append(i)

        return losers
