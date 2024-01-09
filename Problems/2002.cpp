class Solution {
    static int len(const string &s) { return len(s, 0, size(s) - 1); }
    static int len(const string &s, int i, int j) {
        int cnt = 0, maxi = 0;
        while (i < j) {
            if (s[i] == s[j])
                cnt += 2, i++, j--;
            else
                maxi = max(maxi, cnt + len(s, i + 1, j--));
        }
        return max(maxi, cnt + (i == j));
    }

  public:
    int maxProduct(const string &s) const {
        int res = 0;
        for (int mask = 0; mask < 1 << size(s); mask++) {
            string first, second;
            for (int crnt = mask, idx = 0; crnt; crnt >>= 1, idx++) {
                (crnt & 1 ? first : second) += s[idx];
            }
            res = max(res, len(first) * len(second));
        }
        return res;
    }
};
