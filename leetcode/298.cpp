/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        vector<TreeNode*> serial;
        seq(root, serial);
        for (auto &c : serial) {
            res = max(res, dfs(c));
        }
        return res;
    }
    
    void seq(TreeNode *root, vector<TreeNode*> &serial) {
        if (!root) return;
        serial.push_back(root);
        seq(root->left, serial);
        seq(root->right, serial);
    }
    int dfs(TreeNode *root) {
        if (!root) return 0;
        int left = 0;
        int right = 0;
        if (root->left && root->val == (root->left->val - 1)) {
            left = dfs(root->left);
        }
        if (root->right && root->val == (root->right->val - 1)) {
            right = dfs(root->right);
        }
        return max(left, right) + 1;
    }
};
