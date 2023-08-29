class Solution {
  public:
    vector<int> memLeak(int memory1, int memory2) {
        int time = 1;
        while (time <= memory1 || time <= memory2) {
            if (memory1 < memory2)
                memory2 -= time;
            else
                memory1 -= time;
            time++;
        }
        return {time, memory1, memory2};
    }
};
