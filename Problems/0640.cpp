class Solution {
    static pair<int, int> count(const string_view &s) {
        int x = 0, nums = 0, sign = 1;
        for (int i = 0; i < size(s); i++) {
            if (s[i] == '+')
                sign = 1;
            else if (s[i] == '-')
                sign = -1;
            else {
                int num = s[i] == 'x' ? 1 : 0;
                while (isdigit(s[i]))
                    num = num * 10 + s[i++] - '0';
                if (s[i] == 'x')
                    x += sign * num;
                else
                    nums += sign * num, i--;
            }
        }

        return {x, nums};
    }

  public:
    string solveEquation(const string &equation) const {
        const string_view sv(equation);
        const auto it = sv.find('=');

        const auto [lx, ln] = count({begin(sv), it});
        const auto [rx, rn] = count(sv.substr(it + 1));

        if (lx == rx) return ln == rn ? "Infinite solutions" : "No solution";
        return "x=" + to_string((rn - ln) / (lx - rx));
    }
};
