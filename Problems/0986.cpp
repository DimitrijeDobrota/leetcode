class Solution {
  public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                             vector<vector<int>> &secondList) {
        vector<vector<int>> res;

        int n = firstList.size(), m = secondList.size(), i = 0, j = 0;
        while (i < n && j < m) {
            const vector<int> &a = firstList[i], b = secondList[j];
            if (a[1] < b[0])
                i++;
            else if (a[0] > b[1])
                j++;
            else {
                res.push_back({max(a[0], b[0]), min(a[1], b[1])});
                if (a[1] < b[1])
                    i++;
                else
                    j++;
            }
        }

        return res;
    }
};
