class Solution {
  public:
    vector<int> countOfPairs(int n, int x, int y) const {
        vector<int> res(n);

        x--, y--;
        if (x > y) swap(x, y);
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                const int dist = min(abs(i - j), abs(i - x) + abs(j - y) + 1);
                res[dist - 1] += 2;
            }
        }

        return res;
    }
};
