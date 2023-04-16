#include <iostream>
#include <string>
using namespace std;

class Human {
protected:
    string name;
    int age;
public:
    Human() {
        name = "";
        age = 0;
    }
    virtual void input(istream& in) {
        cout << "Ім'я: "; in >> name;
        cout << "Вік: "; in >> age;
    }
    virtual void output(ostream& out) {
        out << "Ім'я: " << name << endl;
        out << "Вік: " << age << endl;
    }
    Human(const Human& h) : name(h.name), age(h.age) {}
    Human& operator=(const Human& h) {
        name = h.name;
        age = h.age;
        return *this;
    }
    virtual ~Human() {}
};

class Teacher : public Human {
private:
    string subject;
public:
    Teacher() : Human() {
        subject = "";
    }
    void input(istream& in) {
        Human::input(in);
        cout << "Предмет: "; in >> subject;
    }
    void output(ostream& out) {
        Human::output(out);
        out << "Предмет: " << subject << endl;
    }
    Teacher(const Teacher& t) : Human(t), subject(t.subject) {}
    Teacher& operator=(const Teacher& t) {
        Human::operator=(t);
        subject = t.subject;
        return *this;
    }
    ~Teacher() {}
};

int main() {
    Human h1;
    h1.input(cin);
    cout << endl << "Інформація про людину:" << endl;
    h1.output(cout);

    Teacher t1;
    t1.input(cin);
    cout << endl << "Інформація про викладача:" << endl;
    t1.output(cout);

    return 0;
}

