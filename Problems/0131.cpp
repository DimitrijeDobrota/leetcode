// Backtracking
class Solution {
  vector<string> st;
  vector<vector<string>> res;

  bool valid(const string &s) {
    int i = 0, j = s.size() - 1;
    while (i < j)
      if (s[i++] != s[j--]) return false;
    return true;
  }

  void dfs(const string &s, int pos) {
    if (pos == s.size()) res.push_back(st);

    string crnt = "";
    for (int i = pos; i < s.size(); i++) {
      crnt += s[i];
      if (valid(crnt)) {
        st.push_back(crnt);
        dfs(s, i + 1);
        st.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s) {
    dfs(s, 0);
    return res;
  }
};

// Backtracking with DP
class Solution {
  vector<string> st;
  vector<vector<string>> res;

  void dfs(const string &s, int pos, vector<vector<bool>> &dp) {
    if (pos == s.size()) res.push_back(st);

    string crnt = "";
    for (int i = pos; i < s.size(); i++) {
      crnt += s[i];
      if (s[pos] == s[i] && (i - pos < 2 || dp[pos + 1][i - 1])) {
        dp[pos][i] = true;
        st.push_back(crnt);
        dfs(s, i + 1, dp);
        st.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    dfs(s, 0, dp);
    return res;
  }
};
