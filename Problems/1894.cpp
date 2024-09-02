class Solution {
  public:
    int chalkReplacer(const vector<int> &chalk, int k) const {
        const long long sum = accumulate(begin(chalk), end(chalk), 0ll);
        int n = 0;

        k %= sum;
        while (true) {
            if (k < chalk[n]) return n;
            k -= chalk[n];
            n = (n + 1) % size(chalk);
        }

        return -1;
    }
};
