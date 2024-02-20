#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    float marks;
public:
    void getData() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Marks: ";
        cin >> marks;
    }
    void displayData() {
        cout << "Name: " << name << "\n";
        cout << "Roll No: " << rollNo << "\n";
        cout << "Marks: " << marks << "\n";
    }
};

int main() {
    Student students[3];

    // Input student details
    for(int i = 0; i < 3; i++) {
        cout << "\nEnter details for student " << i+1 << ":\n";
        students[i].getData();
    }

    // Print student details
    cout << "\nStudent Details:\n";
    for(int i = 0; i < 3; i++) {
        cout << "\nStudent " << i+1 << ":\n";
        students[i].displayData();
    }

    return 0;
}
