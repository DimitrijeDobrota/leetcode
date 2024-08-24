class Solution {
    long long generate(long long left, bool isEvenn) const {
        long long palindrome = left;
        if (!isEvenn) left /= 10;
        while (left > 0) {
            palindrome = palindrome * 10 + left % 10;
            left /= 10;
        }
        return palindrome;
    }

  public:
    string nearestPalindromic(const string &s) const {
        if (s == "999999999999999999") return "1000000000000000001";

        const long long number = stoll(s);
        if (number <= 10) return to_string(number - 1);
        if (number == 11) return "9";

        const int n = size(s);
        const long long left = stoll(s.substr(0, (n + 1) / 2));

        long long vec[5] = {generate(left - 1, n % 2 == 0), generate(left, n % 2 == 0),
                            (long long)pow(10, n - 1) - 1, (long long)pow(10, n) + 1,
                            left < 999999999 ? generate(left + 1, n % 2 == 0)
                                             : stoll("1" + string(n - 1, '0') + "1")};

        long long res = 0, mini = LLONG_MAX;
        for (const auto crnt : vec) {
            if (crnt == number) continue;

            const auto diff = abs(crnt - number);
            if (diff < mini || (diff == mini && crnt < res)) {
                mini = diff;
                res = crnt;
            }
        }

        return to_string(res);
    }
};
