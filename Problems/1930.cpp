class Solution {
  public:
    int countPalindromicSubsequence(const string &s) const {
        static pair<int, int> pos[27];
        memset(pos, 0xFF, sizeof(pos));

        const int n = s.size();
        for (int i = 0; i < n; i++) {
            const int idx = s[i] & 0x1F;
            if (pos[idx].first == -1) pos[idx].first = i;
            pos[idx].second = i;
        }

        int res = 0;
        for (int i = 1; i <= 26; i++) {
            const auto [first, last] = pos[i];
            if (first == -1) continue;
            bitset<27> bs;
            for (int j = first + 1; j < last; j++)
                bs.set(s[j] & 0x1F);
            res += bs.count();
        }
        return res;
    }
};

// Improve constant factor by using a lot of memory
class Solution {
  public:
    int countPalindromicSubsequence(const string &s) const {
        static int count[100001][27];
        memset(count, 0x00, sizeof(int) * 27);

        static pair<int, int> pos[27];
        memset(pos, 0xFF, sizeof(pos));

        const int n = s.size();
        for (int i = 0; i < n; i++) {
            const int idx = s[i] & 0x1F;
            if (i != 0) memcpy(count[i], count[i - 1], sizeof(int) * 27);
            count[i][idx]++;

            if (pos[idx].first == -1) pos[idx].first = i;
            pos[idx].second = i;
        }

        int res = 0;
        for (int i = 1; i <= 26; i++) {
            const auto [first, last] = pos[i];
            if (first == -1) continue;

            count[last][i]--;
            for (int j = 1; j <= 26; j++) {
                res += count[last][j] > count[first][j];
            }
            count[last][i]++;
        }

        return res;
    }
};
