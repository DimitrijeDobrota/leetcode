class Solution {
  public:
    int maxSatisfied(const vector<int> &customers, const vector<int> &grumpy, int minutes) const {
        const int n = size(customers);
        int total = 0, crnt = 0, maxi = 0;

        for (int i = 0; i < n; i++) {
            (grumpy[i] ? crnt : total) += customers[i];
            if (i >= minutes && grumpy[i - minutes]) crnt -= customers[i - minutes];
            maxi = max(maxi, crnt);
        }

        return total + maxi;
    }
};
