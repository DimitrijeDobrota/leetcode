class ProductOfNumbers {
    std::vector<int> prefix = { 1 };

public:
    void add(int num) {
        if(num == 0) prefix.resize(1);
        else prefix.emplace_back(num * prefix.back());
    }

    int getProduct(int k) const {
        if(k >= prefix.size()) return 0;
        return prefix.back() / prefix[prefix.size() - k - 1];
    }
};