// Backtracking: 4 ^ N
class Solution {
    static bool find(const vector<int> &sticks, const int side, int idx, int crnt[4]) {
        if (idx == size(sticks)) return crnt[0] == side && crnt[1] == side && crnt[2] == side;

        for (int i = 0; i < 4; i++) {
            if (crnt[i] + sticks[idx] > side) continue;

            crnt[i] += sticks[idx];
            if (find(sticks, side, idx + 1, crnt)) return true;
            crnt[i] -= sticks[idx];
        }

        return false;
    }

  public:
    bool makesquare(vector<int> &sticks) const {
        const int sum = accumulate(begin(sticks), end(sticks), 0);
        if (sum % 4 != 0) return false;

        sort(begin(sticks), end(sticks), greater<>());
        int crnt[4] = {sticks[0], 0};
        return find(sticks, sum / 4, 1, crnt);
    }
};

// DP: N * 2 ^ N
class Solution {
    uint8_t dp[4][1 << 16] = {0};

    bool find(const vector<int> &sticks, int left, int side, int crnt, uint16_t mask) {
        if (dp[left][mask]) return false;
        dp[left][mask] = 1;

        if (crnt == side) left--, crnt = 0;
        if (!left) return true;

        for (int i = 0, msk = 1; i < size(sticks); i++, msk <<= 1) {
            if (mask & msk) continue;
            if (crnt + sticks[i] > side) continue;
            if (find(sticks, left, side, crnt + sticks[i], mask | msk)) return true;
        }

        return false;
    }

  public:
    bool makesquare(vector<int> &sticks) {
        const int sum = accumulate(begin(sticks), end(sticks), 0);
        if (sum % 4 != 0) return false;

        const int side = sum / 4;
        return find(sticks, 3, side, 0, 0);
    }
};
