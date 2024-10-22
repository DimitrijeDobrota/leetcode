class Solution {
  public:
    vector<vector<int>> getSkyline(const vector<vector<int>> &buildings) const {
        using type_t = tuple<int, int>;
        vector<type_t> vec;
        vec.reserve(2 * size(buildings) + 1);

        for (const auto &building : buildings) {
            vec.emplace_back(building[0], +building[2]);
            vec.emplace_back(building[1], -building[2]);
        }
        sort(begin(vec), end(vec));
        vec.emplace_back(-1, -1);

        multiset<int> st = {{0}};
        vector<vector<int>> res;
        for (int i = 0; i < size(vec) - 1; i++) {
            const auto [x, h] = vec[i];

            if (h > 0)
                st.insert(h);
            else
                st.extract(-h);

            if (x != get<0>(vec[i + 1])) {
                const int height = *st.rbegin(); // 0 will always be there
                if (res.empty() || res.back()[1] != height) res.push_back({x, height});
            }
        }

        return res;
    }
};
