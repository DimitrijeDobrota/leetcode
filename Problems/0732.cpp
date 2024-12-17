// Map solution
class MyCalendarThree {
    map<int, int> mp;

  public:
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;

        int res = 0, acc = 0;
        for (const auto [_, add] : mp) {
            res = max(res, acc += add);
        }

        return res;
    }
};

// Vector solution
class MyCalendarThree {
    using type_t = pair<int, int>;
    vector<type_t> vec;

  public:
    int book(int startTime, int endTime) {
        const type_t start = {startTime, 1};
        const type_t end = {endTime, -1};

        // trick to insert into a sorted vector
        vec.insert(upper_bound(vec.begin(), vec.end(), start), start);

        vec.insert(upper_bound(vec.begin(), vec.end(), end), end);

        int res = 0, acc = 0;
        for (const auto [_, add] : vec) {
            res = max(res, acc += add);
        }

        return res;
    }
};
