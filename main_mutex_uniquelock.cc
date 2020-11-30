#include<iostream>
#include<thread>
#include<mutex>
#include<unistd.h>
#include"add.h"
using namespace std;

mutex mylock;

void do1(void){
    // unique_lock<mutex> lock(mylock);
    int idx = 1;
    while(1){
        cout << "1 " << idx << endl;
        idx++;
        usleep(500000);
        if (idx == 5)
            break;
    }
    {
        unique_lock<mutex> lock(mylock);        
        while(1){
            cout << "1 " << idx << endl;
            idx++;
            usleep(500000);
            if (idx == 31)
                break;
        }  
    }  
}

void do2(void){
    int idx = 1;
    {
        unique_lock<mutex> lock(mylock);
        while(1){
            cout << "2 " << idx << endl;
            idx++;
            usleep(500000);
            if (idx == 10)
                break;        
        }
        mylock.unlock();
    }
    while(1){
        cout << "2 " << idx << endl;
        idx++;
        usleep(500000);
        if (idx>20)
            unique_lock<mutex> lock(mylock);
        if (idx == 31)
            break;        
    }    
}

int main(int argc, char const *argv[])
{
    thread th1(do1);
    thread th2(do2); 
    th1.join();
    th2.join();
    return 0;
}

