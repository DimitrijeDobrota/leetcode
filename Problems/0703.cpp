class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    int k;

public:
    KthLargest(int k, const vector<int>& nums)
        : pq(std::begin(nums), std::end(nums))
        , k(k)
    {
        while (std::size(pq) > k) {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.emplace(val);
        if (std::size(pq) > k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */