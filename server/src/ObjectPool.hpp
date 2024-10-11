#pragma once

#include <stack>
#include <memory>

template<class T>
class Poolable
{
public:
    void* operator new(size_t size)
    {
        if (_objects.empty())
            return std::malloc(size);

        auto ptr = _objects.top();
        _objects.pop();

        return ptr;
    }
    void operator delete(void* ptr)
    {
        _objects.push_back(static_cast<T*>(ptr));
    }
private:
    static std::stack<T*> _objects;
};

template<class T>
std::stack<T*> Poolable<T>::_objects;