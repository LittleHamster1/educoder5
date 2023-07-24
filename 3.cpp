#include <iostream>
#include "ArrayList.h"
#include <string>
using namespace std;

ArrayList::ArrayList() : size(0)
{
    capacity = 40;
    data = new int[capacity];
    if (data = nullptr)
    {
        string s = __func__;
        cout << s << endl;
        throw std::bad_alloc();
    }
}

ArrayList::ArrayList(const ArrayList& rhs) : size(rhs.size)
{
    capacity = rhs.size;
    data = new int[capacity];
    if (data == nullptr)
    {
        string s = __func__;
        cout << s << endl;
        throw std::bad_alloc();
    }
    for (int i = 0; i < rhs.size; i++)
    {
        this->data[i] = rhs.data[i];
    }
}

ArrayList::ArrayList(int const a[], int n) : size(n)
{
    if (n < 0)
    {
        throw std::invalid_argument("ArrayList");
    }
    capacity = n;
    data = new int[capacity];
    if (data == nullptr)
    {
        string s = __func__;
        cout << s << endl;
        throw std::bad_alloc();
    }
    for (int i = 0; i < n; i++)
    {
        this->data[i] = a[i];
    }
}

ArrayList::ArrayList(int n, int value) : size(n)
{
    if (n < 0)
    {
        throw std::invalid_argument("ArrayList");
    }
    capacity = n;
    data = new int[capacity];
    if (data == nullptr)
    {
        string s = __func__;
        cout << s << endl;
        throw std::bad_alloc();
    }
    for (int i = 0; i < n; i++)
    {
        this->data[i] = value;
    }
}

ArrayList::~ArrayList()
{
    delete[] data;
}

void ArrayList::insert(int pos, int value)
{
    if (size == capacity)
    {
        setCapacity(2 * capacity);
    }
    if (pos < 0 || pos > size)
    {
        throw std::invalid_argument("insert");
    }
    size++;
    for (int i = size - 1; i >= pos; i--)
    {
        data[i + 1] = data[i];
    }
    data[pos] = value;
}

void ArrayList::remove(int pos)
{
    if (size == 0)
    {
        return;
    }
    if (pos < 0 || pos > size)
    {
        throw std::invalid_argument("remove");
    }
    for (int i = pos; i < size; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
}

int ArrayList::at(int pos) const
{
    if (pos < 0 || pos > size)
    {
        throw std::invalid_argument("at");
    }
    return data[pos];
}

void ArrayList::modify(int pos, int newValue)
{
    if (size == 0)
    {
        return;
    }
    if (pos < 0 || pos > size)
    {
        throw std::invalid_argument("modify");
    }
    data[pos] = newValue;
}

void ArrayList::disp() const noexcept
{
    if (size == 0)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

void ArrayList::setCapacity(int newCapa)
{
    if (newCapa == 0)
    {
        return;
    }
    int* temp = new int[newCapa];
    if (temp == nullptr)
    {
        string s = __func__;
        cout << s << endl;
        throw std::bad_alloc();
    }
    for (int i = 0; i < capacity; i++)
    {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity = newCapa;
}