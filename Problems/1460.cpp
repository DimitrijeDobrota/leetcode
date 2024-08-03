class Solution {
  public:
    bool canBeEqual(const vector<int> &target, const vector<int> &arr) const {
        static int um[1001];

        memset(um, 0x00, sizeof(um));
        for (const int n : target)
            um[n]++;
        for (const int n : arr)
            if (!um[n]--) return false;

        return true;
    }
};
