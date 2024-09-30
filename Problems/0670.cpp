class Solution {
  public:
    int maximumSwap(int numi) const {
        string num = to_string(numi);
        const int n = size(num);
        int last[10] = {0};

        for (int i = 0; i < n; i++)
            last[num[i] - '0'] = i;
        for (int i = 0; i < n; i++) {
            for (int d = 9; d > num[i] - '0'; d--) {
                if (last[d] <= i) continue;
                swap(num[i], num[last[d]]);
                return stoi(num);
            }
        }

        return numi;
    }
};
