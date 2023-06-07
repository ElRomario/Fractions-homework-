/*Создать класс «Дробь» для представления простой дроби.
Поля:
■ числитель,
■ знаменатель.
Функции-члены: ■ конструктор принимающий числитель и знаменатель.
В конструкторе использовать список инициализаторов полей класса.
▷ конструктор по умолчанию, реализовать через делегирование конструктору
с параметрами числитель и знаменатель;
▷ вывод на экран дроби;
▷ сложение/вычитание/умножение простой дроби с простой дробью;
▷ сложение/вычитание/умножение простой дроби с целым числом.
В арифметических операциях предусмотреть возможность вызова операций
по цепочке используя указатель this.
Предусмотреть сокращение дроби. Сокращение рекомендуется производить
в конструкторе.*/

#include <iostream> 

using namespace std;
class Fraction
{
private:
    int numerator;
    int deniminator;
    int whole;
public:
    Fraction(int num, int denum, int whole) : numerator{ num }, deniminator{ denum }, whole{ 0 }{};
    Fraction(int num, int denum) : Fraction{ num, denum, 0 } {};
    Fraction() : Fraction{ 0, 0, 0 } {};
    void print()const { cout << /*"whole:(" << whole << ")"*/  numerator << "/" << deniminator ; };

    Fraction &division(Fraction & other)
    {
        int common_denominator = deniminator * other.numerator;
        int common_numerator = numerator * other.deniminator;
        numerator = common_numerator;
        deniminator = common_denominator;
        reducter();
        return *this;
    }
    Fraction &multyplying(Fraction & other)
    {
        int common_denominator = deniminator * other.deniminator;
        int common_numerator = numerator * other.numerator;
        numerator = common_numerator;
        deniminator = common_denominator;
        reducter();
        return *this;
    }

    /*Fraction& add(const Fraction& other) { // сложение дроби с дробью
        int common_denominator = denominator * other.denominator;
        int common_numerator = numerator * other.denominator + other.numerator * denominator;
        numerator = common_numerator;
        denominator = common_denominator;
        reduce();
        */
    Fraction &addition(const Fraction& other)
    {
        
        int common_denominator = deniminator * other.deniminator;
        int common_numerator = numerator * other.deniminator + other.numerator * deniminator;
        numerator = common_numerator;
        deniminator = common_denominator;
        reducter();
        return *this;
        

    }
    Fraction &subtraction(const Fraction& other)
    {
        int common_denominator = deniminator * other.deniminator;
        int commomn_numerator = numerator * other.deniminator - other.numerator * deniminator;
        numerator = commomn_numerator;
        deniminator = common_denominator;
        reducter();
        return *this;

    }


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

int main()
{
    Fraction frac1(5, 3);
    Fraction frac2(4, 9);

    frac1.print(); cout << " + "; frac2.print(); cout << " = ";
    frac1.addition(frac2).print();
    cout << endl;

    frac1.print(); cout << " - "; frac2.print(); cout << " = " ;
    frac1.subtraction(frac2).print();
    cout << endl;

    frac1.print(); cout << " * "; frac2.print(); cout << " = " ;
    frac1.multyplying(frac2).print();
    cout << endl;

    frac1.print(); cout << " / "; frac2.print(); cout << " = " ;
    frac1.division(frac2).print();
    cout << endl;


}