class Solution {
  public:
    int largestOverlap(const vector<vector<int>> &img1, const vector<vector<int>> &img2) {
        const int n = img1.size();
        vector<int> one, two;
        unordered_map<int, int> count;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) one.push_back(i * 100 + j);
                if (img2[i][j]) two.push_back(i * 100 + j);
            }
        }

        for (int i : one)
            for (int j : two)
                count[i - j]++;

        int res = 0;
        for (auto it : count)
            res = max(res, it.second);
        return res;
    }
};
