class Solution {
  public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        int n = s.length(), start = 0, maxi = 0, result = 0;
        for_each(s.begin(), s.end(), [](char &c) { c -= 'A'; });

        for (int end = 0; end < n; end++) {
            maxi = max(maxi, ++counts[s[end]]);
            while (end - start - maxi + 1 > k) {
                counts[s[start++]]--;
                for (int i = 0; i < 26; i++)
                    maxi = max(maxi, counts[i]);
            }
            result = max(result, end - start + 1);
        }
        return result;
    }
};
