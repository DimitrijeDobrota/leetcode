class Solution {
    inline static bool isVowel(const char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

  public:
    long long countVowels(const string &word) const {
        long long n = size(word), res = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(word[i])) res += (i + 1) * (n - i);
        }
        return res;
    }
};
