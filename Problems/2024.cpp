class Solution {
public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    int i = 0, j = 0, res = 0, t = 0, f = 0;
    while (true) {
      if (min(t, f) <= k) {
        if (j == answerKey.size()) break;
        (answerKey[j++] == 'T' ? t : f)++;
      } else {
        res = max(res, j - i);
        (answerKey[i++] == 'T' ? t : f)--;
      }
    }
    return max(res - 1, j - i);
  }
};
