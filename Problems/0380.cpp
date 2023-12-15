class RandomizedSet {
  public:
    RandomizedSet() {}

    bool insert(int val) {
        if (um.count(val)) return false;
        nums.emplace_back(val);
        um[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!um.count(val)) return false;
        int last = nums.back();
        um[last] = um[val];
        nums[um[val]] = last;
        nums.pop_back();
        um.erase(val);
        return true;
    }

    int getRandom() { return nums[rand() % nums.size()]; }

  private:
    vector<int> nums;
    unordered_map<int, int> um;
};
