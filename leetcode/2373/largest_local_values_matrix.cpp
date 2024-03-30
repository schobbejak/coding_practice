#include<vector>

using namespace std;

class Solution {

public:
    int largestGrid(vector<vector<int>>& grid) {
      int max_elem = grid[0][0];
      for (int i = 0; i < grid.size(); i++) {
        auto curr_max = max_element(grid[i].begin(), grid[i].end());
        max_elem = max(max_elem, *curr_max);
      }
      return max_elem;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size() - 2;
        vector<vector<int>> result;

        for (int i = 0; i < n; i++) {
          vector<int> row;
          for (int j = 0; j < n; j++) {
            vector<vector<int>> localGrid;
            localGrid.push_back(vector<int>(grid[i].begin()+j, grid[i].begin()+j+3));
            localGrid.push_back(vector<int>(grid[i+1].begin()+j, grid[i+1].begin()+j+3));
            localGrid.push_back(vector<int>(grid[i+2].begin()+j, grid[i+2].begin()+j+3));
            row.push_back(largestGrid(localGrid));
          };
          result.push_back(row);
        };
        return result;
    };
};

