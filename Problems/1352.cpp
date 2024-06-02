class ProductOfNumbers {
    vector<long long> prefix = {1};

  public:
    void add(int num) {
        if (num == 0)
            prefix = {1};
        else
            prefix.push_back(num * prefix.back());
    }

    int getProduct(int k) {
        if (k >= prefix.size()) return 0;
        return prefix.back() / prefix[prefix.size() - k - 1];
    }
};
