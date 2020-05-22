#include <iostream>
#include "doubllist.h"
#include <string>
using namespace std;

int main()
{
    DoubleList<char> list1;
    list1.print();
    cout<<endl;
    list1.insertFirst('A');
    cout<<"\tSize: "<< list1.size() <<endl<<endl;
    list1.insertLast('B');
    cout<<"\tSize: "<< list1.size() <<endl<<endl;
    list1.insertAtPos('D', 2);
    cout<<"\tSize: "<< list1.size() <<endl<<endl;
    list1.insertLast('D');
    cout<<"\tSize: "<< list1.size() <<endl<<endl;
    list1.print();
    cout<<"\tSize: "<< list1.size() <<endl<<endl;
    list1.deleteAtPos(3);
    list1.print();
    cout<<"\tSize: "<< list1.size() <<endl<<endl;
    list1.deleteLast();
    list1.print();
    cout<<"\tSize: "<< list1.size() <<endl<<endl;
    list1.delette( 'D' );
    list1.print();
    cout<<"\tSize: "<< list1.size() <<endl<<endl;
    DoubleList<char> list2('l');
    list2.print();
    cout<<endl;
    list1 = list2;
    list1.print();
    cout<<endl;
    return 0;
}
