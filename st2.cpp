//wap in c++ implement the concepts of copy constructor?
#include<iostream>
using namespace std;
class Myclass{
    public:
    int data;
    Myclass (int value):data(value){}
    Myclass(const Myclass & other){
        data=other.data;
        cout<<"Copy constructor :"<<data<<endl;
    }};
    int main(){
        Myclass obj(34),obj2=obj;
        return 0;
    }