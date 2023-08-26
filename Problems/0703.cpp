class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

  public:
    KthLargest(int k, vector<int> &nums) : k(k), pq(nums.begin(), nums.end()) {
        while (pq.size() > k)
            pq.pop();
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k) pq.pop();
        return pq.top();
    }
};
