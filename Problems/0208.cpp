class Trie {
    struct Record {
        bool end;
        array<Record *, 26> records = {nullptr};

        Record *insert(int x) {
            if (records[x]) return records[x];
            return records[x] = new Record();
        }

        Record *check(int x) { return records[x]; }
    };

    Record *record = new Record;
    Record *last(string word) {
        Record *crnt = record;
        for (char c : word)
            if (!crnt)
                return nullptr;
            else
                crnt = crnt->check(c - 'a');
        return crnt;
    }

  public:
    void insert(string word) {
        Record *crnt = record;
        for (char c : word)
            crnt = crnt->insert(c - 'a');
        crnt->end = true;
    }

    bool search(string word) {
        Record *crnt = last(word);
        if (!crnt) return false;
        return crnt->end;
    }

    bool startsWith(string prefix) { return last(prefix); }
};
