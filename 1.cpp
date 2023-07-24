/********** BEGIN **********/
#include <iostream>
#include "ArrayList.h"

ArrayList::ArrayList()
    : size(0)
{
    capacity = 0;
    data = new int[capacity];
}

ArrayList::ArrayList(const ArrayList& rhs)
    :size(rhs.size)
{
    capacity = rhs.size;
    data = new int[capacity];
    for (int i = 0; i < rhs.size; i++)
    {
        this->data[i] = rhs.data[i];
    }
}

ArrayList::ArrayList(int const a[], int n)
    : size(n)
{
    capacity = n;
    data = new int[capacity];
    for (int i = 0; i < n; i++)
    {
        this->data[i] = a[i];
    }
}

ArrayList::ArrayList(int n, int value)
    : size(n)
{
    capacity = n;
    data = new int[capacity];
    for (int i = 0; i < n; i++)
    {
        this->data[i] = value;
    }
}

ArrayList::~ArrayList()
{
    delete[] data;
}

/********** END **********/