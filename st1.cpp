//wap in c++ implement the concept constructor with arguments &destructor
#include<iostream>
using namespace std;
class Myclass{
    public:
    int data;
    Myclass(int value){data = value;
        cout<<"Constructor:"<<data<<endl;
    }
    ~Myclass(){cout<<"Destructor:"<<data<<endl;}

};
int main(){
    Myclass obj(53);
    return 0;
}