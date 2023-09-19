class Solution {
  public:
    vector<int> decode(const vector<int> &encoded) {
        const int n = encoded.size();
        vector<int> res(n + 1);

        res[0] = n + 1;
        for (int i = 0; i < n; i++) {
            if (i & 1) res[0] ^= encoded[i];
            res[0] ^= i + 1;
        }

        for (int i = 1; i <= n; i++)
            res[i] = res[i - 1] ^ encoded[i - 1];

        return res;
    }
};
