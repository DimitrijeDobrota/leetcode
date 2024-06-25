class Solution {
  public:
    vector<int> maximumBobPoints(const int numArrows, const vector<int> &aliceArrows) const {
        vector<int> res;
        int maxi = 0;

        for (int i = 0; i < (1 << 11); i++) {
            unsigned mask = i, score = 0, total = 0;
            static int crnt[12];

            memset(crnt, 0x00, sizeof(crnt));
            while (mask) {
                int idx = std::countr_zero(mask);
                mask ^= 1u << idx++;

                total += crnt[idx] = aliceArrows[idx] + 1;
                score += idx;
            }

            if (total <= numArrows && score > maxi) {
                res = vector<int>(crnt, crnt + 12);
                res[0] += numArrows - total;
                maxi = score;
            }
        }

        return res;
    }
};
