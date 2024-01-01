class Solution {
  public:
    int findContentChildren(vector<int> &g, vector<int> &s) const {
        sort(rbegin(g), rend(g));
        sort(rbegin(s), rend(s));
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) j++;
            i++;
        }
        return j;
    }
};
