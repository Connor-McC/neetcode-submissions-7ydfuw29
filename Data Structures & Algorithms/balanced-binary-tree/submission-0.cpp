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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        bool is = true;
        height(root, is);

        return is;
    }
private:
    int height(TreeNode* root, bool& is){
        if (root == nullptr) return true;
        int left = height(root->left, is);
        int right = height(root->right, is);
        if(abs(left - right) > 1){
            is = false;
        }

        return 1 + max(left, right);
    }

};
