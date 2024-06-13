class Solution {
  public:
    int minMovesToSeat(const vector<int> &seats, const vector<int> &students) const {
        static int count[101];

        memset(count, 0x00, sizeof(count));
        for (const int n : seats)
            count[n]++;
        for (const int n : students)
            count[n]--;

        int res = 0, unmatched = 0;
        for (int n : count) {
            res += abs(unmatched);
            unmatched += n;
        }

        return res;
    }
};
