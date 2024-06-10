class Solution {
  public:
    bool isPossible(const vector<int> &nums) const {
        unordered_map<int, int> left, end;
        for (const int n : nums)
            left[n]++;

        for (const int n : nums) {
            if (!left[n]) continue;
            left[n]--;

            if (end[n - 1] > 0) {
                end[n - 1]--;
                end[n]++;
            } else if (left[n + 1] > 0 && left[n + 2] > 0) {
                left[n + 1]--;
                left[n + 2]--;
                end[n + 2]++;
            } else
                return false;
        }

        return true;
    }
};
