class Solution {
  public:
    int minimumOperationsToMakeKPeriodic(const string &word, int k) const {
        unordered_map<string, int> um;
        const int n = size(word);
        int maxi = 0;

        for (int i = 0; i < n; i += k) {
            maxi = max(maxi, ++um[word.substr(i, k)]);
        }

        return n / k - maxi;
    }
};
