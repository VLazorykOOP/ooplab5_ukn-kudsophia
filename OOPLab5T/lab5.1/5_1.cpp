#include <iostream>
#include <string>
using namespace std;

// Створити клас рідина(Liquid), що має поля:  назва (name), шільність (density).
// Визначити конструктори, деструктор,функцiю друку та iншi сервiснi функцiї.
// Створити похiдний клас – спиртні напої (Alcohol), який має поле міцність (strength).
// Визначити конструктори за замовчуванням та iз рiзним числом параметрiв, деструктори, функцiю друку.
// Визначити функцiї перепризначення щільності (density) і міцності (strength).
// Написати програму тестування всiх можливостей цього класу.
class Liquid {
public:
    // Конструктор з параметрами
    Liquid(const std::string &name, float density)
            : name_(name), density_(density) {}

    // Конструктор за замовчуванням
    Liquid()
            : name_("Unknown"), density_(0.0f) {}

    // Деструктор
    virtual ~Liquid() {}

    // Функція друку
    void print() const {
        std::cout << "Fluid: " << name_ << ", density: " << density_ << std::endl;
    }

    // Функція перепризначення щільності
    void setDensity(float density) {
        density_ = density;
    }

public:
    std::string name_;
    float density_;
};

class Alcohol : public Liquid {
public:
    // Конструктор з параметрами
    Alcohol(const std::string &name, float density, float strength)
            : Liquid(name, density), strength_(strength) {}

    // Конструктор за замовчуванням
    Alcohol()
            : Liquid(), strength_(0.0f) {}

    // Деструктор
    ~Alcohol() {}

    // Функція друку
    void print() const {
        std::cout << "Alcoholic beverage: " << name_ << ", density: " << density_
                  << ", strength: " << strength_ << "%" << std::endl;
    }

    // Функція перепризначення міцності
    void setStrength(float strength) {
        strength_ = strength;
    }

private:
    float strength_;
};

int main() {
    // Тестую
    Liquid water("Вода", 1.0f);
    Alcohol beer("Пиво", 1.01f, 4.5f);

    // Використовую функції
    water.print();  // Liquid: Water, density: 1
    beer.print();  // Alcohol: Beer, density: 1.01, strength: 4.5%

    beer.setDensity(1.02f);
    beer.setStrength(5.0f);
    beer.print();  // Alcohol: Beer, density: 1.02, strength: 5%

    return 0;
}


