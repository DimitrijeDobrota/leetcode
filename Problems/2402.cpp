class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) const {
        sort(begin(meetings), end(meetings));

        typedef pair<long long, int> record;
        priority_queue<record, vector<record>, greater<>> engaged;
        priority_queue<int, vector<int>, greater<>> unused;
        vector<int> count(n);

        for (int i = 0; i < n; i++)
            unused.push(i);

        for (const auto meeting : meetings) {
            const int s = meeting[0], e = meeting[1];

            while (!engaged.empty() && engaged.top().first <= s) {
                unused.push(engaged.top().second);
                engaged.pop();
            }

            if (!unused.empty()) {
                const int room = unused.top();
                unused.pop();

                count[room] += 1;
                engaged.push({e, room});
            } else {
                const auto [end, room] = engaged.top();
                engaged.pop();

                count[room] += 1;
                engaged.push({end + e - s, room});
            }
        }

        int maxi = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[maxi]) maxi = i;
        }

        return maxi;
    }
};
