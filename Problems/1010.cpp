class Solution {
  public:
    int numPairsDivisibleBy60(const vector<int> &time) const {
        static int count[60];
        int res = 0;

        memset(count, 0x00, sizeof(count));
        for (const int n : time) {
            const int rem = n % 60;
            res += rem == 0 ? count[0] : count[60 - rem];
            count[rem]++;
        }

        return res;
    }
};
