class Solution {
  public:
    long long maximumHappinessSum(vector<int> &happiness, int k) const {
        long long res = 0;

        nth_element(begin(happiness), begin(happiness) + k, end(happiness), greater());
        sort(begin(happiness), begin(happiness) + k, greater());

        for (int i = 0; i < k; i++)
            res += max(happiness[i] - i, 0);

        return res;
    }
};
