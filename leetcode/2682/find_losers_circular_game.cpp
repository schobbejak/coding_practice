// 6ms | 11mb
// 59.26% | 86.11%
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> winners;
        for (int i = 0; i < n; i++) {
            winners.push_back(false);
        }

        int current_friend = 0;
        int current_k = 1;
        bool playing = true;

        while (playing) {
            if (winners[current_friend]) {
                playing = false;
            } else {
                winners[current_friend] = true;
                current_friend = (current_friend + current_k * k) % n;
                current_k++;
            }
        }

        vector<int> losers;
        for (int i = 0; i < n; i++) {
            if (!winners[i]) {
                losers.push_back(i+1);
            }
        }

        return losers;
    }
};
