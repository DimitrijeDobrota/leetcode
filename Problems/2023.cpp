class Solution {
public:
  int numOfPairs(const vector<string> &nums, const string target) {
    unordered_map<string, int> um;
    for (const auto &s : nums) um[s]++;

    int res = 0;
    for (int i = 0; i < target.size(); i++) {
      const string s1 = target.substr(0, i);
      const string s2 = target.substr(i);
      res += (s1 != s2) ? um[s1] * um[s2] : um[s1] * (um[s1] - 1);
    }
    return res;
  }
};
