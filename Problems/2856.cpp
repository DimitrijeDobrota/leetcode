class Solution {
  public:
    int minLengthAfterRemovals(const vector<int> &nums) const {
        priority_queue<int> pq;

        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                pq.push(count);
                count = 1;
            } else
                count++;
        }
        pq.push(count);

        while (pq.size() > 1) {
            const int first = pq.top();
            pq.pop();
            const int second = pq.top();
            pq.pop();
            if (first > 1) pq.push(first - 1);
            if (second > 1) pq.push(second - 1);
        }

        return pq.size() ? pq.top() : 0;
    }
};

// Not sure why this works...
class Solution {
  public:
    int minLengthAfterRemovals(const vector<int> &nums) const {
        const int n = nums.size();
        int count = 1, maxi = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                maxi = max(maxi, count);
                count = 1;
            } else
                count++;
        }
        maxi = max(maxi, count);

        if (maxi <= n / 2) return n % 2;
        return 2 * maxi - n;
    }
};
