class Solution {
  public:
    int maximumCostSubstring(const string &s, const string &chars, const vector<int> &vals) {
        static int cost[27];

        for (int i = 1; i <= 26; i++)
            cost[i] = i;
        for (int i = 0; i < size(vals); i++)
            cost[chars[i] & 0x1F] = vals[i];

        int res = 0, crnt = 0;
        for (int i = 0; i < size(s); i++) {
            crnt = max(0, crnt + cost[s[i] & 0x1F]);
            res = max(res, crnt);
        }

        return res;
    }
};
