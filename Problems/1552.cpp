class Solution {
  public:
    int maxDistance(vector<int> &position, int m) const {
        sort(begin(position), end(position));
        int low = 0, high = position.back() - position.front();
        while (low <= high) {
            const int mid = low + (high - low) / 2;
            int prev = position[0], count = 1;
            for (int i = 1; i < position.size(); i++) {
                if (position[i] - prev >= mid) prev = position[i], count++;
            }
            if (count >= m)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};
