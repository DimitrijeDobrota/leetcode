class Solution {
  int binary_search(const vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;
    while(low<=high){
      int mid = low + (high-low)/2;
      if(nums[mid]==target) return mid;
      else if(nums[mid]>target) high = mid-1;
      else low = mid + 1;
    }
    return -1;
  }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low, high;
        low = high = binary_search(nums, target);
        while(low-1>=0 && nums[low-1] == target) low--;
        while(high+1<nums.size() && nums[high+1] == target) high++;
        return {low, high};
    }
};
