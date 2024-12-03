class Solution {
  public:
    int monotoneIncreasingDigits(int n) const {
        string num = to_string(n);
        const int m = size(num);
        int stop = m - 1;

        for (int i = m - 1; i > 0; i--) {
            if (num[i] >= num[i - 1]) continue;
            stop = i - 1;
            num[i - 1]--;
        }

        for (int i = stop + 1; i < m; i++)
            num[i] = '9';

        return stoi(num);
    }
};
