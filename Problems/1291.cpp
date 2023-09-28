class Solution {
  public:
    vector<int> sequentialDigits(const int low, const int high) {
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            int crnt = i;
            for (int j = i + 1; j <= 9; j++) {
                crnt = crnt * 10 + j;
                if (crnt > high) break;
                if (crnt >= low) res.push_back(crnt);
            }
        }
        sort(begin(res), end(res));
        return res;
    }
};

// BFS, without sort
class Solution {
  public:
    vector<int> sequentialDigits(const int low, const int high) {
        queue<int> q;
        vector<int> res;
        for (int i = 1; i <= 9; i++)
            q.push(i);
        while (!q.empty()) {
            const int crnt = q.front();
            q.pop();
            if (crnt > high) continue;
            if (crnt >= low) res.push_back(crnt);
            if (crnt % 10 == 9) continue;
            q.push(crnt * 10 + crnt % 10 + 1);
        }
        return res;
    }
};
