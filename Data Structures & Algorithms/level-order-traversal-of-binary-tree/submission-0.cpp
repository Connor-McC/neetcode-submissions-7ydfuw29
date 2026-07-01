/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        queue<TreeNode*> que;

        if (root == nullptr) return levels;

        que.push(root);
        while(!que.empty()){
            vector<int> level;
            
            int n = que.size();
            for(int index = 0; index < n ; index++){
                TreeNode* node = que.front();
                que.pop();
                level.push_back(node->val);

                if(node->left != nullptr) que.push(node->left);
                if(node->right != nullptr) que.push(node->right);
            }
            levels.push_back(level);
        }
        return levels;
    }
};
