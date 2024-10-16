class Solution {
    inline static string convert(int n) {
        if (n < 10) return '0' + to_string(n);
        return to_string(n);
    }

  public:
    vector<string> readBinaryWatch(int turnedOn) const {
        if (turnedOn == 0) return {"0:00"};

        vector<string> res;
        unsigned i = (1 << turnedOn) - 1, t;

        while (i < (1 << 10)) {
            const int hours = i >> 6, minutes = i & 0x3F;

            if (hours < 12 && minutes < 60) {
                res.push_back(to_string(hours) + ':' + convert(minutes));
            }

            const unsigned t = i | (i - 1);
            i = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(i) + 1));
        }

        return res;
    }
};
