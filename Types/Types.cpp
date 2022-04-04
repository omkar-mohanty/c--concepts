// Types.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<cstdint>
template<typename T,typename E>
//decltype is used to determine types of complex return type
auto deceltypeDemo(T a , E b)->decltype(T{} + E{}) {
    return a + b;
}
std::vector<int> xvalue(std::vector<int>& x) {

    //x can be moved and has a identity and hence in this contxt
    //it is an xvalue
    //but here x is being sent by value 
    std::vector<int> val = std::move(x);
    val[0] = 14;
    return val;
}

std::vector<int> rvalue(std::vector<int>&& x) {
    //x has no identity but it can be moved
    std::vector<int> val = std::move(x);

    return val;
}

template<typename T>
class Matrix;

template<typename T,typename E>
auto MatrixAdd(Matrix<T>, Matrix<E>) ->Matrix<decltype(T{}+E{})> {

}

//size_t is used to hold sizeof any object ans hence it makes sense to use in 
//context of allocating memory.
void* allocate(std::size_t n) {
    void* ptr = new void* [n];

    return ptr;
}

int main()
{
    std::vector<int> pass1{ 1,2,3 };
    //auto is used for determining type at compile time 
    //for simple expressions
    auto x = xvalue(pass1);
    x[0] = 14;
    std::cout<<"After moving pass1: " <<" x1: "<<x[0]<<"\n";
    x = rvalue(std::vector<int>{4, 5, 6, 6});
    std::cout << "After moving x:" << x[0] << "\n";
    std::cout << "Deceltype : " << deceltypeDemo(1 , 2) << "\n";

    //pointer to a variable on unknown type.
    void* pv=new std::string("Hello");

    std::cout << pv << "\n";

    //int if size 16 bytes.

    int32_t y{};


    void* ptr = allocate(40);
    int* int_ptr = static_cast<int*>(ptr);
    for (int i = 0; i < 40; i++) {
        std::cout << *(int_ptr + i) << "\n";
    }

}

