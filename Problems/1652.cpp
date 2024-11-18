class Solution {
  public:
    vector<int> decrypt(vector<int> &code, int k) {
        const int n = size(code);
        vector<int> res(n, 0);

        if (k == 0) return res;

        auto [start, end] = k >= 0 ? tuple(1, k) : tuple(n + k, n - 1);
        int sum = 0;

        for (int i = start; i <= end; i++)
            sum += code[i];
        for (int i = 0; i < n; i++) {
            res[i] = sum;
            sum -= code[start++ % n];
            sum += code[++end % n];
        }

        return res;
    }
};
