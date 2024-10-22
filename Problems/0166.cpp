class Solution {
  public:
    string fractionToDecimal(long long n, long long d) const {
        if (n == 0) return "0";
        string res;

        if (n < 0 ^ d < 0) res += '-';
        n = abs(n), d = abs(d);

        res += to_string(n / d);
        if ((n %= d) == 0) return res;
        res += '.';

        unordered_map<int, int> um;
        while (n) {
            if (um.count(n)) {
                res.insert(um[n], 1, '(');
                res += ')';
                break;
            }

            um[n] = size(res);

            n *= 10;
            res += to_string(n / d);
            n %= d;
        }

        return res;
    }
};
