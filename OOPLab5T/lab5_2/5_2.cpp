#include <iostream>
#include <vector>

using namespace std;

class Wheel {
private:
    float radius;
    float width;
public:
    Wheel(float r, float w): radius(r), width(w) {}
    float getRadius() { return radius; }
    float getWidth() { return width; }
};

class Bicycle {
private:
    Wheel frontWheel;
    Wheel lastWheel;
    string color;
public:
    Bicycle(float fw_radius, float fw_width, float lw_radius, float lw_width, string c):
            frontWheel(fw_radius, fw_width), lastWheel(lw_radius, lw_width), color(c) {}
    float getfrontWheelRadius() { return frontWheel.getRadius(); }
    float getfrontWheelWidth() { return frontWheel.getWidth(); }
    float getlastWheelRadius() { return lastWheel.getRadius(); }
    float getlastWheelWidth() { return lastWheel.getWidth(); }
    string getColor() { return color; }
};

class Car {
private:
    vector<Wheel> wheels;
    string brand;
public:
    Car(float w_radius, float w_width, string b): brand(b) {
        for(int i = 0; i < 4; i++) {
            wheels.emplace_back(w_radius, w_width);
        }
    }
    float getWheelRadius() { return wheels[0].getRadius(); }
    float getWheelWidth() { return wheels[0].getWidth(); }
    string getBrand() { return brand; }
};

int main() {
    Bicycle b(26.0, 2.0, 26.0, 2.0, "red");
    Car c(16.0, 7.0, "Honda");
    cout << "Колір велосипеду: " << b.getColor() << endl;
    cout << "Радіус переднього колеса: " << b.getfrontWheelRadius() << endl;
    cout << "Ширина переднього колеса: " << b.getfrontWheelWidth() << endl;
    cout << "Радіус заднього колеса: " << b.getlastWheelRadius() << endl;
    cout << "Ширина заднього колеса: " << b.getlastWheelWidth() << endl;
    cout << "Бренд машини: " << c.getBrand() << endl;
    cout << "Радіус колеса: " << c.getWheelRadius() << endl;
    cout << "Ширина колеса: " << c.getWheelWidth() << endl;
    return 0;
}
