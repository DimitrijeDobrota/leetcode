class Solution {
public:
  int partitionString(string s) {
    bitset<26> st;
    int res = 0;
    for (char c : s) {
      int n = c - 'a';
      if (!st[n])
        st.set(n);
      else {
        res++;
        st.reset();
        st.set(n);
      }
    }
    return res + 1;
  }
};
