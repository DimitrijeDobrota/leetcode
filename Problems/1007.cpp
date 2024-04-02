class Solution {
  public:
    int minDominoRotations(const vector<int> &tops, const vector<int> &bottoms) {
        const int n = size(tops);
        int up[7] = {0}, down[7] = {0}, both[7] = {0};

        for (int i = 0; i < n; i++) {
            if (tops[i] == bottoms[i])
                both[tops[i]]++;
            else
                up[tops[i]]++, down[bottoms[i]]++;
        }

        for (int i = 1; i <= 6; i++) {
            if (up[i] + down[i] != n - both[i]) continue;
            return min(up[i], down[i]);
        }

        return -1;
    }
};
