class Solution {
  public:
    int countLatticePoints(vector<vector<int>> &circles) {
        unordered_set<int> us;

        for (const auto &circle : circles) {
            for (int i = circle[0] - circle[2]; i <= circle[0] + circle[2]; i++) {
                for (int j = circle[1] - circle[2]; j <= circle[1] + circle[2]; j++) {
                    const int a = (i - circle[0]) * (i - circle[0]);
                    const int b = (j - circle[1]) * (j - circle[1]);
                    const int c = circle[2] * circle[2];

                    if (a + b <= c) us.insert(i * 200 + j);
                }
            }
        }

        return size(us);
    }
};
