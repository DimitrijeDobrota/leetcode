class Solution {
  public:
    string minWindow(string s, string t) {
        vector<int> remaining(128, 0);
        for (char c : t)
            remaining[c]++;

        int required = t.size();
        int min = INT_MAX, start = 0, left = 0, i = 0;
        while (i <= s.size() && start < s.size()) {
            if (required) {
                if (i == s.size()) break;
                if (--remaining[s[i++]] >= 0) required--;
            } else {
                if (i - start < min) {
                    min = i - start;
                    left = start;
                }
                if (++remaining[s[start++]] > 0) required++;
            }
        }
        return min == INT_MAX ? "" : s.substr(left, min);
    }
};
