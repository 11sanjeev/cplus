#include<iostream>
#include<fstream>
using namespace std;

int main() {
    // Create and open a text file
    ofstream MyFile("example.txt");

    // Write to the file
    MyFile << "Hello, World!";

    // Close the file
    MyFile.close();

    // String to hold the text from the file
    string text;

    // Open the file in read mode
    ifstream MyReadFile("example.txt");

    // Read from the file
    getline(MyReadFile, text);

    // Close the file
    MyReadFile.close();

    // Append to the text
    text += " Welcome to C++ programming.";

    // Open the file in write mode
    ofstream MyWriteFile("example.txt");

    // Write the modified text to the file
    MyWriteFile << text;

    // Close the file
    MyWriteFile.close();

    // Reopen the file in read mode
    ifstream MyNewReadFile("example.txt");

    // Read the modified text from the file
    while (getline(MyNewReadFile, text)) {
        // Output the text from the file
        cout << text;
    }

    // Close the file
    MyNewReadFile.close();

    return 0;
}
