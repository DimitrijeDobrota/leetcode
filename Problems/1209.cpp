class Solution {
public:
  string removeDuplicates(string s, int k) {
    stack<pair<char, int>> st;
    for (char c : s)
      if (!st.empty() && st.top().first == c) {
        if (++st.top().second == k) st.pop();
      } else
        st.push(make_pair(c, 1));

    string res = "";
    while (!st.empty()) {
      res += string(st.top().second, st.top().first);
      st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
