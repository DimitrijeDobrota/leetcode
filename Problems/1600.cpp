class ThroneInheritance {
    unordered_map<string, vector<string>> children;
    unordered_set<string> dead;

    const string king;

  public:
    ThroneInheritance(const string &king) : king(king) {}
    void birth(const string &parent, const string &child) { children[parent].push_back(child); }
    void death(const string &name) { dead.insert(name); }

    vector<string> getInheritanceOrder() {
        order.clear();
        rec(king);
        return order;
    }

  private:
    vector<string> order;
    void rec(const string &name) {
        if (!dead.count(name)) order.push_back(name);
        for (const string &s : children[name])
            rec(s);
    }
};
