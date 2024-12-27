class SORTracker {
    using type_t = tuple<int, string>;

    set<type_t> st;
    set<type_t>::iterator pos = end(st);

  public:
    void add(string name, int score) {
        const auto it = st.insert({-score, name}).first;
        if (pos == end(st) || *it < *pos) pos--;
    }

    const string &get() { return get<1>(*pos++); }
};
