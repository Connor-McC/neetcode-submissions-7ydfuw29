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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> onlyRights;
        queue<TreeNode*> que;

        if (root == nullptr) return onlyRights;

        que.push(root);
        while(!que.empty()){
            TreeNode* node = que.front();
            onlyRights.push_back(node->val);
           
            
            int n = que.size();

            for(int index = 0; index < n ; index++){
                TreeNode* node = que.front();
                que.pop();

                if(node->right != nullptr) que.push(node->right);
                if(node->left != nullptr) que.push(node->left);
            }
        }
        return onlyRights;
    }
};
