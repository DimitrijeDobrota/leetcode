class StockSpanner {
    std::vector<std::pair<int, int>> stack;

public:
    StockSpanner() = default;
    
    int next(int price) {
        int total = 1;
        while (!std::empty(stack) && price >= stack.back().first) {
            total += stack.back().second;
            stack.pop_back();
        }
        stack.emplace_back(price, total);
        return total;
    }
};

class StockSpanner {
    std::vector<std::pair<int, int>> stack;
    int time = 0;

public:
    StockSpanner() = default;
    
    int next(int price) {
        while (!std::empty(stack) && price >= stack.back().first) {
            stack.pop_back();
        }
        const auto result = ++time - (!std::empty(stack) ? stack.back().second : 0);
        stack.emplace_back(price, time);
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */