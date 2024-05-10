class Solution {
  public:
    vector<int> kthSmallestPrimeFraction(const vector<int> &arr, int k) const {
        priority_queue<tuple<double, int, int>> pq;

        for (int i = 0; i < arr.size(); i++) {
            pq.emplace(-1.0 * arr[i] / arr.back(), i, arr.size() - 1);
        }

        while (true) {
            auto [_, i, j] = pq.top();
            pq.pop();
            if (!--k) return {arr[i], arr[j]};
            if (--j > i) pq.emplace(-1.0 * arr[i] / arr[j], i, j);
        }

        return {};
    }
};
