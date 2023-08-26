// Concise way

class Solution {
    long dp[1001] = {1, 0};

  public:
    int numWays(const vector<string> &words, const string &target) {
        int n = target.length(), mod = 1e9 + 7;
        for (int i = 0; i < words[0].length(); ++i) {
            vector<int> count(26);
            for (const auto &w : words)
                count[w[i] - 'a']++;
            for (int j = n - 1; j >= 0; --j)
                dp[j + 1] += (dp[j] * count[target[j] - 'a']) % mod;
        }
        return dp[n] % mod;
    }
};

// Relatively dump way
class Solution {
    int dp[1001][1001] = {0};
    int count[1001][26] = {0};
    int mod = 1E9 + 7;

    int rec(const vector<string> &words, const string &target, int k = 0, int l = 0) {
        if (k >= target.size()) return 1;
        if (l >= words[0].size()) return 0;
        if (dp[k][l] != -1) return dp[k][l];

        long long res = rec(words, target, k, l + 1);
        res += ((long long)count[l][target[k] - 'a'] * rec(words, target, k + 1, l + 1)) % mod;
        return dp[k][l] = res % mod;
    }

  public:
    int numWays(const vector<string> &words, const string &target) {
        memset(dp, 0xFF, 1001 * 1001 * sizeof(int)); // init dp to -1
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words[i].size(); j++)
                count[j][words[i][j] - 'a']++;

        return rec(words, target, 0, 0);
    }
};
