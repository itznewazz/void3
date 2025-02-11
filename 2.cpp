#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream my_file("readme.txt",ios::app);
    my_file << "Line 77" << endl ;
    my_file << "Line 5" << endl ;
    my_file.close();
}


