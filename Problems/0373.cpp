class Solution {
    typedef tuple<int, int, int> tpl;

  public:
    vector<vector<int>> kSmallestPairs(const vector<int> &nums1, const vector<int> &nums2, int k) {
        priority_queue<tpl, vector<tpl>, greater<tpl>> pq;
        vector<vector<int>> res;
        res.reserve(k);

        for (int i = 0; i < min(k, (int)nums1.size()); i++)
            pq.push({nums1[i] + nums2[0], i, 0});

        while (k-- && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if (j == nums2.size() - 1) continue;
            pq.push({nums1[i] + nums2[j + 1], i, j + 1});
        }
        return res;
    }
};
