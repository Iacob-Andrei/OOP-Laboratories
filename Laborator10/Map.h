#pragma once
#include <iostream>
using namespace std;

template <typename A, typename B>

class Map
{
    int index;
    struct mapping
    {
        A key;
        B value;
        int ordine;
    };
    mapping k[100];

public:
    Map() { index = 0; }

    B& operator[](A keye)
    {
        for (auto& x : k)
            if (x.key == keye)
                return x.value;
         
        if (index < 100)
        {
            k[index].key = keye;
            k[index].ordine = index;
            index += 1;
            return k[index - 1].value;
        }

        return k[0].value;

    }

    void Set(A keye, B valoare)
    {
        (*this)[keye] = valoare;
    }

    bool Get(const A& key, B& value)
    {
        for (auto [keye, valoare, index] : (*this))
            if (keye == key)
            {
                value = valoare;
                return true;
            }
        return false;
    }

    mapping* begin() { return &k[0]; }

    mapping* end() { return &k[index]; }

    int Count() { return index; }

    void Clear() { index = 0; }

    bool Delete(const A& keye)
    {
        int i, pozitie = -1;

        for (i = 0; i < index; i++)
            if (keye == k[i].key)
            {
                pozitie = i;
                break;
            }

        if (pozitie == -1)
            return false;

        for (i = pozitie; i < index; i++)
        {
            k[i] = k[i + 1];
            k[i].ordine--;
        }
        index--;
        return true;
    }

    bool Includes(const Map<A, B>& map)
    {
        int i, j , flag;

        if (this->index <= map.index) 
        {

            for (i = 0; i < this->index; i++)
            {   
                flag = 0;
                for (j = 0 ; j < map.index; j++)
                    if (this->k[i].key == map.k[j].key )
                        {
                            flag = 1;
                            break;
                        }
                if (flag == 0)
                    return false;
            }

        }
        else
        {
            for (i = 0; i < map.index; i++)
            {
                flag = 0;
                for (j = 0 ; j < this->index; j++)
                    if (this->k[i].key == map.k[j].key)
                        {
                            flag = 1;
                            break;
                        }
                if (flag == 0)
                    return false;
            }
        }

        return true;
    }
};