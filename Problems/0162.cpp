class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;

        for(int i=0; i<n-1; ) {
          if(nums[i]>nums[i+1]) return i;
          i+=2;
          if(i>=n) break;
          if(nums[i-1]>nums[i]) return i-1;
        }
        if(nums[n-1]>nums[n-2]) return n-1;

        return -1;
    }
};
