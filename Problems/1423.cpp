class Solution {
  public:
    int maxScore(const vector<int> &cardPoints, int k) const {
        const int n = size(cardPoints);

        int res = 0, sum = 0;
        for (int i = 0; i < k; i++)
            sum += cardPoints[i];
        for (int i = n, j = k - 1; j >= 0; i--, j--) {
            res = max(res, sum);
            sum += cardPoints[i - 1];
            sum -= cardPoints[j];
        }

        return max(res, sum);
    }
};
