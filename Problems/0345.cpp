class Solution {
    bool is_vowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

  public:
    string reverseVowels(string s) {
        int i = 0, j = size(s) - 1;
        while (i < j) {
            while (i < j && !is_vowel(s[i]))
                i++;
            while (i < j && !is_vowel(s[j]))
                j--;
            if (i >= j) break;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};
