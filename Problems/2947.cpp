class Solution {
    static inline bool isVowel(const char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

  public:
    int beautifulSubstrings(const string &s, int k) const {
        const int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int vowels = 0, consonants = 0;
            for (int j = i; j < n; j++) {
                isVowel(s[j]) ? vowels++ : consonants++;
                if (vowels != consonants) continue;
                if ((vowels * consonants) % k != 0) continue;
                res++;
            }
        }
        return res;
    }
};
