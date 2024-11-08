class Solution {
    static string valid4(const string &s) {
        stringstream ss(s);
        string crnt;
        int cnt = 0;

        while (getline(ss, crnt, '.')) {
            if (size(crnt) == 0 || size(crnt) > 3) break;
            if (any_of(begin(crnt), end(crnt), [](char c) { return isalpha(c); })) break;
            if (size(crnt) > 1 && crnt[0] == '0') break;
            if (stoi(crnt) >= 256) break;
            cnt++;
        }

        return cnt == 4 ? "IPv4" : "Neither";
    }

    static string valid6(const string &s) {
        stringstream ss(s);
        string crnt;
        int cnt = 0;

        while (getline(ss, crnt, ':')) {
            if (size(crnt) == 0 || size(crnt) > 4) break;
            cnt++;
        }

        return cnt == 8 ? "IPv6" : "Neither";
    }

  public:
    string validIPAddress(const string &queryIP) const {
        int dot = 0, col = 0;

        for (const char c : queryIP) {
            if (c == '.')
                dot++;
            else if (c == ':')
                col++;
            else if (!isxdigit(c))
                return "Neither";
        }

        if (dot && col) return "Neither";
        if (dot ? dot != 3 : col != 7) return "Neither";

        return dot ? valid4(queryIP) : valid6(queryIP);
    }
};
