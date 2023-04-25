class SmallestInfiniteSet {
  int count = 1;
  set<int> st;

public:
  int popSmallest() {
    if (!st.empty()) {
      int elem = *st.begin();
      st.erase(st.begin());
      return elem;
    }
    return count++;
  }

  void addBack(int num) {
    if (num >= count) return;
    st.insert(num);
  }
};
