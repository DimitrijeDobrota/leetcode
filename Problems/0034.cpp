class Solution {
    int binary_search_left(const vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }

    int binary_search_right(const vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }

  public:
    vector<int> searchRange(const vector<int> &nums, const int target) {
        const int low = binary_search_left(nums, target);
        if (low >= nums.size() || nums[low] != target) return {-1, -1};
        const int high = binary_search_right(nums, target);
        return {low, high};
    }
};
