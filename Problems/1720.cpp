class Solution {
  public:
    vector<int> decode(const vector<int> &encoded, int first) const {
        const int n = size(encoded);
        vector<int> res(n + 1);

        res[0] = first;
        for (int i = 0; i < size(encoded); i++) {
            res[i + 1] = encoded[i] ^ res[i];
        }

        return res;
    }
};
