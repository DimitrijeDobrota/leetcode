class Solution {
  public:
    int numberOfWays(const string &corridor) const {
        int total = 0, crnt = 0, start = 0;
        long res = 1;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] != 'S') continue;
            if (crnt == 1) start = i;
            if (crnt == 2) {
                if (start) {
                    res = (res * (i - start)) % static_cast<int>(1E9 + 7);
                }
                start = crnt = 0;
            }
            crnt++, total++;
        }

        return !total || total % 2 ? 0 : res;
    }
};
