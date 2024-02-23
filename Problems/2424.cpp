class LUPrefix {
  public:
    LUPrefix(int n) : n(n) { memset(seen, 0x00, sizeof(seen)); }

    void upload(int video) { seen[video] = true; }

    int longest() const {
        while (seen[next])
            next++;
        return next - 1;
    }

  private:
    const int n;
    mutable int next = 1;

    static int seen[100001];
};

int LUPrefix::seen[100001];
