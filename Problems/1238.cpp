class Solution {
  public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> res = {0, 1};
        int idx = 2;
        for (int i = 1; i < n; i++) {
            const int size = 1 << i;
            for (int j = 1; j <= size; j++) {
                res.push_back(size | res[size - j]);
                if (res.back() == start) idx = res.size();
            }
        }
        if (start == 0) return res;
        reverse(begin(res), begin(res) + idx);
        reverse(begin(res) + idx, end(res));
        return res;
    }
};

class Solution {
  public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> res;
        for (int i = 0; i < (1 << n); i++)
            res.push_back(start ^ i ^ (i >> 1));
        return res;
    }
};
