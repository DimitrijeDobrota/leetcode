class Solution {
    typedef pair<long long, long long> elem;

  public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = nums1.size();
        vector<elem> arr(n);
        for (int i = 0; i < n; ++i)
            arr[i] = {nums2[i], nums1[i]};
        sort(rbegin(arr), rend(arr));

        long long sum = 0, res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &[a, b] : arr) {
            pq.emplace(b);
            sum += b;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) res = max(res, sum * a);
        }
        return res;
    }
};
