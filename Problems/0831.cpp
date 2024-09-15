class Solution {
  public:
    string maskPII(string &s) const {
        const auto at = s.find('@');
        string res;

        if (at != string::npos) {
            res += tolower(s[0]);
            res += "*****";
            res += tolower(s[at - 1]);
            for (int i = at; i < size(s); i++)
                res += tolower(s[i]);
        } else {
            int digits = 0;
            for (const char c : s)
                digits += isdigit(c);

            if (digits == 10)
                res += "***-***-";
            else if (digits == 11)
                res += "+*-***-***-";
            else if (digits == 12)
                res += "+**-***-***-";
            else if (digits == 13)
                res += "+***-***-***-";

            string extra;
            for (int i = size(s) - 1; size(extra) < 4; i--) {
                if (!isdigit(s[i])) continue;
                extra = s[i] + extra;
            }

            res += extra;
        }

        return res;
    }
};
