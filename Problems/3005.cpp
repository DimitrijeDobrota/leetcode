class Solution {
  public:
    int maxFrequencyElements(const vector<int> &nums) const {
        static int count[101];
        memset(count, 0x00, sizeof(count));

        for (const int n : nums)
            count[n]++;

        int res = 0, maxi = 0;
        for (int i = 0; i <= 100; i++) {
            if (count[i] == maxi) res += count[i];
            if (count[i] > maxi) res = maxi = count[i];
        }
        return res;
    }
};
