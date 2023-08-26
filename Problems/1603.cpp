class ParkingSystem {
    vector<int> space;

  public:
    ParkingSystem(int big, int medium, int small) : space(vector<int>{0, big, medium, small}) {}

    bool addCar(int carType) {
        if (space[carType] == 0) return false;
        space[carType]--;
        return true;
    }
};
