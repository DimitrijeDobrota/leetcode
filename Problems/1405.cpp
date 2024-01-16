class Solution {
    typedef tuple<int, char> record;

  public:
    string longestDiverseString(int a, int b, int c) const {
        priority_queue<record> pq;
        if (a > 0) pq.emplace(a, 'a');
        if (b > 0) pq.emplace(b, 'b');
        if (c > 0) pq.emplace(c, 'c');

        string res;
        int last = '!', lastc = 1;
        while (!pq.empty()) {
            const auto [cnt, c] = pq.top();
            pq.pop();
            if (c == last && lastc == 2) {
                if (pq.empty()) return res;
                const auto [ocnt, oc] = pq.top();
                pq.pop();
                if (ocnt > 1) pq.emplace(ocnt - 1, oc);
                res += oc;
                lastc = 0;
            }
            if (c != last) last = c, lastc = 0;
            if (cnt > 1) pq.emplace(cnt - 1, c);
            res += c;
            lastc++;
        }
        return res;
    }
};
