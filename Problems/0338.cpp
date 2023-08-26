class Solution {
  public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        int offset = 1;
        for (int i = 1; i <= n; i++) {
            if (offset * 2 == i) offset *= 2;
            res[i] = (res[i - offset]) + 1;
        }
        return res;
    }
};
