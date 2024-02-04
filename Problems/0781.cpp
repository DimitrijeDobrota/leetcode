class Solution {
    static const int size = 1001;

  public:
    int numRabbits(const vector<int> &answers) const {
        int count[size];

        memset(count, 0x00, sizeof(count));
        for (const int n : answers)
            count[n]++;

        int res = count[0];
        for (int i = 1; i < size; i++) {
            if (!count[i]) continue;
            res += ((count[i] + i) / (i + 1)) * (i + 1);
        }

        return res;
    }
};
