class Solution {
  public:
    int earliestFullBloom(const vector<int> &plantTime, const vector<int> &growTime) const {
        const int n = size(plantTime);
        static int idxs[100001];

        iota(idxs, idxs + n, 0);
        sort(idxs, idxs + n, [&](int a, int b) { return growTime[a] > growTime[b]; });

        int res = 0, acc = 0;
        for (const int i : span(idxs, n)) {
            acc += plantTime[i];
            res = max(res, acc + growTime[i]);
        }

        return res;
    }
};
