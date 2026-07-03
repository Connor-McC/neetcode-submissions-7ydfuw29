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

class Codec {
public:
    string serialize(TreeNode* root) {
        string result;
        buildString(root, result);
        return result;
    }

    TreeNode* deserialize(string data) {
        vector<string> tokens = splitTokens(data);
        int pos = 0;
        return rebuildTree(tokens, pos);
    }

private:
    void buildString(TreeNode* node, string& out) {
        if (!node) {
            out += "N,";
            return;
        }
        out += to_string(node->val) + ",";
        buildString(node->left, out);
        buildString(node->right, out);
    }

    vector<string> splitTokens(const string& data) {
        vector<string> tokens;
        string current;
        for (char c : data) {
            if (c == ',') {
                tokens.push_back(current);
                current.clear();
            } else {
                current += c;
            }
        }
        return tokens;
    }

    TreeNode* rebuildTree(vector<string>& tokens, int& pos) {
        if (tokens[pos] == "N") {
            pos++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(tokens[pos]));
        pos++;
        node->left = rebuildTree(tokens, pos);
        node->right = rebuildTree(tokens, pos);
        return node;
    }
};
