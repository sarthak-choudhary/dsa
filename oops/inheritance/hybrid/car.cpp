class Car : virtual public Vehicle {
    public :
        int numGears;

    Car() {
        cout << "Car's default constructor" << endl;
    }

    ~Car() {
        cout << "Car's Destructor " << endl;
    }
    
    void print() {
        cout << "NumTyres : " << numTyres << endl;
        cout << "Color :" << color << endl;
        cout << "Num gears : " << numGears << endl;
    }
};