class Solution {
  public:
    vector<int> relocateMarbles(const vector<int> &nums, const vector<int> &moveFrom,
                                const vector<int> &moveTo) const {
        unordered_map<int, int> um;
        vector<int> res;

        for (const int num : nums)
            um[num]++;
        for (int i = 0; i < size(moveFrom); i++) {
            if (moveTo[i] == moveFrom[i]) continue;
            um[moveTo[i]] += um[moveFrom[i]];
            um[moveFrom[i]] = 0;
        }

        for (const auto [k, v] : um)
            if (v) res.push_back(k);
        sort(begin(res), end(res));

        return res;
    }
};
