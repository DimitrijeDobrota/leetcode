class Solution {
    static int left[101][26];
    static int right[101][26];
    static int dp[101][101];

    int rec(const string &ring, const string &key, int idx, int crnt) {
        if (idx == size(key)) return 0;

        if (key[idx] == ring[crnt]) return 1 + rec(ring, key, idx + 1, crnt);
        if (dp[idx][crnt] != -1) return dp[idx][crnt];

        const int n = size(ring);
        const int l = left[crnt][key[idx] - 'a'];
        const int r = right[crnt][key[idx] - 'a'];

        return dp[idx][crnt] = 1 + min(l + rec(ring, key, idx + 1, (crnt - l + n) % n),
                                       r + rec(ring, key, idx + 1, (crnt + r) % n));
    }

  public:
    int findRotateSteps(const string &ring, const string &key) {
        const int n = size(ring);

        memset(dp, 0xFF, sizeof(dp));
        memset(left, 0x00, sizeof(left));
        memset(right, 0x00, sizeof(right));

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                const int x = ring[(i + j) % n] - 'a';
                const int y = ring[(i + n - j) % n] - 'a';

                if (!right[i][x]) right[i][x] = j;
                if (!left[i][y]) left[i][y] = j;
            }
        }

        return rec(ring, key, 0, 0);
    }
};

int Solution::left[101][26];
int Solution::right[101][26];
int Solution::dp[101][101];
