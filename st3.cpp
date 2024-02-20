//wap in c++ implement the concepts of copy constructor?
#include<iostream>
using namespace std;
class Myclass{
    public:
    int data;
    Myclass (int value):data(value){
        cout<<"Parameterized constructor :"<<data<<endl;
 } };
    int main(){
        Myclass obj(34),obj2=obj;
        return 0;
    }