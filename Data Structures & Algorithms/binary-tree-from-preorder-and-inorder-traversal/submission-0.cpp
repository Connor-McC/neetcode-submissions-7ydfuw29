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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            indexMap[inorder[i]] = i;

        int preIdx = 0;
        return dfs(preorder, preIdx, 0, inorder.size() - 1);
    }

private:
    unordered_map<int, int> indexMap;

    TreeNode* dfs(vector<int>& preorder, int& preIdx, int l, int r) {
        if (l > r) return nullptr;

        int rootVal = preorder[preIdx++];       
        TreeNode* node = new TreeNode(rootVal);

        int mid = indexMap[rootVal];            

        node->left  = dfs(preorder, preIdx, l, mid - 1);   
        node->right = dfs(preorder, preIdx, mid + 1, r);   

        return node;
    }
};
