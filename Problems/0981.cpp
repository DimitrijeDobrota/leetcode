class TimeMap {
    unordered_map<string, vector<pair<int, string>>> um;

  public:
    void set(const string &key, const string &value, int timestamp) {
        um[key].emplace_back(timestamp, value);
    }

    string get(const string &key, int timestamp) {
        const auto &vec = um[key];
        int low = 0, high = size(vec) - 1;
        string res = "";

        while (low <= high) {
            const auto mid = low + (high - low) / 2;

            if (vec[mid].first == timestamp) return vec[mid].second;
            if (vec[mid].first >= timestamp)
                high = mid - 1;
            else {
                res = vec[mid].second;
                low = mid + 1;
            }
        }

        return res;
    }
};
