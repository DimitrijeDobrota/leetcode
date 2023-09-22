class Solution {
    struct Node {
        Node(){};
        Node *children[27] = {nullptr};
        bool &terminate = reinterpret_cast<bool &>(children[0]);
    };

  public:
    string replaceWords(const vector<string> &dictionary, const string &sentence) {
        Node *trie = new Node();
        for (const string &s : dictionary) {
            Node *crnt = trie;
            for (const char c : s) {
                const int idx = c & 0x1F;
                if (!crnt->children[idx]) crnt->children[idx] = new Node();
                crnt = crnt->children[idx];
            }
            crnt->terminate = true;
        }

        string res, word, tmp;
        stringstream ss(sentence);
        while (ss >> word) {
            Node *crnt = trie;
            for (const char c : word) {
                const int idx = c & 0x1F;
                if (!crnt->children[idx] || crnt->terminate) break;
                crnt = crnt->children[idx];
                tmp += c;
            }
            res += (crnt->terminate ? tmp : word) + ' ';
            tmp.clear();
        }
        res.pop_back();
        return res;
    }
};
