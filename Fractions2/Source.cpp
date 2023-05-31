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
    double numerator;
    double deniminator;
    double whole;
public:
    Fraction(double num, double denum, double whole) : numerator{ num }, deniminator{ denum }, whole{ 0 }{};
    Fraction(double num, double denum) : Fraction{ num, denum, 0 } {};
    Fraction() : Fraction{ 0, 0, 0 } {};
    void print() { cout << "whole:(" << whole << ")" << numerator << "/" << deniminator << endl; };
    Fraction addition(Fraction frac1, Fraction frac2)
    {
        Fraction frac3;
        if (frac1.deniminator == frac2.deniminator)
        {
            frac3.deniminator = frac1.deniminator;
            frac3.numerator = frac1.numerator + frac2.numerator;
        }
        else
        {
            frac1.deniminator = frac1.deniminator * frac2.deniminator;
            frac1.numerator = frac1.numerator * frac2.deniminator;

            frac2.deniminator = frac2.deniminator * frac1.deniminator;
            frac2.numerator = frac2.numerator * frac1.deniminator;

            frac3.numerator = frac1.numerator + frac1.numerator;
            frac3.deniminator = frac2.deniminator;
        }
        reducter(frac3, frac3);
        return frac3;

    }


    int gcd(int a, int b)
    {
        while (a > 0 && b > 0)

            if (a > b)
                a %= b;

            else
                b %= a;

        return a + b;
    }
    Fraction reducter(Fraction frac, Fraction &frac3)
    {
        if (frac.deniminator > frac.numerator)
        {
            double divisor = gcd(frac.numerator, frac.deniminator);
            frac3.numerator = frac.numerator / divisor;
            frac3.deniminator = frac.deniminator / divisor;
        }
        else if (frac.deniminator < frac.numerator)
        {
            frac3.whole = frac.numerator / frac.deniminator;
            frac3.deniminator = frac.deniminator / frac.deniminator;

        }
        else if (frac.numerator == frac.deniminator)
        {
            frac3.numerator = 1;
            frac3.deniminator = 1;
        }
        return Fraction(frac3.numerator, frac3.deniminator, 0);
    }

};

int main()
{

    Fraction frac1(8, 8);
    Fraction frac2(8, 8);
    Fraction frac3 = frac3.addition(frac1, frac2);
    frac3.print();
    //Идея: сделать делегированный конструктор с двумя параметрами без целого, сделать функцию reducer, чтобы она работала по ссылке 
}