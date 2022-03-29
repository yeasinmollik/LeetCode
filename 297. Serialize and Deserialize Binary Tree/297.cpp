/*
    Author: Yeasin Mollik
    Problem Name: Serialize and Deserialize Binary Tree
    Date: 29/3/2022
*/

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "#";
        string encoded;
        encode(root, encoded);
        cout << encoded << endl;
        return encoded;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#") return NULL;
        vector<string> vals = split(data, ',');
        TreeNode* root;
        int id = 0;
        decode(root, vals, id);
        return root;
    }

   private:
    void encode(TreeNode* &curr, string& s) {
        if (curr == NULL) {
            s += "#,";
            return;
        }

        s += to_string(curr->val) + ",";
        encode(curr->left, s);
        encode(curr->right, s);
    }

    void decode(TreeNode* &curr, vector<string>& vals, int& id) { //notice the address of the pointer!
        if (vals[id] == "#")
            return;
        curr = new TreeNode(stoi(vals[id]));
        decode(curr->left, vals, ++id);
        decode(curr->right, vals, ++id);
    }

    vector<string> split(const string& s, char delim) {
        vector<string> result;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) result.push_back(item);
        return result;
    }
};
