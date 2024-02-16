class Solution {
  public:
    string repeatLimitedString(const string &s, int limit) const {
        int count[27] = {0};
        for (const char c : s)
            count[c & 0x1F]++;

        typedef tuple<char, int> record;
        priority_queue<record> pq;

        for (int i = 1; i <= 26; i++) {
            if (!count[i]) continue;
            pq.emplace('`' + i, count[i]);
        }

        string res;
        char last = '~';
        while (!empty(pq)) {
            const auto [c, cnt] = pq.top();
            pq.pop();
            if (c == last) {
                if (pq.empty()) break;

                const auto [oc, ocnt] = pq.top();
                pq.pop();
                pq.emplace(c, cnt);

                res += oc;
                if (ocnt > 1) pq.emplace(oc, ocnt - 1);

                last = oc;
            } else {
                res += string(min(cnt, limit), c);
                if (cnt > limit) pq.emplace(c, cnt - limit);
                last = c;
            }
        }

        return res;
    }
};

// O(1) space, no priority_queue
class Solution {
  public:
    string repeatLimitedString(const string &s, int limit) const {
        int count[27] = {0};
        for (const char c : s)
            count[c & 0x1F]++;

        string res;
        int i;

        for (i = 26; i >= 0; i--)
            if (count[i]) break;
        if (count[i] == size(s)) return string(min(limit, count[i]), '`' + i);

        int j = i - 1;
        while (i > 0) {
            res += string(min(limit, count[i]), '`' + i);
            if (limit < count[i]) {
                while (j >= 0 && !count[j])
                    j--;
                if (j < 0) break;

                res += '`' + j;

                count[i] -= limit;
                count[j]--;
            } else {
                i = j;
                j = i - 1;
            }
        }

        return res;
    }
};
