// Group by first letter, 637ms
class Solution {
  public:
    long long distinctNames(vector<string> &ideas) {
        array<unordered_set<string>, 26> um;
        for (const auto &idea : ideas)
            um[idea.front() - 'a'].insert(idea.substr(1));

        long long res = 0ll;
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                long long c1 = 0ll, c2 = 0ll;
                for (const auto &s : um[i])
                    c1 += !um[j].count(s);
                for (const auto &s : um[j])
                    c2 += !um[i].count(s);
                res += c1 * c2;
            }
        }

        return res * 2;
    }
};

// Group by suffix, 373ms
class Solution {
  public:
    long long distinctNames(vector<string> &ideas) {
        unordered_map<string, bitset<32>> um;
        unordered_map<bitset<32>, int> cnt;

        for (const auto &idea : ideas)
            um[idea.substr(1)].set(idea.front() - 'a');
        for (const auto &[k, v] : um)
            cnt[v]++;

        long long res = 0ll;
        for (auto it1 = cnt.begin(); it1 != cnt.end(); it1++) {
            for (auto it2 = next(it1); it2 != cnt.end(); it2++) {
                int same = (it1->first & it2->first).count();
                res += (it2->first.count() - same) * (it1->first.count() - same) * it1->second * it2->second;
            }
        }

        return res * 2;
    }
};
