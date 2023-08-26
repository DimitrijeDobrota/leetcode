struct elem {
    static void reset() { id_cnt = 0; }
    static int id_cnt;
    int id = id_cnt++, count = 0;
    void operator++(int) { count++; }
    friend bool operator<(const elem &e1, const elem &e2) { return e1.count > e2.count; }
    friend ostream &operator<<(ostream &os, const elem &e) { return os << e.id << ": " << e.count; }
};
int elem::id_cnt = 0;

class Solution {
    const int size = 20002;
    const int mod = 10000;

  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        elem::reset();
        vector<elem> um(size);
        for (int n : nums)
            um[n + mod]++;
        sort(um.begin(), um.end());
        vector<int> res;
        for (int i = 0; i < k; i++)
            res.push_back(um[i].id - mod);
        return res;
    }
};
