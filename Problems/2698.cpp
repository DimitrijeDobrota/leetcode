class Solution {
  public:
    bool canPartition(const string &s, const int target) {
        if (s == "" && target == 0) return true;
        if (target < 0) return false;

        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            left = left * 10 + s[i] - '0';
            if (canPartition(s.substr(i + 1), target - left)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            const int sqr = i * i;
            if (canPartition(to_string(sqr), i)) res += sqr;
        }
        return res;
    }
};
