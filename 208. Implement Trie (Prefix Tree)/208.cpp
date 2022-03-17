/*
    Author: Yeasin Mollik
    Problem Name: Implement Trie (Prefix Tree)
    Date: 17/3/2022
*/

class Trie {
   public:
    Trie() {
        root = new Node();
    }

    struct Node {
        Node *child[26];
        bool isEnd = false;
    } * root;

    void insert(string word) {
        auto curr = root;
        for (char ch : word) {
            int c = ch - 'a';
            if (curr->child[c] == NULL)
                curr->child[c] = new Node();
            curr = curr->child[c];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        auto curr = root;
        for (char ch : word) {
            int c = ch - 'a';
            if (curr->child[c] == NULL)
                return false;
            curr = curr->child[c];
        }
        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        auto curr = root;
        for (char ch : prefix) {
            int c = ch - 'a';
            if (curr->child[c] == NULL)
                return false;
            curr = curr->child[c];
        }
        return true;
    }
};

