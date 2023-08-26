class SnapshotArray {
    vector<vector<pair<int, int>>> diffs;
    int id = 0;

  public:
    SnapshotArray(int length) : diffs(length, {{0, 0}}), id() {}
    int snap() { return id++; }

    void set(int index, int val) {
        if (diffs[index].back().first != id)
            diffs[index].push_back({id, val});
        else
            diffs[index].back().second = val;
    }

    int get(int index, int snap_id) {
        const vector<pair<int, int>> &vec = diffs[index];
        int low = 0, high = vec.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid].first == snap_id)
                return vec[mid].second;
            else if (vec[mid].first < snap_id)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return diffs[index][high].second;
    }
};
