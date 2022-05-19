#include <iostream>

using namespace std;

int main(){
    int* p = 0;
    cout<<*p<<endl;
    cout<<p<<endl;
    long m = 11;
    long* q = m;
    cout<<*q<<endl;
    cout<<q<<endl;
}