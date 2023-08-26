class Solution {
  public:
    string destCity(vector<vector<string>> &paths) {
        unordered_map<string, int> um;
        for (auto &path : paths) {
            um[path[0]]--;
            um[path[1]]++;
        }
        for (auto &[k, v] : um)
            if (v == 1) return k;
        return "";
    }
};
