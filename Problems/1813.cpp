class Solution {
  public:
    bool areSentencesSimilar(const string &sentence1, const string &sentence2) const {
        stringstream ss1(sentence1), ss2(sentence2);
        vector<string> s1, s2;
        string word;

        while (getline(ss1, word, ' '))
            s1.push_back(word);
        while (getline(ss2, word, ' '))
            s2.push_back(word);

        if (size(s1) > size(s2)) swap(s1, s2);

        int i = 0, j = 0;
        const int n = size(s1), m = size(s2);
        while (i < n && s1[i] == s2[i])
            i++;
        while (j < n && s1[n - j - 1] == s2[m - j - 1])
            j++;

        return i + j >= n;
    }
};
