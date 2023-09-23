class NestedIterator {
    stack<pair<vector<NestedInteger> *, int>> st;

  public:
    NestedIterator(vector<NestedInteger> &nestedList) { st.push({&nestedList, 0}); }
    int next() {
        if (!hasNext()) return -1;
        auto &elem = st.top();
        return (*elem.first)[elem.second++].getInteger();
    }

    bool hasNext() {
        while (!st.empty()) {
            auto &elem = st.top();
            if (elem.second == elem.first->size()) {
                st.pop();
                continue;
            }
            if ((*elem.first)[elem.second].isInteger()) return true;
            st.push({&(*elem.first)[elem.second++].getList(), 0});
        }
        return false;
    }
};
