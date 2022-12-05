class Solution {
  bool mutation(const string &s1, const string &s2) {
    int cnt = 0;
    for (int i = 0; i < size(s1); i++)
      if (s1[i] != s2[i]) cnt++;
    return cnt == 1;
  }

public:
  int minMutation(string startGene, string endGene, vector<string> &bank) {
    /* unordered_map<string, vector<string>> um; */

    /* if (find(bank.begin(), bank.end(), startGene) == bank.end()) */
    /*   bank.push_back(startGene); */

    /* for (int i = 0; i < size(bank); i++) { */
    /*   for (int j = i + 1; j < size(bank); j++) */
    /*     if (mutation(bank[i], bank[j])) { */
    /*       um[bank[i]].push_back(bank[j]); */
    /*       um[bank[j]].push_back(bank[i]); */
    /*     } */
    /* } */

    int mini = INT_MAX;
    unordered_set<string> visited;
    queue<pair<string, int>> st;
    st.push({startGene, 0});
    while (!st.empty()) {
      string root = st.front().first;
      int count = st.front().second;
      st.pop();
      visited.insert(root);
      if (root == endGene) return count;
      /* for (string &s : um[root]) */
      /*   if (visited.find(s) == visited.end()) st.push({s, count + 1}); */
      for (string &s : bank)
        if (visited.find(s) == visited.end() && mutation(root, s))
          st.push({s, count + 1});
    }
    return -1;
  }
};
