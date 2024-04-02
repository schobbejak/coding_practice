class Solution {

public:
  int maximumPopulation(vector<vector<int>>& logs) {
    int maxDeath = 0;
    int minBirth = 0;

    for (int i = 0; i < logs.size(); i++) {
      maxDeath = max(maxDeath, logs[i][1]);
      minBirth = min(minBirth, logs[i][0]);
    }

    // Create vector with count
    vector<int> popCount(maxDeath - minBirth, 0);

    // Add popcount per log
    for (vector<int> log : logs) {
      for (int i = log[0]; i < log[1]; i++) {
        popCount[i] += 1;
      }; 
    };

    // Get maximum year
    int max_year = 0;
    int max_count = 0;
    for (int i = 0; i < popCount.size(); i++) {
      int curr_count = popCount[i];
      if (curr_count > max_count) {
        max_year = i;
        max_count = curr_count;
      };
    };

    return max_year + minBirth;
  };

  int max(int a, int b) {
    if (a > b) {
        return a;
    };
    return b;
  };

  int min(int a , int b) {
    if (a > b) {
        return b;
    };
    return a;
  };
};
