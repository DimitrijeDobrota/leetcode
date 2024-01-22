class Solution {
  public:
    int smallestDivisor(const vector<int> &nums, int threshold) const {
        int left = 1, right = 1000000;
        while (left < right) {
            int mid = left + (right - left) / 2, sum = 0;
            for (const int num : nums)
                sum += (num + mid - 1) / mid;
            if (sum > threshold)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
