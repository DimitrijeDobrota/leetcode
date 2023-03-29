class Solution {
public:
  int maxSatisfaction(vector<int> &satisf) {
    sort(satisf.begin(), satisf.end());
    if (satisf.back() <= 0) return 0;

    int j = satisf.size() - 1, crnt = 0, sum = 0, res = 0;
    for (; j >= 0; j--) res = max(res, crnt += sum += satisf[j]);

    return res;
  }
};
