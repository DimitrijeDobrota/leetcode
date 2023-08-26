class Solution {
  public:
    bool buddyStrings(const string &s, const string &goal) {
        int a = -1, b = -1, dup = 0, count[26] = {0};
        if (s.size() != goal.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i] & 0xF]) dup = 1;
            count[s[i] & 0xF] = 1;
            if (s[i] != goal[i]) {
                if (a == -1)
                    a = i;
                else if (b == -1)
                    b = i;
                else
                    return false;
            }
        }
        if (a == -1) return dup;
        if (b == -1) return false;
        return s[a] == goal[b] && s[b] == goal[a];
    }
};
