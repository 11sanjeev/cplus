#include <iostream>
using namespace std;

class geeks {
    const char* p;
public:
    geeks () {
        p = new char[6];
        p = "geeks";
    }
    void display () {
        cout << p << endl;
    }
};

int main () {
    geeks obj;
    obj.display ();
}
