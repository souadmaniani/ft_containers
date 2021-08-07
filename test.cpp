#include <iostream>
#include <memory>
#include <string>
#include <stdlib.h>
#include<string.h>
#include "test.hpp"
using namespace std;

// template< class T >
// struct allocator;
template<>
struct allocator<void>;
int main()
{
       // default allocator for ints
        std::allocator<int> alloc;
        int* p = alloc.allocate(1);
        alloc.deallocate(p, 1); 
}