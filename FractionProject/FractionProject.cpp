#include <iostream>

using namespace std;

static class Math
{
public:
    int n;
    static double Sin(double x)
    {
        return sin(x);
    }
};

class MyClass
{
public:
    int num;
    static int id;

    MyClass()
    {
        num = 0;
        id = 10;
    }

    static void Show()
    {
        cout << id;
    }
};

int MyClass::id = 0;


class Circle
{
    const double PI = 3.14156;
    int x, y, radius;
public:
    
};

class Fraction
{
    int numerator;
    int denominator;
public:
    Fraction(int numerator = 0, int denominator = 1) :
        numerator{ numerator }, denominator{ denominator }
    {
        cout << this << " fraction constract\n";
        if (!denominator)
            this->denominator = 1;
    }
    int GetNumerator() const { return numerator; }
    int GetDenominator() const { return denominator; }
    void SetNumerator(int numerator) { this->numerator = numerator; }
    void SetDenominator(int denominator) 
    { 
        if (!denominator)
            this->denominator = denominator;
    }
    void Show()
    {
        cout << "[" << numerator << "/" << denominator << "]";
    }

    Fraction Add(const Fraction& f)
    {
        Fraction fresult;
        fresult.numerator = this->numerator * f.denominator + this->denominator * f.numerator;
        fresult.denominator = this->denominator * f.denominator;
        return fresult;
    }

    Fraction Del(Fraction f)
    {
        Fraction fresult;
        fresult.numerator = this->numerator * f.denominator - this->denominator * f.numerator;
        fresult.denominator = this->denominator * f.denominator;
        return fresult;
    }

    Fraction Mult(Fraction f)
    {
        Fraction fresult;
        fresult.numerator = this->numerator * f.numerator;
        fresult.denominator = this->denominator * f.denominator;
        return fresult;
    }

    Fraction Div(Fraction f)
    {
        Fraction fresult;
        fresult.numerator = this->numerator * f.denominator;
        fresult.denominator = this->denominator * f.numerator;
        return fresult;
    }
};

int main()
{
    MyClass obj1;
    //MyClass obj2;

    obj1.num = 100;
    obj1.id = 1234;

    cout << obj1.num << " " << MyClass::id << "\n";

    MyClass obj2;

    cout << obj1.num << " " << MyClass::id << "\n";

    MyClass::id = 5555;

    cout << obj1.num << " " << MyClass::id << "\n";

    MyClass::Show();

   /* Fraction f1(3, 5);
    Fraction f2(2, 7);
    f1.Add(f2);*/

    //Fraction f3(4, 7);
    //f1.Show(); cout << "\n";
    
    //f1.Add(f2).Mult(f3).Del(f1).Show();
    
    //f1.Show(); cout << "\n";

    Math::Sin(12);
}
