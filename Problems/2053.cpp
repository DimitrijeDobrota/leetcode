class Solution {
  public:
    string kthDistinct(const vector<string> &arr, int k) const {
        unordered_map<string, int> um;

        for (const auto &s : arr)
            um[s]++;
        for (const auto &s : arr) {
            if (um[s] > 1) continue;
            if (!--k) return s;
        }

        return "";
    }
};
