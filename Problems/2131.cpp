class Solution {
  public:
    int longestPalindrome(vector<string> &words) {
        unordered_map<string, int> um;
        for (string &w : words)
            um[w]++;

        bool odd = false;
        int res = 0;
        for (const auto &[s, count] : um) {
            if (!count) continue;

            if (s[0] == s[1]) {
                if (count % 2 == 0) {
                    res += count;
                } else {
                    res += count - 1;
                    odd = true;
                }
            } else if (s[0] < s[1] && um.count({s[1], s[0]})) {
                res += min(count, um[{s[1], s[0]}]) * 2;
            }
        }
        if (odd) res++;
        return res * 2;
    }
};
