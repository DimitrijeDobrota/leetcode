// Using a priority_queue
class Solution {
  public:
    int minStoneSum(vector<int> &piles, int k) {
        priority_queue<int> pq;
        int res = 0;
        for (int e : piles)
            res += e, pq.push(e);
        while (k--) {
            int t = pq.top(), pq.pop();
            pq.push(t - t / 2), res -= t / 2;
        }
        return res;
    }
};

// Using heap, constant memory
class Solution {
  public:
    int minStoneSum(vector<int> &piles, int k) {
        auto b = piles.begin(), e = piles.end();
        make_heap(b, e);
        while (k--) {
            pop_heap(b, e);
            auto &elem = *(e - 1);
            elem -= elem / 2;
            push_heap(b, e);
        }
        int sum = 0;
        for (auto v : piles)
            sum += v;
        return sum;
    }
};
