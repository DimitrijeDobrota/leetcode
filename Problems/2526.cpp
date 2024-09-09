class DataStream {
    const int value;
    const int k;
    int cnt = 0;

  public:
    DataStream(int value, int k) : value(value), k(k) {}
    bool consec(int num) {
        if (num == value)
            cnt++;
        else
            cnt = 0;

        return cnt >= k;
    }
};
