class Solution {
    int len(const string &s, const int sa, const int sb, vector<vector<int>> &mem) {
        if (mem[sa][sb]) return mem[sa][sb];

        int res = 0, a = sa, b = sb;
        while (a < b) {
            if (s[a] == s[b])
                a++, b--, res += 2;
            else {
                res += max(len(s, a + 1, b, mem), len(s, a, b - 1, mem));
                break;
            }
        }
        if (a == b) res++;
        mem[sa][sb] = res;
        return res;
    }

  public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> mem(n, vector<int>(n));
        return len(s, 0, n - 1, mem);
    }
};
