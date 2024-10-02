class Solution {
  public:
    vector<int> arrayRankTransform(const vector<int> &arr) const {
        const int n = size(arr);
        vector<pair<int, int>> vec(n);
        vector<int> ans(n);

        for (int i = 0; int x : arr)
            vec[i++] = {x, i};
        sort(begin(vec), end(vec));

        int curr = 0, prev = INT_MIN;
        for (const auto &[x, i] : vec) {
            if (x > prev) curr++;
            ans[i] = curr;
            prev = x;
        }

        return ans;
    }
};
