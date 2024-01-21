class PeekingIterator : public Iterator {
    int l_next = -1;
    bool has_next = false;

  public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        if (!Iterator::hasNext()) return;
        l_next = Iterator::next();
        has_next = true;
    }

    int peek() { return l_next; }

    int next() {
        const int crnt = l_next;
        has_next = Iterator::hasNext();
        if (has_next) l_next = Iterator::next();
        return crnt;
    }

    bool hasNext() const { return has_next; }
};
