class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        unordered_map<unsigned long long, int> um;
        for (int i = 0; i < strs.size(); i++) {
            unsigned long long hash = 0;
            vector<int> m(26, 0);

            for (char c : strs[i])
                m[c - 'a']++;
            for (int i = 0; i < 26; i++)
                hash = hash * 100 + m[i];
            if (um.find(hash) == um.end()) {
                um[hash] = res.size();
                res.push_back({strs[i]});
            } else
                res[um[hash]].push_back(strs[i]);
        }
        return res;
    }
};
