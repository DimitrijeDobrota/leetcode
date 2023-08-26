class Solution {
  public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int maxi = 0;
        int cnt = 0;

        for (int i : nums)
            if (i)
                maxi = max(maxi, ++cnt);
            else
                cnt = 0;

        return maxi;
    }
};
