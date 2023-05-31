class UndergroundSystem {
  unordered_map<int, pair<string, int>> check_in;
  unordered_map<string, pair<int, int>> average;

public:
  UndergroundSystem() {}

  void checkIn(int id, const string &stationName, int t) {
    check_in[id] = {stationName, t};
  }

  void checkOut(int id, const string &stationName, int t) {
    auto &[name, time] = check_in[id];
    auto &p = average[name + "-" + stationName];
    p.second += t - time;
    p.first++;
  }

  double getAverageTime(const string &startStation, const string &endStation) {
    auto &p = average[startStation + "-" + endStation];
    return (double)p.second / p.first;
  }
};
