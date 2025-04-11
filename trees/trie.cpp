struct TrieNode {
    TrieNode** links;
    bool flag = false;

    TrieNode(int sz) {
        links = new TrieNode*[sz]();
    }

    bool contains(int x) {
        return (links[x] != nullptr);
    }

    void put(int x, TrieNode* node) {
        links[x] = node;
    }

    TrieNode* get(int x) {
        return links[x];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    TrieNode* root;
    int sz = 26;

public:
    Trie(int n) {
        sz = n;
        root = new TrieNode(sz);
    }

    void insert(string s) {
        TrieNode* node = root;
        for (int i = 0; i < s.length(); ++i) {
            int c = (s[i] - 'a');
            if (!node->contains(c)) {
                node->put(c, new TrieNode(sz));
            }
            node = node->get(c);
        }
        node->setEnd();
    }

    bool search(string s) {
        TrieNode* node = root;
        for (int i = 0; i < s.length(); ++i) {
            int c = (s[i] - 'a');
            if (!node->contains(c)) {
                return false;
            }
            node = node->get(c);
        }
        return node->isEnd();
    }
};