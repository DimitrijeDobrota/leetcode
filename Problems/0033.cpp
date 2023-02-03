class Solution {
  int binary_search(const vector<int>& nums, int target, int low, int high) {
    while(low<=high){
      int mid = low + (high-low)/2;
      if(nums[mid]==target) return mid;
      else if(nums[mid]>target) high = mid-1;
      else low = mid + 1;
    }
    return -1;
  }
public:
    int search(vector<int>& nums, int target) {
      int pivot = -1;
      for(int i=0; i<nums.size()-1; i++) {
        if(nums[i] > nums[i+1]) {
          pivot = i;
          break;
        }
      }
      if(pivot==-1) return binary_search(nums, target, 0, nums.size()-1);
      if(nums[0]<=target) return binary_search(nums, target, 0, pivot);
      else return binary_search(nums, target, pivot+1, nums.size()-1);
    }
};
