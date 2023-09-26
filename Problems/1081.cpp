class Solution {
  public:
    string smallestSubsequence(const string &s) {
        uint16_t last[128] = {0}, seen[128] = {0};
        string res = "";

        for (int i = 0; i < s.size(); i++)
            last[s[i]] = i;
        for (int i = 0; i < s.size(); i++) {
            if (seen[s[i]]++) continue;
            while (!res.empty() && res.back() > s[i] && i < last[res.back()]) {
                seen[res.back()] = 0;
                res.pop_back();
            }
            res.push_back(s[i]);
        }
        return res;
    }
};
