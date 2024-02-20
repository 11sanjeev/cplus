
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    // Create an output filestream object
    ofstream outFile("sample.txt");

    // Write to the file
    outFile << "Hello, this is a test file!" << endl;
    outFile << "This is the second line of the file." << endl;

    // Close the file
    outFile.close();

    // Create an input filestream object
    ifstream inFile("sample.txt");

    // Read from the file
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    // Close the file
    inFile.close();

    return 0;
}
