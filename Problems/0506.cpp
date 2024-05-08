class Solution {
  public:
    vector<string> findRelativeRanks(const vector<int> &score) const {
        static const char *medal[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        static int index[10001];
        const int n = size(score);

        iota(index, index + n, 0);
        sort(index, index + n, [&score](int a, int b) { return score[a] > score[b]; });

        vector<string> res(n);
        for (int i = 0; i < n; i++)
            res[index[i]] = to_string(i + 1);
        for (int i = 0; i < min(n, 3); i++)
            res[index[i]] = medal[i];

        return res;
    }
};
