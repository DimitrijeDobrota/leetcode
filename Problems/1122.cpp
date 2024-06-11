class Solution {
  public:
    vector<int> relativeSortArray(vector<int> &arr1, const vector<int> &arr2) const {
        const int n = size(arr2);
        unordered_map<int, int> um;

        for (int i = 0; i < n; i++)
            um[arr2[i]] = i;
        sort(begin(arr1), end(arr1), [&n, &um](int a, int b) {
            const auto [it1, _1] = um.emplace(a, n + a);
            const auto [it2, _2] = um.emplace(b, n + b);

            return it1->second < it2->second;
        });

        return arr1;
    }
};
