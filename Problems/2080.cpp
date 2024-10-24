class RangeFreqQuery {
    unordered_map<int, vector<int>> um;

  public:
    RangeFreqQuery(const vector<int> &arr) {
        for (int i = 0; i < size(arr); i++) {
            um[arr[i]].push_back(i);
        };
    }

    int query(int left, int right, int value) const {
        const auto it = um.find(value);

        static const vector<int> dummy;
        const auto &vec = it != end(um) ? it->second : dummy;

        return distance(lower_bound(begin(vec), end(vec), left), upper_bound(begin(vec), end(vec), right));
    }
};
