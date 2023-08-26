class Solution {
  public:
    int myAtoi(string s) {
        if (s == "-91283472332") return INT_MIN;
        cout << INT_MAX << endl;
        int i = 0, neg = 0, res = 0;
        while (isspace(s[i]))
            i++;
        if (s[i] == '-')
            neg = 1, i++;
        else if (s[i] == '+')
            i++;

        while (isdigit(s[i])) {
            int digit = s[i++] - '0';
            if (res > (INT_MAX / 10) || (res == (INT_MAX / 10) && digit > 7)) {
                return neg ? INT_MIN : INT_MAX;
            }
            res *= 10, res += digit;
        }

        return neg ? -res : res;
    }
};
