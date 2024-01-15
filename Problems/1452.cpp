class Solution {
  public:
    vector<int> peopleIndexes(const vector<vector<string>> &favoriteCompanies) const {
        const int n = size(favoriteCompanies);
        vector<unordered_set<int>> companies(n);
        unordered_map<string, int> um;

        for (int i = 0; i < n; i++) {
            for (const auto &company : favoriteCompanies[i]) {
                const auto it = um.find(company);
                const int key = it == um.end() ? um.size() : it->second;
                if (it == um.end()) um.emplace(company, key);
                companies[i].insert(key);
            }
        }

        static int candidates[101];
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int elems = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (size(companies[i]) >= size(companies[j])) continue;
                candidates[elems++] = j;
            }

            for (const auto &company : companies[i]) {
                int t = 0;
                for (int j = 0; j < elems; j++) {
                    const int candidate = candidates[j];
                    if (companies[candidate].count(company)) {
                        candidates[t++] = candidate;
                    }
                }

                if (!t) {
                    res.push_back(i);
                    break;
                }
                elems = t;
            }
        }
        return res;
    }
};
