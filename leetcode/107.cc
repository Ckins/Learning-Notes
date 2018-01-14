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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return vector<vector<int> >();
        TreeNode *cur = root;
        vector<vector<int> > res;
        int depth = 0;
        queue<pair<int, TreeNode*> > q;
        q.push(make_pair(0, root));
        while (q.size() != 0) {
            // cout << q.size() << endl;
            vector<int> level;
            while (depth == q.front().first) {
                TreeNode * cur = q.front().second;
                if (cur->left) q.push(make_pair(depth+1, cur->left));
                if (cur->right) q.push(make_pair(depth+1, cur->right));
                level.push_back(cur->val);
                q.pop();
            }
            depth++;
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
