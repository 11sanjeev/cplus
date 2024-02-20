#include<iostream>
using namespace std;
template<class T1,class T2>
class a{
    public:
    T1 x;
    T2 y;
    a (T1 i, T2 j){
        x = i;
        y = j;

    }
    void display(){
        cout<<this-> x<<endl<<this-> y;

    }
};
int main(){
    a <char,float>obj('c',2.4);
    obj.display();
    return 0;
}