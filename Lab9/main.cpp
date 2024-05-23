#include <iostream>

using namespace std;

template <class K, class V>
struct Pair
{
    K key;
    V value;
    int index;
};

template <class K, class V>
class Map
{
public:
    Pair<K, V>* pairs;
    int count;
    int capacity;
    Map()
    {
        capacity = 50;
        count = 0;
        pairs = new Pair<K, V>[capacity];
    }
    ~Map()
    {
        Clear();
        delete[] pairs;
    }

    Pair<K, V>* begin()
    {
        return &pairs[0];
    }

    Pair<K, V>* end()
    {
        return &pairs[count];
    }

    V& operator[](const K& key)
    {
        for (int i = 0; i < count; i++)
            if (pairs[i].key == key)
                return pairs[i].value;


        if (count == capacity)
        {
            capacity *= 2;
            Pair<K, V>* newPairs = new Pair<K, V>[capacity];
            for (int i = 0; i < count; i++)
                newPairs[i] = pairs[i];
            delete[] pairs;
            pairs = newPairs;
        }

        pairs[count].key = key;
        pairs[count].value = V();
        pairs[count].index = count;
        return pairs[count++].value;
    }
    void Set(const K& key, const V& value)
    {
        (*this)[key] = value;
    }

    bool Get(const K& key, V& value)
    {
        for (int i = 0; i < count; ++i)
            if (pairs[i].key == key)
            {
                value = pairs[i].value;
                return true;
            }
        return false;
    }

    int Count()
    {
        return count;
    }

    void Clear()
    {
        count = 0;
    }

    bool Delete(const K& key)
    {
        for (int i = 0; i < count; ++i)
            if (pairs[i].key == key)
            {
                for (int j = i; j < count - 1; ++j)
                    pairs[j] = pairs[j + 1];
                count--;
                return true;
            }
        return false;
    }

    bool Includes(const Map<K, V>& other)
    {
        for (int i = 0; i < other.count; ++i)
        {
            V value;
            if (!Get(other.pairs[i].key, value) || value != other.pairs[i].value)
                return false;
        }
        return true;
    }
};

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
