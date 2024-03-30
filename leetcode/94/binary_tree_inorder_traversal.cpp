#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        if (root == nullptr) {
          return result;
        }

        if (root->left != nullptr) {
          vector<int> leftTree = inorderTraversal(root->left);
          result.insert(result.end(), leftTree.begin(), leftTree.end());
        }

        result.insert(result.end(), 1, root->val);

        if (root->right != nullptr) {
          vector<int> rightTree = inorderTraversal(root->right);
          result.insert(result.end(), rightTree.begin(), rightTree.end());
        }

        return result;
    };
};
