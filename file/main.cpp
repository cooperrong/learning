#include<iostream>
#include<fstream>
using namespace std;

void test(){

    char data[100];
    ofstream file;
    file.open("test.txt",ios::app);
    cout<<"Write to the file"<<endl;
    cout<<"enter your name: ";
    cin>>data;
    cin.ignore();

    file<<data<<endl;

    file.close();

    ifstream infile;
    infile.open("test.txt");
    cout<<"read for the file"<<endl;
    infile>>data;
    
    cout<<data<<endl;

    infile>> data;
    cout<<data<<endl;

    infile>> data;
    cout<<data<<endl;
    infile.close();
}

int main(){

    test();


    system("pause");
    return 0;
}