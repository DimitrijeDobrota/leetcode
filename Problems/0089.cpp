class Solution {
  public:
    vector<int> grayCode(const int n) const {
        const int k = 1 << n;
        vector<int> res(k, 0);
        for (int i = 0; i < k; i++) {
            res[i] = i ^ (i >> 1);
        }
        return res;
    }
};
