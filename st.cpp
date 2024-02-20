#include<iostream>
using namespace std;
class friendclass;
class Myclass{
    public:
    void display(){
        cout<<"pointer to member function "<<endl;
    }};
    int main(){
        void (Myclass::*ptr)()=&Myclass::display;
        Myclass obj;
        (obj.*ptr)();
    return 0;
    }