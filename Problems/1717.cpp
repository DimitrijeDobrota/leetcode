class Solution {
  public:
    int maximumGain(const string s, int x, int y) const {
        int res = 0, a = 0, b = 0, mini = min(x, y);

        for (const char c : s) {
            if (c > 'b') {
                res += min(a, b) * mini;
                a = b = 0;
                continue;
            }

            if (c == 'a') {
                if (x < y && b > 0)
                    b--, res += y;
                else
                    a++;
            } else {
                if (x > y && a > 0)
                    a--, res += x;
                else
                    b++;
            }
        }

        return res + min(a, b) * mini;
    }
};
