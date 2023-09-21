class Solution {
    int atMost(const vector<int> &nums, int k) {
        static int seen[20001] = {0};
        memset(seen, 0x00, sizeof(seen));

        int res = 0, j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!seen[nums[i]]++) k--;
            while (k < 0)
                if (!--seen[nums[j++]]) k++;
            res += i - j + 1;
        }
        return res;
    }

  public:
    int subarraysWithKDistinct(const vector<int> &nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
