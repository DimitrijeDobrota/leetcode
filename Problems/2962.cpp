class Solution {
  public:
    long long countSubarrays(const vector<int> &nums, int k) const {
        int maxi = *max_element(begin(nums), end(nums));
        long long res = 0;

        for (int i = 0, j = 0, crnt = 0; j < size(nums); j++) {
            if (nums[j] == maxi) crnt++;
            while (crnt >= k)
                if (nums[i++] == maxi) crnt--;
            res += i;
        }

        return res;
    }
};
