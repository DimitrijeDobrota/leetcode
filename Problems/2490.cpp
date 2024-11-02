class Solution {
  public:
    bool isCircularSentence(const string &sentence) const {
        char prev = sentence.back();
        stringstream ss(sentence);
        string word;

        while (ss >> word) {
            if (word.front() != prev) return false;
            prev = word.back();
        }

        return true;
    }
};
