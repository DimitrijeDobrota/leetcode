class RLEIterator {
    vector<int> &vec;
    int idx = 0;

  public:
    RLEIterator(vector<int> &encoding) : vec(encoding) {}

    int next(int n) {
        while (idx < vec.size() && n > vec[idx])
            n -= vec[idx], idx += 2;
        if (idx >= vec.size()) return -1;
        vec[idx] -= n;
        return vec[idx + 1];
    }
};
