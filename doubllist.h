
#pragma once
#include <iostream>
using namespace std;

template <typename Data>
class DoubleList
{
private:
    struct ListElement
        {
            Data         dataElement;
            ListElement *nextElement;
            ListElement *previousElement;
        };
    ListElement *top;
public:
    DoubleList()
    {
        top = nullptr;
    }
    DoubleList( Data const data )
    {
        top         = new ListElement();
        top->dataElement   = data;
        top->nextElement = nullptr;
        top->previousElement = nullptr;
    }
    DoubleList( DoubleList const &doubleList )
    {
        if( nullptr == doubleList->top )
        {
            top = nullptr;
            return;
        }
        ListElement *currentInputElement     = doubleList->top;
        ListElement *currentElement = new ListElement();
        top                         = currentElement;
        while( nullptr != currentInputElement->nextElement )
        {
            currentElement->dataElement            = currentInputElement->dataElement;
            ListElement *newElement         = new ListElement();
            newElement->previousElement    = currentElement;
            if(currentElement == top)
                currentElement->previousElement = nullptr;
            currentElement->nextElement    = newElement;
            currentElement = currentElement->nextElement;
            currentInputElement  = currentInputElement->nextElement;
        }
        currentElement->dataElement           = currentInputElement->dataElement;
        currentElement->nextElement    = nullptr;
    }
    ~DoubleList()
    {
        while( top->nextElement != nullptr )
        {

            delete top-> previousElement;
            top = top->nextElement;
        }
        delete top-> previousElement;
        delete top;
    }

    void insertLast( Data const data )
    {
        ListElement *newElement = new ListElement();
        newElement->dataElement        = data;
        newElement->nextElement = nullptr;
        if( nullptr == top )
        {
            top                 = newElement;
            top->previousElement= nullptr;
            return;
        }
        ListElement *currentElement = top;
        while( currentElement->nextElement != nullptr )
            currentElement = currentElement->nextElement;
        currentElement->nextElement    = newElement;
        newElement->previousElement = currentElement;
    }
    void insertFirst( Data const data )
    {
        ListElement *newElement = new ListElement();
        newElement->dataElement        = data;
        newElement->previousElement     = nullptr;
        if( nullptr == top )
        {
            newElement->nextElement = nullptr;
            top = newElement;
            return;
        }
        newElement->nextElement = top;
        top->previousElement    = newElement;
        top = newElement;
    }
    const bool insertAtPos( Data const data, int const pos )
    {
        if( pos < 1 )
            return false;
        if( ( nullptr == top )&&( pos > 1) )
        {
            return false;
        }
        if( ( pos == 1 ) )
        {
            insertFirst( data );
            return true;
        }
        ListElement *currentElement = top;
        for( int i = pos ; i > 2 ; --i )
        {
            if( currentElement->nextElement == nullptr )
                return false;
            currentElement = currentElement->nextElement;
        }
        ListElement *newElement    = new ListElement();
        newElement->dataElement           = data;
        newElement->previousElement = currentElement;
        if( nullptr == currentElement->nextElement )
        {
            currentElement->nextElement = newElement;
            newElement->nextElement = nullptr;
            return true;
        }
        newElement->nextElement    = currentElement->nextElement;
        currentElement->nextElement->previousElement = newElement;
        currentElement->nextElement     = newElement;
        return true;
    }

     const bool delette( Data const data )
    {
        if( top == nullptr )
            return false;
        ListElement *currentElement = top;
        int counter = 0;
        while( currentElement != nullptr )
        {
            if( currentElement->dataElement == data )
            {
                if( currentElement->previousElement != nullptr )
                    currentElement->previousElement->nextElement = currentElement->nextElement;
                else
                    top = top->nextElement;
                if( currentElement->nextElement != nullptr)
                    currentElement->nextElement->previousElement = currentElement->previousElement;
                ListElement *tmpElement = currentElement;
                currentElement = currentElement->nextElement;
                delete tmpElement;
                ++counter;
            }else{
                currentElement = currentElement->nextElement;
            }
        }
        return (counter > 0);
    }
    const bool deleteFirst()
    {
        if( nullptr == top )
        {
            return false;
        }
        if( nullptr == top->nextElement )
        {
            delete top;
            top = nullptr;
            return true;
        }
        top = top->nextElement;
        delete top->previousElement;
        return true;
    }
    void deleteLast()
    {
        if( nullptr == top )
        {
            return;
        }
        ListElement *tmpElement = top;
        while( tmpElement->nextElement != nullptr )
            tmpElement = tmpElement->nextElement;
        tmpElement->previousElement->nextElement = nullptr;
        delete tmpElement;
    }
    const bool deleteAtPos( int const pos )
    {
        if( 1 > pos )
            return false;
        if( nullptr == top )
        {
            return false;
        }
        if( ( 1 == pos ) )
        {
            deleteFirst();
            return true;
        }
        ListElement *tmpElement = top;
        for( int i = pos ; i > 1 ; --i )
        {
            if( nullptr == tmpElement->nextElement )
                return false;
            tmpElement = tmpElement->nextElement;
        }
        if( tmpElement->nextElement == nullptr )
        {
            tmpElement->previousElement->nextElement = nullptr;
            delete tmpElement;
            return true;
        }
        tmpElement->nextElement->previousElement = tmpElement->previousElement;
        tmpElement->previousElement->nextElement = tmpElement->nextElement;
        delete tmpElement;
        return true;
    }

    void clear()
    {
        while( top != nullptr )
        {
            ListElement *tmpElement = top;
            top                     = top->nextElement;
            delete tmpElement;
            tmpElement = nullptr;
        }
    }

    const Data getLast() const
    {
        if( isEmpty() )
            return 0;
        ListElement *tmpElement = top;
        while( nullptr != tmpElement->nextElement )
            tmpElement = tmpElement->nextElement;
        return tmpElement->dataElement;
    }
    const Data getFirst() const
    {
        if( isEmpty() )
            return 0;
        return top->dataElement;
    }

    const bool isContains( Data const data ) const
    {
        if( nullptr == top )
            return false;
        ListElement *tmpElement = top;
        while( nullptr != tmpElement->nextElement )
        {
            if( tmpElement->dataElement == data )
                return true;
            tmpElement = tmpElement->nextElement;
        }
        return ( tmpElement->dataElement == data );
    }
    const bool isEmpty() const
    {
        return ( nullptr == top );
    }

    const unsigned int size() const
    {
        unsigned int c = 0;
        ListElement *currentElement = top;
        while( nullptr != currentElement )
        {
            ++c;
            currentElement = currentElement->nextElement;
        }
        return c;
    }

    void print() const
    {
        if( isEmpty() )
        {
            std::cout << "There aren't elements!";
            return;
        }
        ListElement *currentElement = top;
        while( nullptr != currentElement )
        {
            std::cout << currentElement->dataElement << std::endl;
            currentElement = currentElement->nextElement;
        }
    }
    DoubleList& operator = ( DoubleList const &doubleList )
    {
        clear();
        if( nullptr == doubleList.top )
        {
            top = nullptr;
            return *this;
        }
        ListElement *tmpElement     = doubleList.top;
        ListElement *tmpElement2    = new ListElement();
        top                         = tmpElement2;
        while( nullptr != tmpElement->nextElement )
        {
            tmpElement2->dataElement           = tmpElement->dataElement;
            ListElement *tmpElement3    = new ListElement();
            tmpElement3->previousElement    = tmpElement2;
            if(tmpElement2 == top)
                tmpElement2->previousElement = nullptr;
            tmpElement2->nextElement    = tmpElement3;
            tmpElement2 = tmpElement2->nextElement;
            tmpElement  = tmpElement->nextElement;
        }
        tmpElement2->dataElement           = tmpElement->dataElement;
        tmpElement2->nextElement    = nullptr;
        return *this;
    }
};
