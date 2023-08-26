class WordDictionary {
    vector<WordDictionary *> children;
    bool isEndOfWord = false;
    ;

  public:
    WordDictionary() : children(vector<WordDictionary *>(26, nullptr)) {}

    void addWord(string word) {
        WordDictionary *crnt = this;
        for (char c : word) {
            if (crnt->children[c - 'a'] == nullptr) crnt->children[c - 'a'] = new WordDictionary();
            crnt = crnt->children[c - 'a'];
        }
        crnt->isEndOfWord = true;
    }

    bool search(string word) {
        WordDictionary *crnt = this;
        for (int i = 0; i < word.length(); ++i) {
            if (word[i] == '.') {
                for (auto c : crnt->children)
                    if (c && c->search(word.substr(i + 1))) return true;
                return false;
            }
            if (crnt->children[word[i] - 'a'] == nullptr) return false;
            crnt = crnt->children[word[i] - 'a'];
        }
        return crnt && crnt->isEndOfWord;
    }
};
