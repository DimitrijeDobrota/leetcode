class Solution {
  public:
    vector<int> sortByBits(vector<int> &arr) const {
        sort(begin(arr), end(arr), [](int a, int b) {
            const int x = __builtin_popcount(a);
            const int y = __builtin_popcount(b);
            return x != y ? x < y : a < b;
        });
        return arr;
    }
};
