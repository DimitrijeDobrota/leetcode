// sort: O(nlogn)
class Solution {
  public:
    vector<string> topKFrequent(const vector<string> &words, int k) {
        unordered_map<string, int> um;
        for (const auto &w : words)
            um[w]++;

        vector<pair<int, string>> vec(um.size());
        vector<string> res(k);

        int count = 0;
        for (const auto &[k, v] : um)
            vec[count++] = {-v, k};
        sort(vec.begin(), vec.end());
        for (int i = 0; i < k; i++)
            res[i] = vec[i].second;

        return res;
    }
};

// heap: O(nlogk)
class Solution {
    typedef pair<string, int> psi;
    static constexpr const auto cmp = [](const psi &p1, const psi &p2) {
        if (p1.second == p2.second) return p1.first < p2.first;
        return p1.second > p2.second;
    };

  public:
    vector<string> topKFrequent(const vector<string> &words, int k) {
        unordered_map<string, int> um;
        for (const auto &w : words)
            um[w]++;

        priority_queue<psi, vector<psi>, decltype(cmp)> pq(cmp);
        vector<string> res(k);

        for (auto it : um) {
            pq.push(it);
            if (pq.size() > k) pq.pop();
        }

        int count = k - 1;
        while (!pq.empty())
            res[count--] = pq.top().first, pq.pop();

        return res;
    }
};
