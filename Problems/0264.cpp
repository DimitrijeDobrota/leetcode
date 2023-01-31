// Brute force solution
class Solution {
public:
  int nthUglyNumber(int n) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    unordered_set<long long> us;
    int count;

    pq.push(1);
    count = 1;
    while (!pq.empty() && count < n) {
      long long n = pq.top();
      pq.pop();
      for (int i : {2, 3, 5}) {
        if (us.count(n * i)) continue;
        pq.push(n * i);
        us.insert(n * i);
      }
      count++;
    }

    return (int)pq.top();
  }
};

// DP solution
class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> k(n);
    k[0] = 1;
    int t2 = 0, t3 = 0, t5 = 0;
    for (int i = 1; i < n; i++) {
      k[i] = min(k[t2] * 2, min(k[t3] * 3, k[t5] * 5));
      t2 += k[i] == k[t2] * 2;
      t3 += k[i] == k[t3] * 3;
      t5 += k[i] == k[t5] * 5;
    }
    return k.back();
  }
};
