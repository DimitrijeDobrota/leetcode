class Solution {
  public:
    int smallestChair(const vector<vector<int>> &times, int targetFriend) const {
        static tuple<int, bool, int> timeline[20002];
        const int n = size(times);
        priority_queue<int> seats;

        for (int i = 0; i < n; i++) {
            timeline[i * 2] = {times[i][0], true, i};
            timeline[i * 2 + 1] = {times[i][1], false, i};
            seats.push(-i);
        }

        sort(timeline, timeline + n * 2);

        static int assign[10001];
        for (const auto [time, sit, person] : span(timeline, timeline + n * 2)) {
            if (person == targetFriend) return -seats.top();
            if (sit)
                assign[person] = seats.top(), seats.pop();
            else
                seats.push(assign[person]);
        }

        return -1;
    }
};
