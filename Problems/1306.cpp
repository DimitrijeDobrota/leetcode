class Solution {
  public:
    bool canReach(const vector<int> &arr, int start) {
        bitset<50001> bs;
        queue<int> q({start});
        while (!q.empty()) {
            const int idx = q.front();
            q.pop();
            const int left = idx - arr[idx], right = idx + arr[idx];

            if (right < arr.size() && !bs[right]) {
                if (!arr[right]) return true;
                bs.set(right);
                q.push(right);
            }

            if (left >= 0 && !bs[left]) {
                if (!arr[left]) return true;
                bs.set(left);
                q.push(left);
            }
        }

        return false;
    }
};
