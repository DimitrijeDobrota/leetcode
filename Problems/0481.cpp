class Solution {
  public:
    int magicalString(const int n) const {
        if (n <= 3) return 1;

        queue<int> q;
        q.push(2);

        int count = 2, res = 1, last = 2;
        while (!q.empty()) {
            const int crnt = q.front();
            q.pop();

            res += crnt == 1;
            if (++count == n) return res;

            last = last == 1 ? 2 : 1;
            for (int i = 0; i < crnt; i++)
                q.push(last);
        }

        return -1;
    }
};
