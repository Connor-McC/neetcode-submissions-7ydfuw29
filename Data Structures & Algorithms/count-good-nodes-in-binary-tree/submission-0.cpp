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
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int count = 0;
        int maxSeen = root->val;
        countGoods(root, maxSeen, count);
        return count;
    }

private:
    void countGoods(TreeNode* node, int maxSeen, int& count){
        if (node == nullptr) return;
        if (node->val >= maxSeen){
            count++;
            maxSeen = node->val;
        }
        countGoods(node->left, maxSeen, count);
        countGoods(node->right, maxSeen, count);
    }
};
