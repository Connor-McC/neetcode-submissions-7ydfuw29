class WordDictionary {
private:
    struct Node {
        Node* children[26] = {nullptr};
        bool isEnd = false;
    };

    Node* root;

    bool dfs(Node* node, const string& word, int index) {
        if (node == nullptr) return false;
        if (index == (int)word.size()) return node->isEnd;

        char c = word[index];
        if (c == '.') {
            for (Node* child : node->children) {
                if (dfs(child, word, index + 1)) return true;
            }
            return false;
        } else {
            return dfs(node->children[c - 'a'], word, index + 1);
        }
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr)
                cur->children[i] = new Node();
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};
