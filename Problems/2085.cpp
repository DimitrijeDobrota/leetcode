class Solution {
public:
  int countWords(vector<string> &words1, vector<string> &words2) {
    unordered_map<string, int> um1, um2;

    for (auto &t : words1) um1[t]++;
    for (auto &t : words2) um2[t]++;

    int count = 0;
    for (auto &[str, cnt] : um1)
      if (cnt == 1 && um2[str] == 1) count++;
    return count;
  }
};
