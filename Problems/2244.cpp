class Solution {
  public:
    int minimumRounds(vector<int> &tasks) {
        unordered_map<int, int> um;
        for (int t : tasks)
            um[t]++;

        int round = 0;
        for (auto [_, c] : um) {
            if (c == 1) return -1;
            round += (c - 1) / 3 + 1;
        }
        return round;
    }
};
