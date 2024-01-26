class Solution {
    typedef array<int, 10001> record;
    static constexpr const record cache = []() constexpr {
        record res = {0};
        int cnt = 0;
        for (int i = 1; i < size(res); i++) {
            int crnt = i, mirror = 1;
            do {
                const int digit = crnt % 10;
                if (digit == 3 || digit == 4 || digit == 7) {
                    mirror = 1;
                    break;
                }
                if (digit != 0 && digit != 1 && digit != 8) mirror = 0;
            } while ((crnt /= 10) > 0);
            if (!mirror) cnt++;
            res[i] = cnt;
        }
        return res;
    }();

  public:
    constexpr int rotatedDigits(int n) const { return cache[n]; }
};
