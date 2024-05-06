class Solution {
  public:
    int maxConsecutive(int bottom, int top, vector<int> &special) const {
        int res = 0, i;

        sort(begin(special), end(special));
        for (i = 0; i < size(special); i++)
            if (special[i] >= bottom) break;
        for (; i < size(special); i++) {
            if (special[i] > top) break;
            res = max(res, special[i] - bottom);
            bottom = special[i] + 1;
        }

        return max(res, top - bottom + 1);
    }
};
