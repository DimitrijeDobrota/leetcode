class Cashier {
    uint16_t price[201];
    uint16_t n, crnt = 0;
    double discount;

  public:
    Cashier(int n, int discount, const vector<int> &products, const vector<int> &prices)
        : n(n), discount((double)(100 - discount) / 100.0) {
        for (int i = 0; i < products.size(); i++)
            this->price[products[i]] = prices[i];
    }

    double getBill(const vector<int> &product, const vector<int> &amount) {
        uint32_t total = 0;
        for (uint8_t i = 0; i < product.size(); i++)
            total += price[product[i]] * amount[i];

        if (++crnt == n) {
            crnt = 0;
            return total * discount;
        }

        return total;
    }
};
