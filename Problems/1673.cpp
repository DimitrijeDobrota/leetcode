class Solution {
  public:
    vector<int> mostCompetitive(const vector<int> &nums, int k) const {
        vector<int> st;
        st.reserve(k);

        for (int i = 0; i < size(nums); i++) {
            while (!st.empty() && k - size(st) < size(nums) - i && st.back() > nums[i])
                st.pop_back();
            if (size(st) < k) st.push_back(nums[i]);
        }

        return st;
    }
};
