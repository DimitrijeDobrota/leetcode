class Solution {
  public:
    string reversePrefix(string word, char ch) const {
        const int n = size(word);
        int i;

        for (i = 0; i < n; i++) {
            if (word[i] == ch) break;
        }

        if (i == n) return word;

        int j = 0;
        while (j < i)
            swap(word[i--], word[j++]);

        return word;
    }
};
