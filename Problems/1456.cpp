class Solution {
    bool isVowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }

  public:
    int maxVowels(string s, int k) {
        int i, cnt = 0;
        for (i = 0; i < k; i++)
            if (isVowel(s[i])) cnt++;

        int maxi = cnt;
        for (; i < s.size(); i++) {
            if (isVowel(s[i - k])) cnt--;
            if (isVowel(s[i])) cnt++;
            maxi = max(maxi, cnt);
        }

        return maxi;
    }
};
