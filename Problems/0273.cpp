class Solution {
    static string int_string(int n) {
        static const char *const below_20[] = {"One",     "Two",       "Three",    "Four",     "Five",
                                               "Six",     "Seven",     "Eight",    "Nine",     "Ten",
                                               "Eleven",  "Twelve",    "Thirteen", "Fourteen", "Fifteen",
                                               "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        static const char *const below_100[] = {"Twenty", "Thirty",  "Forty",  "Fifty",
                                                "Sixty",  "Seventy", "Eighty", "Ninety"};

        if (n >= 1000000000)
            return int_string(n / 1000000000) + " Billion" + int_string(n - 1000000000 * (n / 1000000000));
        else if (n >= 1000000)
            return int_string(n / 1000000) + " Million" + int_string(n - 1000000 * (n / 1000000));
        else if (n >= 1000)
            return int_string(n / 1000) + " Thousand" + int_string(n - 1000 * (n / 1000));
        else if (n >= 100)
            return int_string(n / 100) + " Hundred" + int_string(n - 100 * (n / 100));
        else if (n >= 20)
            return string(" ") + below_100[n / 10 - 2] + int_string(n - 10 * (n / 10));
        else if (n >= 1)
            return string(" ") + below_20[n - 1];

        return "";
    }

  public:
    string numberToWords(int num) const {
        if (num == 0) return "Zero";
        return int_string(num).substr(1);
    }
};
