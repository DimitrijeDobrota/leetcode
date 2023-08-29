class Solution {
  public:
    int bestClosingTime(string customers) {
        int mini = 0, crnt = 0, res = 0;

        for (int i = 0; i < customers.size(); i++) {
            crnt += (customers[i] == 'Y') ? -1 : +1;
            if (crnt >= mini) continue;
            res = i + 1;
            mini = crnt;
        }

        return res;
    }
};
