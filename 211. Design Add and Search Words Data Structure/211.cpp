/*
    Author: Yeasin Mollik
    Problem Name: Design Add and Search Words Data Structure
    Date: 24/3/2022
*/

class WordDictionary {
   public:
    struct Node {
        Node *next[26];
        bool isWord = false;
    } * root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        auto curr = root;
        for (char ch : word) {
            int c = ch - 'a';
            if (!curr->next[c])
                curr->next[c] = new Node();
            curr = curr->next[c];
        }
        curr->isWord = true;
    }
    bool find(Node *curr, int id, string &s) {
        if (id == s.size())
            return curr->isWord;
        if (s[id] == '.') {
            bool found = false;
            for (int i = 0; i < 26; i++) {
                if (curr->next[i])
                    found = found | find(curr->next[i], id + 1, s);
            }
            return found;
        } else if (curr->next[s[id] - 'a'])
            return find(curr->next[s[id] - 'a'], id + 1, s);
        else
            return false;
    }
    bool search(string word) {
        auto curr = root;
        return find(curr, 0, word);
    }
};