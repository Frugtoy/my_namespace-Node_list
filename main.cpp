#include<iostream>
#include"nodelist.h"
using my_namespace::Node_list;
using std::cin;
using std::cout;



int main() {
    Node_list <int> l;
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    for(int i = 0 ; i<l.get_size();++i)
    {
        cout<<"the ["<<i<<"] element of list is: "<<l[i]<<";"<<std::endl;
    }

}