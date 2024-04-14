class Solution {
  public:
    string getSmallestString(string &s, int k) const {
        for (int i = 0; i < size(s) && k > 0; ++i) {
            int dist = min(s[i] - 'a', 'z' - s[i] + 1);
            s[i] = dist <= k ? 'a' : s[i] - k;
            k -= dist;
        }
        return s;
    }
};
