class Solution {
  public:
    vector<int> missingRolls(const vector<int> &rolls, int mean, int n) const {
        int sum = mean * (n + size(rolls));
        int left = sum - accumulate(begin(rolls), end(rolls), 0);

        if (left < n || n * 6 < left) return {};

        vector<int> res(n, left / n);

        for (int i = 0; i < left % n; i++) {
            res[i]++;
        }

        return res;
    }
};
