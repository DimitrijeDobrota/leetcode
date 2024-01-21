class MyCalendar {
    typedef pair<int, int> record;
    set<record> st;

  public:
    bool book(int estart, int eend) {
        const record event(estart, eend);
        const auto next = st.lower_bound(event);

        if (next != end(st) && next->first < eend) return false;
        if (next != begin(st)) {
            const auto prv = prev(next);
            if (prv->second > estart) return false;
        }

        st.insert(event);
        return true;
    }
};
