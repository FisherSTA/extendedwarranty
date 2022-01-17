// copyright 2022 Fisher St. Amour
// no rights reserved

#include <vector>
namespace ews
{
    template<typename T>
    class vMPointer
    {
    private:
        std::vector<T>& vector;
        int index;
    public:
        vMPointer(std::vector<T>& vector, T& value)
            : vector(vector)
        {
            index = &value - &vector[0];
        }
        vMPointer(vMPointer<T>& copy) : vector(copy.getVector())
        {
            index = copy.getIndex();
            vector = copy.getVector();
        }
        vMPointer(vMPointer<T>&& copy) : vector(copy.getVector())
        {
            index = copy.getIndex();
            vector = copy.getVector();
        }
        vMPointer(int index, std::vector<T>& vector) : index(index), vector(vector){};
        ~vMPointer(){}
        int getIndex() {return index;} //returns the index
        T& getValue() {return vector[index];} //returns a reference to the value pointed to
        std::vector<T>& getVector() {return vector;}
        vMPointer<T> operator +(vMPointer<T> other) {return vMPointer<T>(index + other.getIndex(), vector);}
        vMPointer<T> operator +(int other) {return vMPointer<T>(index + other, vector);}
        vMPointer<T> operator -(vMPointer<T> other) {return vMPointer<T>(index - other.getIndex(), vector);}
        vMPointer<T> operator -(int other) {return vMPointer<T>(index - other, vector);}
        vMPointer<T> operator *(vMPointer<T> other) {return vMPointer<T>(index * other.getIndex(), vector);}
        vMPointer<T> operator *(int other) {return vMPointer<T>(index * other, vector);}
        vMPointer<T> operator /(vMPointer<T> other) {return vMPointer<T>(index / other.getIndex(), vector);}
        vMPointer<T> operator /(int other) {return vMPointer<T>(index / other, vector);}
        T& operator *() {return vector[index];}
        T* operator ->() const {return &vector[index];}
    };
}