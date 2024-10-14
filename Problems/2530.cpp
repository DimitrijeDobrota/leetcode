class Solution {
  public:
    long long maxKelements(const vector<int> &nums, int k) const {
        priority_queue<int> pq(begin(nums), end(nums));
        long long res = 0;

        while (k--) {
            int crnt = pq.top();
            res += crnt;
            if (crnt == 1) {
                res += k;
                break;
            }
            pq.pop();
            pq.push((crnt + 2) / 3);
        }

        return res;
    }
};
