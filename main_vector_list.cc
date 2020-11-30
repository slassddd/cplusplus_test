#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> v1;
    list<int> l1;
    cout << "v1: ";
    for(int i=0; i!=10;i++){
        v1.push_back(i);
        l1.push_back(i);
        cout << v1[i] << "  ";
    }
    cout << endl;
    list<int>::iterator i;
    cout << "l1: ";
    for(i = l1.begin();i!=l1.end();i++){
        cout << *i << "  ";
    }
    cout << endl;
    fill(l1.begin(),l1.end(),0);
    cout << "l1: ";
    for(i = l1.begin();i!=l1.end();i++){
        cout << *i << "  ";
    }    
    cout << endl;
    return 0;
}
