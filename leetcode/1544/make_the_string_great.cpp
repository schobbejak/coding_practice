// 0ms | 7.5mb
// 100.0% | 98.66%
class Solution {

public:
  string makeGood(string s) {
    for (auto si = s.begin() + 1; si < s.end(); ++si) {
      if (tolower(*(si - 1)) == tolower(*(si)) && *(si - 1) != *(si)) {
        s.erase(si);
        s.erase(si - 1);
        si = s.begin();
      }
    }
    return s;
  }
};
