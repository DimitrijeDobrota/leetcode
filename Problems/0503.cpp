class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    vector<int> res(nums.size(), -1);
    stack<int> st;

    for (int i = 0; i < nums.size(); i++) {
      while (!st.empty() && nums[i] > nums[st.top()]) {
        res[st.top()] = nums[i];
        st.pop();
      }
      st.push(i);
    }

    for (int i = 0; !st.empty() && i < nums.size(); i++) {
      while (!st.empty() && nums[i] > nums[st.top()]) {
        res[st.top()] = nums[i];
        st.pop();
      }
    }

    return res;
  }
};
