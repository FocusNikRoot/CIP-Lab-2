#include <iostream>

using namespace std;

class IX {
public:
    virtual void Fx1() = 0;
    virtual void Fx2() = 0;
    virtual void Fx3() = 0;
    virtual void Fx4() = 0;
};

class CA : public IX {
public:
    double m_Fx2;
    double m_Fx3;
    double m_Fx4;

    virtual void Fx1() { cout << "CA::Fx1" << endl; };
    virtual void Fx2() { cout << m_Fx2 << endl; };
    virtual void Fx3() { cout << m_Fx3 << endl; };
    virtual void Fx4() { cout << m_Fx4 << endl; };

    CA(double d) {
        m_Fx2 = d * d;
        m_Fx3 = d * d * d;
        m_Fx4 = d * d * d * d;
    };
};

class CB : public IX {
public:
    virtual void Fx1() { cout << "CB::Fx1" << endl; };
    virtual void Fx2() { cout << "CB::Fx2" << endl; };
    virtual void Fx3() { cout << "CB::Fx3" << endl; };
    virtual void Fx4() { cout << "CB::Fx4" << endl; };
};

void foo(IX* pIX) {
    pIX->Fx1();
    pIX->Fx2();
    pIX->Fx3();
    pIX->Fx4();
};

int main() {
    // Создание CA
    CA* pA = new CA(1.789);

    // Создание CB
    CB* pB = new CB;

    // Получение указателя IX для CA, CB
    IX* pIX = pA;
    foo(pIX);

    cout << "-=-=-=-=-=-=-" << endl;

    pIX = pB;
    foo(pIX);

    return 0;
};