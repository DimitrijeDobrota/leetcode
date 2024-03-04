class Solution {
  public:
    int bagOfTokensScore(vector<int> &tokens, int power) const {
        sort(begin(tokens), end(tokens));

        const int n = size(tokens);
        int score = 0, i = 0, j = n - 1;
        while (i <= j) {
            if (power >= tokens[i])
                score++, power -= tokens[i++];
            else if (i < j && score > 0)
                score--, power += tokens[j--];
            else
                return score;
        }
        return score;
    }
};
