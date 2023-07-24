#include "ArrayList.h"

ArrayList::ArrayList()
    : data(nullptr), size(0), capacity(0)
{
    capacity = 1;
    data = new int[capacity];
}

ArrayList::ArrayList(const ArrayList& rhs)
    : data(nullptr), size(0), capacity(0)
{
    size = rhs.size;
    capacity = rhs.capacity;
    data = new int[capacity];

    for (int i = 0; i < size; i++)
    {
        data[i] = rhs.data[i];
    }
}

ArrayList::ArrayList(int const a[], int n)
    : data(nullptr), size(0), capacity(0)
{
    size = n;
    capacity = n;
    data = new int[capacity];
    for (int i = 0; i < size; i++)
    {
        data[i] = a[i];
    }
}

ArrayList::ArrayList(int n, int value)
    : data(nullptr), size(0), capacity(0)
{
    size = n;
    capacity = n;
    data = new int[capacity];
    for (int i = 0; i < size; i++)
    {
        data[i] = value;
    }
}

ArrayList::~ArrayList()
{
    delete[] data;
}

void ArrayList::setCapacity(int newCapa)
{
    if (newCapa <= capacity) return;
    int* pt = new int[capacity = newCapa];
    for (int i = 0; i < size; i++)
    {
        pt[i] = data[i];
    }
    delete[] data;
    data = pt;
}

void ArrayList::insert(int pos, int value)
{
    if (size == capacity)
    {
        setCapacity(capacity + capacity);
    }
    for (int i = size - 1; i >= pos; --i)
    {
        data[i + 1] = data[i];
    }
    data[pos] = value;
    ++size;
}

void ArrayList::remove(int pos)
{
    for (int i = pos; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    --size;
}

int ArrayList::at(int pos) const
{
    return (*this)[pos];
}

void ArrayList::modify(int pos, int newValue)
{
    (*this)[pos] = newValue;
}

ArrayList& ArrayList::operator = (const ArrayList& rhs)
{
    if (&rhs != this)
    {
        if (capacity < rhs.size)
        {
            setCapacity(rhs.size);
        }
        size = rhs.size;
        for (int i = 0; i < size; i++)
        {
            data[i] = rhs.data[i];
        }
    }
    return *this;
}

ArrayList& ArrayList::operator += (const ArrayList& rhs)
{
    if (capacity < size + rhs.size)
    {
        setCapacity(size + rhs.size);
    }
    for (int i = 0; i < rhs.size; i++)
    {
        data[i + size] = rhs.data[i];
    }
    size += rhs.size;
    return *this;
}

const int& ArrayList::operator [] (int pos) const
{
    return static_cast<const int&>((*const_cast<ArrayList*>(this))[pos]);
}

int& ArrayList::operator [] (int pos)
{
    return data[pos];
}