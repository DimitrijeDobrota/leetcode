class Solution {
  public:
    vector<int> constructArray(int n, int k) const {
        vector<int> res(n);
        int idx = 0;
        for (int i = 1; i < n - k; i++)
            res[idx++] = i;
        for (int i = 0; i <= k; i++) {
            res[idx++] = i % 2 ? n - i / 2 : n - k + i / 2;
        }
        return res;
    }
};
