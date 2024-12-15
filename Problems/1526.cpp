class Solution {
  public:
    int minNumberOperations(const vector<int> &target) const {
        int res = target[0];

        for (int i = 1; i < size(target); i++) {
            res += max(target[i] - target[i - 1], 0);
        }

        return res;
    }
};
