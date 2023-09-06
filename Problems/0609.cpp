#pragma GCC optimize("fast")
static auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
  public:
    vector<vector<string>> findDuplicate(const vector<string> &paths) {
        unordered_map<string, vector<string>> um;
        vector<vector<string>> res;

        string path, file;
        for (const string &entry : paths) {
            stringstream ss(entry);
            ss >> path;
            path += '/';
            while (ss >> file) {
                int idx = file.find('(');
                um[file.substr(idx)].push_back(path + file.substr(0, idx));
            }
        }

        for (const auto &[_, v] : um)
            if (v.size() > 1) res.push_back(v);
        return res;
    }
};
