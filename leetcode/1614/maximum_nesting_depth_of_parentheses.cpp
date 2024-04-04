#include <string>

using namespace std;

class Solution {

public:
  int maxDepth(string s) {
    int count = 0;
    int maxCount = 0;
    for (char c : s) {
      if (c == '(') {
        count++;
      } else if (c == ')') {
        count--;
      }

      if (count > maxCount) {
        maxCount = count;
      }
    }

    return maxCount;
  }
};
