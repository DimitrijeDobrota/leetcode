
class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) const {
        const int n = size(nums1), m = size(nums2);
        int i = 0, j = 0;
        vector<int> res;

        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        while (i < n && j < m) {
            if (nums1[i] == nums2[j]) {
                const int crnt = nums1[i];
                res.push_back(crnt);
                while (i < n && nums1[i] == crnt)
                    i++;
                while (j < m && nums2[j] == crnt)
                    j++;
            } else if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        return res;
    }
};

class Solution {
  public:
    vector<int> intersection(const vector<int> &nums1, const vector<int> &nums2) const {
        unordered_set<int> st(begin(nums1), end(nums1));
        vector<int> res;
        for (const int n : nums2) {
            if (st.erase(n)) res.push_back(n);
        }
        return res;
    }
};
