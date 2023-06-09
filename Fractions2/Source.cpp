/*Дружественная перегрузка
Срок: к следующему занятию, пятнице 9 июня

1. Возьмите за основу класс дробей из предыдущего ДЗ. Модифицируйте его, чтобы для бинарных равноправных операторов (+, -, *, /, ==, >, < и т.п.) использовать дружественную перегрузку.

2. Добавьте классу Дроби два новых оператора:

• Помещения в поток вывода
• Чтение из потока ввода*/

#include <iostream> 

using namespace std;
class Fraction
{
private:
    int numerator;
    int deniminator;
public:
    Fraction(int num, int denum) : numerator{ num }, deniminator{ denum }{};
    Fraction() : Fraction{ 0, 0 } {};
    void print()const { cout << /*"whole:(" << whole << ")"*/  numerator << "/" << deniminator ; };

    friend Fraction operator+(const Fraction& _this, const Fraction & _that);
    friend Fraction operator-(const Fraction& _this, const Fraction& _that);
    friend Fraction operator*(const Fraction& _this, const Fraction& _that);
    friend Fraction operator/(const Fraction& _this, const Fraction& _that);

    friend bool operator==(const Fraction& _this, const Fraction& _that);
    friend bool operator>(const Fraction& _this, const Fraction& _that);
    friend bool operator<(const Fraction& _this, const Fraction& _that);

    friend ostream& operator <<(ostream& out, const Fraction &frac);
    friend istream& operator >>(istream& in, Fraction& frac);


    int gcd(int a, int b)
    {
        while (a > 0 && b > 0 && a != b)

            if (a > b)
                a -= b;

            else
                b -= a;
        if (a == b)return a;

    }
    void reducter()
    {
        int common_factor = gcd(numerator, deniminator);
        numerator /= common_factor;
        deniminator /= common_factor;

    }

};

Fraction operator+(const Fraction& _this, const Fraction& _that)
{
    Fraction frac3;
    int common_denominator = _this.deniminator * _that.deniminator;
    int common_numerator = _this.numerator * _that.deniminator + _that.numerator * _this.deniminator;
    frac3.numerator = common_numerator;
    frac3.deniminator = common_denominator;
    frac3.reducter();
    return frac3;
}

Fraction operator-(const Fraction& _this, const Fraction& _that)
{
    Fraction frac3;
    int common_denominator = _this.deniminator * _that.deniminator;
    int common_numerator = _this.numerator * _that.deniminator - _that.numerator * _this.deniminator;
    frac3.numerator = common_numerator;
    frac3.deniminator = common_denominator;
    frac3.reducter();
    return frac3;
}

Fraction operator*(const Fraction& _this, const Fraction& _that)
{
    Fraction frac3;
    int common_denominator = _this.deniminator * _that.deniminator;
    int common_numerator = _this.numerator * _that.numerator;
    frac3.numerator = common_numerator;
    frac3.deniminator = common_denominator;
    frac3.reducter();
    return frac3;
}

Fraction operator/(const Fraction& _this, const Fraction& _that)
{
    Fraction frac3;
    int common_denominator = _this.deniminator * _that.numerator;
    int common_numerator = _this.numerator * _that.deniminator;
    frac3.numerator = common_numerator;
    frac3.deniminator = common_denominator;
    frac3.reducter();
    return frac3;
}

bool operator==(const Fraction& _this, const Fraction& _that)
{
    if (_this.numerator == _that.deniminator && _this.numerator == _that.deniminator)
        return true;
    else { return false; }
}

bool operator>(const Fraction& _this, const Fraction& _that)
{
    Fraction fracThis, fracThat;
    int common_denominator = _this.deniminator * _that.deniminator;
    fracThis.deniminator = common_denominator;
    fracThat.deniminator = common_denominator;

    fracThis.numerator = _this.numerator * _that.deniminator;
    fracThat.numerator = _that.numerator * _this.deniminator;

    if (fracThis.numerator > fracThat.numerator) return true;
    else { return false; };


}

bool operator<(const Fraction& _this, const Fraction& _that)
{
    Fraction fracThis, fracThat;
    int common_denominator = _this.deniminator * _that.deniminator;
    fracThis.deniminator = common_denominator;
    fracThat.deniminator = common_denominator;

    fracThis.numerator = _this.numerator * _that.deniminator;
    fracThat.numerator = _that.numerator * _this.deniminator;

    if (fracThis.numerator < fracThat.numerator) return true;
    else { return false; };
}

ostream& operator <<(ostream& out, const Fraction& frac)
{
    out << frac.numerator << " / " << frac.deniminator;
    return out;
}

istream& operator>>(istream& in, Fraction& frac)
{
    cout << "Enter numerator: ";
    in >> frac.numerator;
    cout << "Enter denominator: ";
    in >> frac.deniminator;

    return in;
}


int main()
{
    Fraction frac1(5, 3);
    Fraction frac2(4, 9);
    Fraction frac3;


    cout << frac1 << " - " << frac2 << " = " << frac1 - frac2;
    cout << endl;

    cout << frac1 << " + " << frac2 <<" = " << frac1 + frac2;
    cout << endl;

    cin >> frac3;
    cout << frac3;
    cout << endl;

    if (frac1 > frac2) cout << frac1 << " > " << frac2;
    else
    {
        cout << frac1 << "!> " << frac2;
    }
    cout << endl;

    if (frac3 < frac2) cout << frac3 << " < " << frac2;
    else
    {
        cout << frac3 << "!< " << frac2;
    }
    cout << endl;

    Fraction frac4;
    cin >> frac4;
    cout << endl;

    if (frac1 == frac2) cout << frac1 << " == " << frac2;
    else
    {
        cout << frac1 << "!== " << frac2;
    }


}
