class Solution {
    static int count[16][27];
    mutable array<int, 26> crnt{0};

    int rec(const int n, const int idx = 0, const int score = 0) const {
        if (idx == n) return score;

        int res = rec(n, idx + 1, score);
        auto back = crnt;
        for (int i = idx; i < n; i++) {
            bool valid = true;
            for (int j = 0; j < 26; j++) {
                crnt[j] += count[i][j];
                if (crnt[j] > count[n][j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) res = max(res, rec(n, i + 1, score + count[i][26]));
            crnt = back;
        }

        return res;
    }

  public:
    int maxScoreWords(const vector<string> &words, const vector<char> &letters,
                      const vector<int> &score) const {
        memset(count, 0x00, sizeof(count));

        const int n = size(words);
        for (int i = 0; i < n; i++) {
            for (const char c : words[i]) {
                const int idx = c - 'a';
                count[i][26] += score[idx];
                count[i][idx]++;
            }
        }

        for (const char c : letters) {
            const int idx = c - 'a';
            count[n][26] += score[idx];
            count[n][idx]++;
        }

        return rec(n);
    }
};

int Solution::count[16][27];
