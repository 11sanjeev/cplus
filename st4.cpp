
//wap in c++ implement the concept single level Inheritance
#include<iostream>
using namespace std;
class Base{
    public:
    void display(){
        cout<<"Base class"<<endl;}
    };
    class Derived:public Base{};
    int main(){
        Derived obj;
        obj.display();
        return 0;
    }
