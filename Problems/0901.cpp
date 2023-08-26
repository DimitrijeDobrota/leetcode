class StockSpanner {
    static const int length = 10001;
    int size = 0;
    pair<int, int> stocks[length];

  public:
    StockSpanner() {}

    int next(int price) {
        int index = size - 1;
        while (index >= 0)
            if (price >= stocks[index].first)
                index -= stocks[index].second;
            else
                break;
        int span = size - index;
        stocks[size++] = make_pair(price, span);
        return span;
    }
};
