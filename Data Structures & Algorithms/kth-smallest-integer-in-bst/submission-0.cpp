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
    int kthSmallest(TreeNode* root, int k) {
        int result = -1, count = 0;
        dfs(root, k, count, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int k, int& count, int& result) {
        if (!node || result != -1) return;

        dfs(node->left, k, count, result);  // visit left subtree first

        if (++count == k) {                 // this node is the kth visited
            result = node->val;
            return;
        }

        dfs(node->right, k, count, result); // visit right subtree
    }
};
