#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    fstream file("example.txt",ios::trunc);
    if(file){
        file<<"Hello ,this is a file \n ";
        file.seekg(0);
        string line;
        while(getline(file,line))
        cerr<<line<<endl;
        file<<"Adding a new line to the file \n";
        file.seekg(0);
        while(getline(file ,line ))
        cerr<<line<<endl;
        file.close();
    }
    else 
    cerr<<"unable to open the file \n";
    return 0;
}