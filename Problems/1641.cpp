class Solution {
  public:
    int countVowelStrings(int n) {
        int vec[5] = {1, 1, 1, 1, 1};
        for (int i = 1; i <= n; i++) {
            for (int i = 4, sum = 0; i >= 0; i--)
                vec[i] = sum += vec[i];
        }
        return vec[0];
    }
};
