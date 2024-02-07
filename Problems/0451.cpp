class Solution {
  public:
    string frequencySort(string &s) const {
        unordered_map<char, int> freq;
        vector<string> bucket(size(s) + 1);

        for (char c : s)
            freq[c]++;
        for (auto [c, n] : freq)
            bucket[n].append(n, c);

        string res;
        for (int i = s.size(); i > 0; i--) {
            if (!bucket[i].empty()) res.append(bucket[i]);
        }

        return res;
    }
};

class Solution {
  public:
    string frequencySort(const string &s) const {
        static pair<int, char> count[128];

        for (int i = 0; i < size(count); i++)
            count[i] = {0, i};
        for (const char c : s)
            count[c].first++;
        sort(rbegin(count), rend(count));

        string res;
        for (const auto [n, c] : count)
            res += string(n, c);

        return res;
    }
};
