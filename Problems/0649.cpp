class Solution {
  public:
    string predictPartyVictory(string senate) {
        queue<int> rq, dq;
        int n = senate.size();

        for (int i = 0; i < n; i++)
            (senate[i] == 'R' ? rq : dq).push(i);

        while (!rq.empty() && !dq.empty()) {
            int a = rq.front(), b = dq.front();
            rq.pop(), dq.pop();
            if (a < b)
                rq.push(a + n);
            else
                dq.push(b + n);
        }

        return rq.size() ? "Radiant" : "Dire";
    }
};
