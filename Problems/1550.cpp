class Solution {
  public:
    bool threeConsecutiveOdds(const vector<int> &arr) const {
        int cnt = 0;

        for (const int n : arr) {
            if (n % 2 == 0)
                cnt = 0;
            else if (++cnt == 3)
                return true;
        }

        return false;
    }
};
