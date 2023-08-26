// DP, O(n^2)
class Solution {
  public:
    int findLongestChain(vector<vector<int>> &pairs) {
        sort(begin(pairs), end(pairs));
        const int n = pairs.size();
        int res = 1, count[1001] = {0};
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (pairs[i][1] < pairs[j][0]) count[i] = max(count[i], count[j]);
            }
            res = max(res, ++count[i]);
        }

        return res;
    }
};

// Greedy, O(nlogn)
class Solution {
  public:
    int findLongestChain(vector<vector<int>> &pairs) {
        sort(pairs.begin(), pairs.end(), [](const auto &a, const auto &b) { return a[1] < b[1]; });

        int curr = INT_MIN, ans = 0;
        for (const auto &pair : pairs) {
            if (pair[0] > curr) curr = pair[1], ans++;
        }
        return ans;
    }
};
