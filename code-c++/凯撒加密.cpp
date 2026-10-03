#include <iostream>
using namespace std;

int main() {
    int a;
    cin>>a;
    string password;
    cin>> password;
    for(auto p=password.begin();p!=password.end();p++)
    {
        *p=(*p-'a'+a)%26+'a';
        cout<<*p;
    }
}
