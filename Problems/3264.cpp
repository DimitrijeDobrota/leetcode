class Solution {
  public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {
        using type_t = pair<int, int>;
        priority_queue<type_t, vector<type_t>, greater<>> pq;
        const int n = size(nums);

        for (int i = 0; i < n; i++) {
            pq.emplace(nums[i], i);
        }

        while (k--) {
            const auto [val, idx] = pq.top();
            pq.pop();
            pq.emplace(val * multiplier, idx);
        }

        while (!pq.empty()) {
            const auto [val, idx] = pq.top();
            pq.pop();
            nums[idx] = val;
        }

        return nums;
    }
};
