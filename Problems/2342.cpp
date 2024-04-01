class Solution {
    static int sum_digits(int n) {
        int res = 0;
        while (n)
            res += n % 10, n /= 10;
        return res;
    }

  public:
    int maximumSum(const vector<int> &nums) const {
        static int um[82];
        int res = -1;

        memset(um, 0x00, sizeof(um));
        for (const int num : nums) {
            const int sum = sum_digits(num);
            if (um[sum])
                res = max(res, num + um[sum]), um[sum] = max(um[sum], num);
            else
                um[sum] = num;
        }

        return res;
    }
};
