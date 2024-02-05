class Solution {
  public:
    int minOperations(vector<int> &nums1, vector<int> &nums2) const {
        int n = size(nums1), m = size(nums2);
        if (6 * n < m || 6 * m < n) return -1;

        const int s1 = accumulate(begin(nums1), end(nums1), 0);
        const int s2 = accumulate(begin(nums2), end(nums2), 0);

        if (s1 > s2) swap(nums1, nums2), swap(n, m);

        make_heap(begin(nums1), end(nums1), greater<int>());
        make_heap(begin(nums2), end(nums2), less<int>());

        int goal = abs(s1 - s2), res = 0;
        while (goal > 0 && !empty(nums1) && !empty(nums2)) {
            res++;
            if (6 - nums1.front() > nums2.front() - 1) {
                goal -= 6 - nums1.front();
                pop_heap(begin(nums1), end(nums1), greater<int>());
                nums1.pop_back();
            } else {
                goal -= nums2.front() - 1;
                pop_heap(begin(nums2), end(nums2), less<int>());
                nums2.pop_back();
            }
        }

        while (goal > 0 && !empty(nums1)) {
            goal -= 6 - nums1.front();
            pop_heap(begin(nums1), end(nums1), greater<int>());
            nums1.pop_back();
            res++;
        }

        while (goal > 0 && !empty(nums2)) {
            goal -= nums2.front() - 1;
            pop_heap(begin(nums2), end(nums2), less<int>());
            nums2.pop_back();
            res++;
        }

        return goal <= 0 ? res : -1;
    }
};
