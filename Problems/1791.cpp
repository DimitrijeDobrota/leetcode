class Solution {
  public:
    int findCenter(vector<vector<int>> &edges) {
        unordered_set<int> us;

        for (auto &p : edges) {
            if (us.count(p[0]))
                return p[0];
            else
                us.insert(p[0]);
            if (us.count(p[1]))
                return p[1];
            else
                us.insert(p[1]);
        }
        return -1;
    }
};
