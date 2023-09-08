class Solution {
  public:
    string evaluate(const string &s, const vector<vector<string>> &knowledge) {
        unordered_map<string, string> um;
        for (const auto &p : knowledge)
            um[p[0]] = p[1];

        string res, key;
        bool open = false;
        for (const char c : s) {
            if (c == '(')
                open = true;
            else if (c == ')') {
                res += um.count(key) ? um[key] : "?";
                open = false;
                key.clear();
            } else {
                (open ? key : res) += c;
            }
        }
        return res;
    }
};
