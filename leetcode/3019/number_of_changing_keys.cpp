#include <iostream>
#include <string>

using namespace std;

class Solution {

public:
  int countKeyChanges(string s) {
    int count = 0;
    char prev_char = tolower(s[0]);

    for (char curr_char : s) {
      curr_char = tolower(curr_char);
      if (curr_char != prev_char) {
        prev_char = curr_char;
        count++;
      };
    };

    return count;
  };
};

int main() {
}
