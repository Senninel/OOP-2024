#pragma once
#include<exception>

using namespace std;

class IndexOut : public exception
{
    virtual const char* what() const throw()
    {
        return "Indexul este inafara domeniului";
    }
};
class SizeBiggerOrQualThanCap : public exception
{
    virtual const char* what() const throw()
    {
        return "Size-ul mai mare sau egal decat capacitatea";
    }
};
class CapacityAloc : public exception
{
    virtual const char* what() const throw()
    {
        return "Eroare alocare capacitate";
    }
};
class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T>
class ArrayIterator
{
private:
    T** list;
    int Current;
public:
    ArrayIterator(T** List, int start)
    {
        this->list = List;
        this->Current = start;
    }
    ArrayIterator& operator++()
    {
        this->Current++;
        return *this;
    }
    ArrayIterator& operator--()
    {
        this->Current--;
        return *this;
    }
    bool operator==(ArrayIterator<T>& cmp)
    {
        return *this == cmp;
    }
    bool operator!=(ArrayIterator<T>& cmp)
    {
        return *this != cmp;
    }
    T* GetElement()
    {
        return this->list[this->Current];
    }
};
template<class T>
class Array
{
private:
    T** List; 
    int Capacity; 
    int Size;
public:
    Array()
    {
        this->Capacity = this->Size = 0;
        this->List = nullptr;
    }
    ~Array()
    {
        for (int i = 0;i < this->Size; i++)
            if (this->List[i]) delete this->List[i];
        delete[] this->List;
    }
    Array(int capacity)
    {
            if (capacity < 0)
                throw CapacityAloc();
            this->Capacity = capacity;
            this->Size = 0;
            this->List = nullptr;
        
    }
    Array(const Array<T>& otherArray)
    {
        this->Capacity = otherArray.Capacity;
        this->Size = otherArray.Size;
        this->List = new T * [this->Capacity];
        for (int i = 0; i < this->Size; i++)
            this->List[i] = new T(*otherArray.List[i]);
    }

    T& operator[] (int index)
    {
        if (index < 0 || index >= this->Size)
            throw IndexOut;
        return *this->List[index];
    }

    const Array<T>& operator+=(const T& newElem)
    {
        if (this->Size >= this->Capacity)
            throw SizeBiggerOrQualThanCap;
        this->List[this->Size++] = new T(newElem);
        return *this;
    }
    const Array<T>& Insert(int index, const T& newElem)
    {
        if (index < 0 || index > this>Size)
            throw IndexOut;
        if (this->Size >= this->Capacity)
            throw SizeBiggerOrQualThanCap;
        for (int i = this->Size; i > index; i--)
            this->List[i] = new T(this->List[i - 1]);
        this->List[index] = new T(newElem);
        this->Size++;
        return *this;
    }
    const Array<T>& Insert(int index, const Array<T> otherArray)
    {
        if (index < 0 || index > this > Size)
            throw IndexOut;
        if (this->Size + otherArray.Size >= this->Capacity)
            throw SizeBiggerOrQualThanCap;
        for (int i = this->Size - 1; i > index; i--)
            this->List[i + otherArray.Size] = new T(this->List[i]);
        for (int i = 0; i < otherArray.Size;i++)
        {
            this->List[index + i] = new T(*otherArray.List[i]);
        }
    }
    const Array<T>& Delete(int index)
    {
        if (index < 0 || index > this > Size)
            throw IndexOut;
        for (int i = index; i < this->Size - 2; i--)
            this->List[i] = this->List[i + 1];
        delete this->List[this->Size - 2];
        this->List[this->Size] = nullptr;
        this->Size--;
    }
    bool operator=(const Array<T>& otherArray)
    {
        if (*this == otherArray) return true;
        for (int i = 0; i < this->Size; i++)
            delete this->List[i];
        delete[] this->List;
        this->Capacity = otherArray.Capacity;
        this->Size = otherArray.Size;
        this->List = new T * [Capacity];
        for (int i = 0; i < Size; i++)
            this->List[i] = new T(otherArray.List[i]);
        return true;
    }
    void Sort()
    {
        for(int i=0; i < this->Size - 2;i++)
            for(int j=i+1; j<this->Size-1;j++)
                if (this->List[i] > this->List[j])
                {
                    T* aux = List[i];
                    this->List[i] = this->List[j];
                    this->List[j] = aux;
                }

    }
    void Sort(int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < this->Size - 2;i++)
            for (int j = i+1; j < this->Size - 1;j++)
                if (compare(this->List[i], this->List[j]) > 0)
                {
                    T* aux = List[i];
                    this->List[i] = this->List[j];
                    this->List[j] = aux;
                }
    }
    void Sort(Compare* comparator)
    {
        for (int i = 0; i < this->Size - 2;i++)
            for (int j = i+1; j < this->Size - 1;j++)
                if (comparator->CompareElements(this->List[i], this->List[j]) > 0)
                {
                    T* aux = List[i];
                    this->List[i] = this->List[j];
                    this->List[j] = aux;
                }
    }

    int BinarySearch(const T& elem)
    {
        int left = 0, right = this->Size - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (List[mid] == elem) return true;
            if (List[mid] > elem) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
    {
        int left = 0, right = this->Size - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (compare(List[mid], elem) == 0) return mid;
            else if (compare(List[mid], elem) < 0) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, Compare* comparator)
    {
        int left = 0, right = this->Size - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (comparator->CompareElements(List[mid], &elem) == 0) return mid;
            else if (comparator->CompareElements(List[mid], &elem) < 0) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem)
    {
        for (int i = 0;i <this->Size;i++)
            if (*List[i] == elem) return 1;
        return -1;
    }
    int Find(const T& elem, int(*compare)(const T&, const T&))
    {
        for (int i = 0;i <this->Size;i++)
          if (compare(List[i], elem) == 0) return 1;
        
        return -1;
    }
    int Find(const T& elem, Compare* comparator)
    {
        for (int i = 0;i < this->Size;i++)
         if (comparator->CompareElements(List[i], &elem) == 0) return 1;
        return -1;
    }

    int GetSize()
    {
        return this->Size;
    }
    int GetCapacity()
    {
        return this->Capacity;
    }

    ArrayIterator<T> GetBeginIterator()
    {
        return ArrayIterator<T>(this->List, 0);
    }
    ArrayIterator<T> GetEndIterator()
    {
        return ArrayIterator<T>(this->List, this->Size);
    }
};


