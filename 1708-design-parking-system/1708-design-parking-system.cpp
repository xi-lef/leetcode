class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small)
        : big(big), medium(medium), small(small) {}

    bool addCar(int carType) {
        int& size = carType == 1 ? big : carType == 2 ? medium : small;
        if (size == 0)
            return false;

        --size;
        return true;
    }

private:
    int big;
    int medium;
    int small;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */