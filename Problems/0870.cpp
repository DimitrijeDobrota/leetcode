class Solution {
  public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
        static int indices[100001];
        const int n = size(nums1);

        sort(begin(nums1), end(nums1), greater<int>());

        iota(indices, indices + n, 0);
        sort(indices, indices + n, [&nums2](int a, int b) { return nums2[a] > nums2[b]; });

        int i = 0, j = 0, k = n - 1;
        vector<int> res(n);

        while (i <= k) {
            if (nums1[i] > nums2[indices[j]])
                res[indices[j++]] = nums1[i++];
            else
                res[indices[j++]] = nums1[k--];
        }

        return res;
    }
};
