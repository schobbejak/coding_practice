#include <iostream>
#include <cstddef>
#include <string>

using namespace std;

class Solution {

public:
  string mergeAlternately(string word1, string word2) {
    string new_string = "";

    size_t max = word1.length();
    if (word2.length() > max) {
      max = word2.length();
    }

    for (size_t i = 0; i < max; i++) {
      if (i < word1.length()) {
        new_string += word1[i];
      };

      if (i < word2.length()) {
        new_string += word2[i];
      };
    };

    return new_string;
  };
};

int main() {

}
