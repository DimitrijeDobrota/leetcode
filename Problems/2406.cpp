class Solution {
  public:
    int minGroups(vector<vector<int>> &intervals) const {
        static int start[1000001], end[1000001];
        int res = 1;

        memset(end, 0x00, sizeof(end));
        memset(start, 0x00, sizeof(start));

        for (const auto &inter : intervals) {
            start[inter[0]]++;
            end[inter[1]]++;
        }

        for (int i = 1, acc = 0; i <= 1000000; i++) {
            acc += start[i];
            res = max(res, acc);
            acc -= end[i];
        }

        return res;
    }
};
