class Solution {
  public:
    vector<int> smallestRange(const vector<vector<int>> &nums) const {
        using ti = tuple<int, int, int>;
        priority_queue<ti, vector<ti>, greater<ti>> pq;
        int maxi = -1;

        for (int i = 0; i < size(nums); i++) {
            pq.emplace(nums[i][0], i, 0);
            maxi = max(maxi, nums[i][0]);
        }

        vector<int> res = {0, INT_MAX};
        while (!pq.empty()) {
            const auto [mini, list, elem] = pq.top();
            pq.pop();

            if (maxi - mini < res[1] - res[0]) res = {mini, maxi};
            if (elem + 1 == size(nums[list])) break;

            const int next = nums[list][elem + 1];
            pq.emplace(next, list, elem + 1);
            maxi = max(maxi, next);
        }

        return res;
    }
};
