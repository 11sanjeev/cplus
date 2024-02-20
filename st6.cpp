//wap in c++ implement the concept hierarchial level Inheritance
#include<iostream>
using namespace std;
class Base{
    public:
    void display(){
        cout<<"Base class"<<endl;}
    };
    class Derived1:public Base{};
    class Derived2:public Base{};
    int main(){
        Derived1 obj;
        obj.display();
        Derived2 obj2;
        obj2.display();
        return 0;
    }
