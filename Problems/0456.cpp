class Solution {
  public:
    bool find132pattern(const vector<int> &nums) {
        int n3 = INT_MIN;
        stack<int> st;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < n3) return true;
            while (!st.empty() && st.top() < nums[i]) {
                n3 = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
