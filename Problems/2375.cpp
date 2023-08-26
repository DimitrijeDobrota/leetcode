class Solution {
    string crnt = string(9, '#');

    int rec(const string &pattern, uint mask = 0, uint idx = 0) {
        if (idx == pattern.size() + 1) return 1;

        int start, end;
        if (!idx) {
            start = 1;
            end = 9;
        } else {
            if (pattern[idx - 1] == 'I') {
                start = (crnt[idx - 1] & 0xF) + 1;
                end = 9;
            } else {
                start = 1;
                end = (crnt[idx - 1] & 0xF) - 1;
            }
        }

        for (int i = start; i <= end; i++) {
            if (mask & (1 << i)) continue;
            crnt[idx] = '0' + i;
            if (rec(pattern, mask | (1 << i), idx + 1)) return 1;
        }
        return 0;
    }

  public:
    string smallestNumber(const string &pattern) {
        crnt.resize(pattern.size() + 1);
        rec(pattern);
        return crnt;
    }
};
