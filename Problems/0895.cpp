class FreqStack {
    unordered_map<int, int> count;
    vector<int> track[20001];
    int maxi = 0;

  public:
    void push(int val) {
        const int cnt = ++count[val];
        track[cnt].push_back(val);
        maxi = max(maxi, cnt);
    }

    int pop() {
        const int res = track[maxi].back();
        track[maxi].pop_back();
        if (track[count[res]--].empty()) maxi--;
        return res;
    }
};
