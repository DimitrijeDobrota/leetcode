class Solution {
    static bool valid(const string &s) {
        const int n = size(s);
        if (n == 1) return true;
        if (s[0] == '0' && s[1] != '.') return false;

        for (int i = 0; i < n; i++) {
            if (s[i] == '.') return s[n - 1] != '0';
        }

        return true;
    }

    const vector<string> devide(const string &s) const {
        const int n = size(s);
        vector<string> res;
        if (valid(s)) res.push_back(s);
        string left(1, s[0]);
        for (int i = 1; i < n; i++) {
            const string crnt = left + '.' + s.substr(i, n - i);
            if (valid(crnt)) res.push_back(crnt);
            left += s[i];
        }
        return res;
    }

  public:
    vector<string> ambiguousCoordinates(const string &s) const {
        const int n = size(s) - 2;
        vector<string> res;
        string left;
        for (int i = 1; i < n; i++) {
            left += s[i];
            for (const auto &a : devide(left)) {
                for (const auto &b : devide(s.substr(i + 1, n - i))) {
                    res.push_back("(" + a + ", " + b + ")");
                }
            }
        }
        return res;
    }
};
