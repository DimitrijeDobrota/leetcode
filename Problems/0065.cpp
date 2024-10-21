class Solution {
    using it_t = string::const_iterator;

    static bool validSign(it_t &pos, const it_t &end) {
        if (*pos == '-' || *pos == '+') {
            pos++;
            if (find(pos, end, '-') != end || find(pos, end, '+') != end) {
                return false;
            }
        }

        return pos != end;
    }

    static bool validDigit(const it_t &pos, const it_t &end) {
        return all_of(pos, end, [](char c) { return isdigit(c); });
    }

    static bool isDecimal(const string &s) {
        auto pos = begin(s);

        if (!validSign(pos, end(s))) return false;
        if (string(pos, end(s)) == ".") return false;

        auto dot = find(pos, end(s), '.');
        return validDigit(pos, dot) && validDigit(dot + 1, end(s));
    }

    static bool isInteger(const string &s) {
        auto pos = begin(s);
        if (!validSign(pos, end(s))) return false;
        return validDigit(pos, end(s));
    }

  public:
    bool isNumber(const string &s) const {
        auto e = s.find('e'), E = s.find('E');

        if (E != string::npos) swap(e, E);
        if (e != string::npos) {
            const string first = s.substr(0, e);
            const string second = s.substr(e + 1);
            return !first.empty() && !second.empty() && isInteger(second) &&
                   (isDecimal(first) || isInteger(first));
        }

        return isDecimal(s) || isInteger(s);
    }
};
