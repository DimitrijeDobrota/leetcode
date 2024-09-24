class Solution {
  public:
    int longestCommonPrefix(const vector<int> &arr1, const vector<int> &arr2) const {
        unordered_set<int> us;
        int res = 0;

        for (int n : arr1) {
            while (n > 0) {
                us.insert(n);
                n /= 10;
            }
        }

        for (int n : arr2) {
            while (n > 0) {
                if (us.count(n)) {
                    res = max(res, (int)log10(n) + 1);
                    break;
                }
                n /= 10;
            }
        }

        return res;
    }
};
