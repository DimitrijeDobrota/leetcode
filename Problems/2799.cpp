class Solution {
  public:
    int countCompleteSubarrays(const vector<int> &nums) {
        static int count[10001];
        memset(count, 0x00, sizeof(count));

        int uniq = 0, res = 0, cnt = 0;
        ;
        for (const int n : nums)
            if (!count[n]) count[n] = 1, uniq++;
        for (int i = 0, left = 0; i < nums.size(); i++) {
            if (count[nums[i]]++ == 1) cnt++;
            while (cnt == uniq) {
                res += nums.size() - i;
                if (--count[nums[left++]] == 1) cnt--;
            }
        }
        return res;
    }
};
