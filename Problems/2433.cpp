class Solution {
  public:
    vector<int> findArray(vector<int> &pref) {
        int mask = 0;
        for (int &n : pref) {
            n ^= mask;
            mask ^= n;
        }
        return pref;
    }
};
