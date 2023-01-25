class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
      left[i] = i;
      while (!st.empty() && heights[st.top()] >= heights[i]) {
        left[i] = left[st.top()];
        st.pop();
      };
      st.push(i);
    }

    for (int i = n - 1; i >= 0; i--) {
      right[i] = i;
      while (!st.empty() && heights[st.top()] >= heights[i]) {
        right[i] = right[st.top()];
        st.pop();
      };
      st.push(i);
    }

    int res = 0;
    for (int i = 0; i < n; i++)
      res = max(res, (right[i] - left[i] + 1) * heights[i]);
    return res;
  }
};
