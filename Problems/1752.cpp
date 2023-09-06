
// Simulation
class Solution {
  public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a), pq.push(b), pq.push(c);

        int res = 0;
        while (pq.size() >= 2) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a > 1) pq.push(a - 1);
            if (b > 1) pq.push(b - 1);
            res++;
        }
        return res;
    }
};

// Math
class Solution {
  public:
    int maximumScore(const int a, const int b, const int c) const {
        const int total = a + b + c;
        return min(total / 2, total - max({a, b, c}));
    }
};
