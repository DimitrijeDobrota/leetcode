class Solution {
  public:
    long long pickGifts(const vector<int> &gifts, int k) const {
        priority_queue<int> pq(begin(gifts), end(gifts));
        long long remain = accumulate(begin(gifts), end(gifts), 0ll);

        while (k--) {
            const int crnt = pq.top(), leave = sqrt(crnt);
            pq.pop(), pq.push(leave);
            remain -= crnt - leave;
        }

        return remain;
    }
};
