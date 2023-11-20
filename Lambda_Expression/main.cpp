#include <QtCore/QCoreApplication>
#include <QtCore/qglobal.h>

#include <iostream>
#include <functional>
#include <algorithm>
#include <cmath>

/**
 *
 * @brief In C++11 and later, a lambda expression -- often called a lambda -- is a convenient way
 * of defining an anonymous function object (a closure) right at the location where it is
 * invoked or passed as an argument to a funtion.
 * Typically lambdas are used to encapsulate a few lines of code that are passed to algorithms or
 * asynchronous methods.
 *
 * https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-160
 *
 * This illustration shows the parts of a lambda:
 * [=] () mutable throw() -> int
 *  1   2   3       4         5
 * {
 * 6 is the body
 * int n = x + y;
 * x = y;
 * y = n;
 * return n;
 * }
 * 1 capture clause (Also known as the lambda-introducer in the C++ specification.)
 * 2 parameter list Optional. (Also known as the lambda declarator )
 * 3 mutable specification Optional.
 * 4 exception-specification Optional.
 * 5 trailing-return-type Optional.
 * 6 lambda body .
 */
void absSort(float* x, unsigned n){
    std::sort(x, x + n,
        //Lambda expression begins
        [](float a, float b){
        return (std::abs(a) < std::abs(b));
    }   // end of lambda expression
    );
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /// https://docs.microsoft.com/en-us/cpp/cpp/examples-of-lambda-expressions?view=msvc-160
    /// Ex1
    auto f1 = [](int x, int y) {return x + y;};

    std::cout << f1(2, 3) << std::endl;
    //Assign the same labda expr to a function object.

    std::function<int(int, int)> f2 = [](int x, int y){return x+y;};

    std::cout << f2(3, 4) << std::endl;

    /// Ex2
    int i = 3;
    int j = 5;
    // The following lambda expression captures i by value and
    // j by reference.
    std::function<int (void)> f = [i, &j] { return i + j; };
    // Change the values of i and j.
    i = 22;
    j = 44;
    // Call f and print its result.
    std::cout << f() << std::endl;

    return a.exec();
}
