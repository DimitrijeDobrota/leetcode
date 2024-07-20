class Solution {
  public:
    int countHighestScoreNodes(const vector<int> &parents) const {
        const int n = size(parents);

        vector<int> count(n, 0);
        for (int i = 1; i < n; i++) {
            count[parents[i]]++;
        }

        queue<int> q;
        for (int i = 1; i < n; i++) {
            if (!count[i]) q.push(i);
        }

        vector<int> below(n, 1);
        while (q.front()) {
            const int root = q.front();
            q.pop();
            const int parent = parents[root];

            if (!--count[parent]) q.push(parent);
            below[parent] += below[root];
        }

        vector<int> above(n, 0);
        for (int i = 1; i < n; i++) {
            above[i] = below[0] - below[i];
        }

        vector<long long> score(n, 1);
        for (int i = 1; i < n; i++) {
            score[parents[i]] *= below[i];
            score[i] *= above[i];
        }

        int res = 0;
        long long maxi = 0;
        for (const auto n : score) {
            if (n == maxi) res++;
            if (n > maxi) {
                maxi = n;
                res = 1;
            }
        }

        return res;
    }
};
