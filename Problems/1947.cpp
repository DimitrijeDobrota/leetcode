class Solution {
  public:
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors) {
        const int n = students.size(), m = students[0].size();
        uint16_t student[9] = {0}, mentor[9] = {0};

        for (uint8_t i = 0; i < n; i++) {
            for (const int n : students[i])
                student[i] = (student[i] | n) << 1;
            for (const int n : mentors[i])
                mentor[i] = (mentor[i] | n) << 1;
        }

        uint8_t res = 0;
        vector<uint8_t> idx(n);
        iota(begin(idx), end(idx), 0);
        do {
            uint8_t count = 0;
            for (uint8_t i = 0; i < n; i++) {
                count += m - __builtin_popcount(student[i] ^ mentor[idx[i]]);
            }
            res = max(res, count);
        } while (next_permutation(begin(idx), end(idx)));

        return res;
    }
};
