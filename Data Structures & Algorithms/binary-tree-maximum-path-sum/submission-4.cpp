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
    int maxPathSum(TreeNode* root) {
            int maxPath = root->val;
            pathSum(root, maxPath);
            return maxPath;
    }

private:
    int pathSum(TreeNode* node, int& maxPath){
        if (node == nullptr) return 0;

        int currVal = node->val;
        
        int left = pathSum(node->left, maxPath);
        int right = pathSum(node->right, maxPath);

        if(left > 0 && right > 0){
            maxPath = max(maxPath, left + right + currVal);
        }
        else if (left > 0){
            maxPath = max(maxPath, left + currVal);

        }
        else if (right > 0){
            maxPath = max(maxPath, right + currVal);
        }
        else maxPath = max(maxPath, currVal);
        return currVal + max({left, right, 0});
    }

};
