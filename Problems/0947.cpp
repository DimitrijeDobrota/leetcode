class Solution {
public:
  int removeStones(vector<vector<int>> &stones) {
    unordered_map<int, vector<int>> rows, cols;
    unordered_set<int> seen;

    for (int s = 0; s < size(stones); ++s)
      rows[stones[s][0]].push_back(s), cols[stones[s][1]].push_back(s);

    int c = 0;
    stack<int> st;
    for (int s = 0; s < size(stones); ++s) {
      if (seen.count(s)) continue;
      st.push(s);
      while (!st.empty()) {
        int s = st.top();
        st.pop();
        if (seen.count(s)) continue;
        seen.insert(s);
        int r = stones[s][0], c = stones[s][1];
        for (auto ss : rows[r])
          if (!seen.count(ss)) st.push(ss);
        for (auto ss : cols[c])
          if (!seen.count(ss)) st.push(ss);
      }
      c++;
    }

    return size(stones) - c;
  }
};
