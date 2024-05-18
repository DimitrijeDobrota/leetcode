class Solution {
    using array_t = array<pair<int, int>, 26>;
    static constexpr const array_t lookup = []() constexpr -> array_t {
        array_t res;

        for (int i = 0; i < 26; i++)
            res[i] = {i / 5, i % 5};

        return res;
    }();

  public:
    string alphabetBoardPath(const string &target) const {
        int x = 0, y = 0;
        string res;

        for (const char c : target) {
            const auto [i, j] = lookup[c - 'a'];

            if (j < y) res += string(y - j, 'L');
            if (i < x) res += string(x - i, 'U');
            if (i > x) res += string(i - x, 'D');
            if (j > y) res += string(j - y, 'R');

            res += '!';
            x = i, y = j;
        }

        return res;
    }
};
