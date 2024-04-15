class Solution {
  public:
    int minRectanglesToCoverPoints(const vector<vector<int>> &points, int w) const {
        set<int> st;

        for (const auto &point : points)
            st.insert(point[0]);
        if (w == 0) return size(st);

        int res = 1, prev = *st.begin();

        while (true) {
            auto it = st.upper_bound(prev + w);
            if (it == st.end()) break;
            prev = *it;
            res++;
        }

        return res;
    }
};
