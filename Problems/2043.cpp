#pragma GCC optimize("fast")
static int _ = []() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return 0;
}();

class Bank {
    const int n;
    vector<long long> balance;

    inline bool valid(int acc) const { return acc >= 1 && acc <= n; }

  public:
    Bank(const vector<long long> &balance) : n(balance.size()), balance(balance) {}

    inline bool transfer(int account1, int account2, long long money) {
        if (!valid(account1) || !valid(account2)) return false;
        if (!withdraw(account1, money)) return false;
        if (!deposit(account2, money)) return false;
        ;
        return true;
    }

    inline bool deposit(int account, long long money) {
        if (!valid(account)) return false;
        balance[account - 1] += money;
        return true;
    }

    inline bool withdraw(int account, long long money) {
        if (!valid(account)) return false;
        if (money > balance[account - 1]) return false;
        balance[account - 1] -= money;
        return true;
    }
};
