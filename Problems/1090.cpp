class Solution {
  public:
    int largestValsFromLabels(const vector<int> &values, const vector<int> &labels, int numWanted,
                              int useLimit) {
        static int count[20001], idx[20001];
        memset(count, 0x00, sizeof(count));

        const int n = values.size();
        iota(begin(idx), begin(idx) + n, 0);
        sort(begin(idx), begin(idx) + n, [&](int a, int b) { return values[a] > values[b]; });

        int res = 0;
        for (const int i : idx) {
            if (count[labels[i]] >= useLimit) continue;
            res += values[i];
            if (!--numWanted) break;
            count[labels[i]]++;
        }
        return res;
    }
};
