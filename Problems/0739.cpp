class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temps) {
    stack<int> st({0});

    for (int i = 1; i < temps.size(); ++i) {
      while (!st.empty() && temps[i] > temps[st.top()]) {
        temps[st.top()] = i - st.top();
        st.pop();
      }
      st.push(i);
    }

    while (!st.empty()) {
      temps[st.top()] = 0;
      st.pop();
    }
    return temps;
  }
};
