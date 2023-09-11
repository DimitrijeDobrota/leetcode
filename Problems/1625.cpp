class Solution {
    unordered_set<string> seen;
    string res;

    string rotate(string s, int b) {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
        return s;
    }

    string add(string s, int x) {
        for (int i = 1; i < s.size(); i += 2)
            s[i] = '0' + ((s[i] & 0xF) + x) % 10;
        return s;
    }

  public:
    void dfs(const int a, const int b, const string &s) {
        if (seen.count(s)) return;
        res = min(res, s);
        seen.insert(s);
        dfs(a, b, rotate(s, b));
        dfs(a, b, add(s, a));
    }

    string findLexSmallestString(const string &s, int a, int b) {
        res = s;
        dfs(a, b, s);
        return res;
    }
};
