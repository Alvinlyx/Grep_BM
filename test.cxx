#include<iostream>
#include"linklist.h"
using namespace std;

int main(void)
{
    int i;
    CLinklist<int> link;
    for(i=10;i>0;i--)
    {
        link.push(i);
    }
    cout<<link;
    link.insert(11);
    cout<<link;

    link.insert(12,1);
    cout<<link;
    link.insert(13,12);
    cout << link; 
    cout << link.len()<<endl;
    return 0;
}
