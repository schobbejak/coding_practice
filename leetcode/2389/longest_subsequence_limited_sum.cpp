// 6ms | 16.6mb
// 96.15% | 16.84%
#include <vector>
#include <iostream>

using namespace std;

class Solution {

public:
  vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
    sort(nums.begin(), nums.end());

    // Calculate running sum
    vector<int> running_sum;
    int rs = 0;
    for (int num : nums) {
      rs += num;
      running_sum.push_back(rs);
    }

    vector<int> result;
    for (int query : queries) {
      int result_idx = binarySearch(running_sum, query);
      result.push_back(result_idx + 1);
    }

    return result;
  }

  int binarySearch(vector<int> &array, int value) {
    int start = 0;
    int end = array.size() - 1;

    int mid = 0;
    while (start <= end) {

      mid = (start + end) / 2;

      if (array[mid] == value) {
        return mid;
      } else if (array[mid] < value) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    if (array[mid] > value) {
      mid -= 1;
    }
    return mid;
  }
};
