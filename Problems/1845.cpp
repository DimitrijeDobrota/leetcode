class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;
    int used;

  public:
    SeatManager(int n) : used(0) {}

    int reserve() {
        if (!pq.empty()) {
            int seat = pq.top();
            pq.pop();
            return seat;
        }
        return ++used;
    }

    void unreserve(int seatNumber) { pq.push(seatNumber); }
};
