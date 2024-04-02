// 17ms | 28.11mb
// 5.36% | 5.20%
class Solution {

public: 
  int minimumSubarrayLength(vector<int>& nums, int k) {
    if (*max_element(nums.begin(), nums.end()) >= k) {
      return 1;
    }

    for (int size = 2; size <= nums.size(); size++) {
      for (int index = 0; index <= nums.size() - size; index++) {
        vector<int> subarray(nums.begin() + index, nums.begin() + index+size);
        int bitwise = 0;
        for (int elem : subarray) {
          bitwise |= elem;
        }
        if (bitwise >= k) {
          return size;
        }
      }
    } 

    return -1;
  }
};
