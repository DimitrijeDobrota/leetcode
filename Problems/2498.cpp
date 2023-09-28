class Solution {
  public:
    int maxJump(const vector<int> &stones) {
        int res = stones[1];
        for (int i = 2; i < stones.size(); i++)
            res = max(res, stones[i] - stones[i - 2]);
        return res;
    }
};
