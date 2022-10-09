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
    static int a;
};

int Circle::a = 10;

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
    void Show() const
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

    friend Fraction operator+ (Fraction f1, Fraction f2);
    friend Fraction operator+ (Fraction f, int n);
    friend Fraction operator+ (int n, Fraction f);




    /*{
        Fraction fresult;
        fresult.numerator = this->numerator * f.denominator + this->denominator * f.numerator;
        fresult.denominator = this->denominator * f.denominator;
        return fresult;
    }

    Fraction operator+ (int n)
    {
        Fraction fresult(1, this->denominator);
        fresult.numerator = this->numerator + this->denominator * n;
        return fresult;
    }*/

};

Fraction operator+ (Fraction f1, Fraction f2)
{
    Fraction fresult;
    fresult.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
    fresult.denominator = f1.denominator * f2.denominator;
    return fresult;
}

Fraction operator+ (Fraction f, int n)
{
    Fraction fresult(1, f.denominator);
    fresult.numerator = f.numerator + f.denominator * n;
    return fresult;
}

Fraction operator+ (int n, Fraction f)
{
    return f + n;
}


class Counter
{
public:
    int count;

    friend Counter operator+(Counter c1, Counter c2);
};
Counter operator+(Counter c1, Counter c2)
{
    Counter c;
    c.count = c1.count * c2.count;
    return c;
}

int main()
{
    MyClass obj1;

    obj1.num = 100;
    obj1.id = 1234;

    cout << obj1.num << " " << MyClass::id << "\n";

    MyClass obj2;

    cout << obj1.num << " " << MyClass::id << "\n";

    MyClass::id = 5555;

    cout << obj1.num << " " << MyClass::id << "\n";

    MyClass::Show();

    // -----------------------------


    Fraction f1(3, 5);
    Fraction f2(2, 7);

    Fraction f3 = 5 + f1;
    f3.Show();

    int x = 6;
    float y = 4.5;

    /*f1.Add(f2);

    Fraction f3(4, 7);
    f1.Show(); cout << "\n";
    
    f1.Add(f2).Mult(f3).Del(f1).Show();
    
    f1.Show(); cout << "\n";

    Math::Sin(12);*/
}
