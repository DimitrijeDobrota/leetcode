class Solution {
  public:
    string findDifferentBinaryString(const vector<string> &nums) {
        const unordered_set<string> us(begin(nums), end(nums));
        const int n = nums.size();

        for (int mask = 0, crnt = 0; mask < (1 << n); crnt = ++mask) {
            string s(n, '0');
            for (int i = n - 1; i >= 0; i--, crnt >>= 1)
                if (crnt & 1) s[i]++;
            if (!us.count(s)) return s;
        }
        return "";
    }
};
