class Solution {
  public:
    long long smallestNumber(long long num) {
        static uint8_t digits[16];
        bool neg = false;
        uint8_t cnt = 0;

        if (num < 0) {
            num = -num;
            neg = true;
        }

        do {
            digits[cnt++] = num % 10;
        } while ((num /= 10) > 0);

        if (neg)
            sort(begin(digits), begin(digits) + cnt, greater());
        else {
            sort(begin(digits), begin(digits) + cnt);
            for (int i = 0; i < cnt; i++) {
                if (digits[i] == 0) continue;
                swap(digits[0], digits[i]);
                break;
            }
        }

        num = 0;
        for (int i = 0; i < cnt; i++)
            num = (num * 10) + digits[i];
        return !neg ? num : -num;
    }
};
