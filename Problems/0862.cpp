// Priority queue
class Solution {
  public:
    int shortestSubarray(const vector<int> &nums, int k) const {
        const int n = size(nums);
        long long acc = 0;
        uint res = -1;

        using type_t = pair<long long, int>;
        priority_queue<type_t, vector<type_t>, greater<>> pq;

        for (uint i = 0; i < n; i++) {
            acc += nums[i];

            if (acc >= k) res = min(res, i + 1);
            while (!pq.empty() && acc - pq.top().first >= k) {
                res = min(res, i - pq.top().second);
                pq.pop();
            }

            pq.emplace(acc, i);
        }

        return res;
    }
};

// Deque optimization
class Solution {
  public:
    int shortestSubarray(const vector<int> &nums, int k) const {
        static long long prfx[100001];
        for (int i = 0; i < size(nums); i++) {
            prfx[i + 1] = prfx[i] + nums[i];
        }

        uint res = -1;
        deque<int> dq;
        for (uint i = 0; i <= size(nums); i++) {
            while (!dq.empty() && prfx[i] - prfx[dq.front()] >= k) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && prfx[i] <= prfx[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return res;
    }
};
