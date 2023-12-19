class Solution {
  public:
    int calculate(const string &s) const {
        int res = 0;
        vector<int> signs(2, 1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0') {
                int number = 0;
                while (i < s.size() && isdigit(s[i])) {
                    number = 10 * number + (s[i++] - '0');
                }
                res += signs.back() * number;
                signs.pop_back();
                i--;
            } else if (s[i] == '(' && s[i + 1] == '-') {
            } else if (s[i] == ')')
                signs.pop_back();
            else if (s[i] != ' ')
                signs.push_back(signs.back() * (s[i] == '-' ? -1 : 1));
        }
        return res;
    }
};
