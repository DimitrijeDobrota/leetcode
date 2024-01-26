class Solution {
  public:
    int findLeastNumOfUniqueInts(const vector<int> &arr, int k) const {
        unordered_map<int, int> um;
        for (const int n : arr)
            um[n]++;

        static int count[100001];
        size_t sz = 0;
        for (const auto [_, cnt] : um)
            count[sz++] = cnt;

        sort(begin(count), begin(count) + sz);
        for (int i = 0; i < sz; i++) {
            k -= count[i];
            if (k < 0) return sz - i;
        }

        return 0;
    }
};
