#include "iostream"
int main()
{
    int a =9;
    // non-const lvalue reference to type 'double' cannot 
    // bind to a value of unrelated type 'int' double &m = a;
    const double &m = a;
    a++;
    // m++;
    std::cout << &m << "|" << &a << std::endl;
}