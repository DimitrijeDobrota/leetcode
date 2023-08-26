class Solution {
  public:
    int nextGreaterElement(int n) {
        string nums = to_string(n);

        int prev = 0;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (!st.empty() && nums[i] < nums[st.top()]) {
                while (!st.empty() && nums[i] < nums[st.top()]) {
                    prev = st.top();
                    st.pop();
                }
                swap(nums[i], nums[prev]);
                reverse(nums.begin() + i + 1, nums.end());
                break;
            }
            st.push(i);
        }

        long long res = stoll(nums);
        return (res > INT_MAX || (int)res == n) ? -1 : (int)res;
    }
};
