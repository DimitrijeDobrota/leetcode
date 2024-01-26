class Solution {
  public:
    vector<int> numMovesStonesII(vector<int> &stones) const {
        const int n = size(stones);
        vector<int> res(2, n);
        sort(begin(stones), end(stones));

        int i = 0;
        for (int j = 0; j < n; j++) {
            while (stones[j] - stones[i] >= n)
                i++;
            if (j - i + 1 == n - 1 && stones[j] - stones[i] == n - 2)
                res[0] = min(res[0], 2);
            else
                res[0] = min(res[0], n - (j - i + 1));
        }

        res[1] = 2 + max(stones[n - 2] - stones[0], stones[n - 1] - stones[1]) - n;
        return res;
    }
};
