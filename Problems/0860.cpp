class Solution {
  public:
    bool lemonadeChange(const vector<int> &bills) const {
        int count[2] = {0, 0};

        for (const int n : bills) {
            switch (n) {
            case 5: count[0]++; break;
            case 10:
                if (count[0] == 0) return false;
                count[0]--;
                count[1]++;
                break;
            case 20:
                if (count[0] > 0 && count[1] > 0) {
                    count[0]--;
                    count[1]--;
                    break;
                }

                if (count[0] >= 3) {
                    count[0] -= 3;
                    break;
                }

                return false;
            }
        }

        return true;
    }
};
