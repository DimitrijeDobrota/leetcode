class Solution {
  public:
    int furthestBuilding(const vector<int> &heights, int bricks, int ladders) const {
        const int n = size(heights);
        priority_queue<int> pq;

        for (int i = 1; i < n; i++) {
            const int diff = heights[i] - heights[i - 1];
            if (diff <= 0) continue;
            if (diff > bricks) {
                if (ladders-- == 0) return i - 1;
                if (pq.empty() || pq.top() < diff) continue;
                bricks += pq.top();
                pq.pop();
            }
            bricks -= diff;
            pq.push(diff);
        }

        return n - 1;
    }
};
