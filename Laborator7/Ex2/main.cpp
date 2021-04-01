#include<iostream>
using namespace std;

template<typename T>
bool sortCresc(T value1, T value2)
{
    if (value1 > value2)
        return true;
    else
        return false;
}

template<typename T>
bool sortDesc(T value1, T value2)
{
    if (value1 < value2)
        return true;
    else
        return false;
}

template <class T>
class vector
{
    T* list;
    int count = 0;
public:
    ~vector() { delete[] list; }
    void push(T value)
    {
        if (count == 0)
        {
            list = (T*)malloc(sizeof(T));
            list[0] = value;
            ++count;
        }
        else
        {
            list = (T*)realloc(list,(count+1) * sizeof(T));
            list[count] = value;
            ++count;
        }
    }
    void at(int value)
    {
        cout << list[value] << "\n";
    }
    T pop()
    {
        return list[count - 1];
    }
    void remove(int index) 
    {
        for (int i = index; i < count - 1; i++)
            list[i] = list[i + 1];
        count--;
    }
    void insert(int index, T value)
    {
        list = (T*)realloc(list, 2 * count * sizeof(T));
        for (int i = count; i > index; i--)
            list[i] = list[i - 1];
        count++;
        list[index] = value;
    }
    int count_n() { return count; }
    void print()
    {
        for (int i = 0; i < count; i++)
            cout << list[i] << ' ';
        cout << endl;
    }
    T sort(bool(*callback)(T, T))
    {
        if (callback == nullptr)
        {
            for (int i = 0; i < count - 1; i++)
                for (int j = 0; j < count - i - 1; j++)
                    if (list[j] > list[j + 1])
                    {
                        T aux = list[j];
                        list[j] = list[j + 1];
                        list[j + 1] = aux;
                    }
        }
        else
        {
            for (int i = 0; i < count - 1; i++)
                for (int j = 0; j < count - i - 1; j++)
                    if (callback(list[j], list[j + 1]))
                    {
                        T aux = list[j];
                        list[j] = list[j + 1];
                        list[j + 1] = aux;
                    }
        }
        return true;
    }
    T get_element(int index)
    {
        return &list[index];
    }
    void schimba(vector<T>& v)
    {
        int i = 0, j = 0;
        while (i < this->count && j < v.count)
        {
            T aux = this->list[i];
            this->list[i] = v.list[j];
            v.list[j] = aux;
            i++;
            j++;
        }

        if (j != v.count && i == this->count)  // this este plin dar trebuie sa mai aduc din V
        {
            this->list = (T*)realloc(this->list, v.count * sizeof(T));

            while (j < v.count)
            {
                this->list[j] = v.list[j];
                j++;
            }
        }

        if (i != this->count && j == v.count)   // v este plin dar mai trebuie sa aduc din this
        {
            v.list = (T*)realloc(v.list, this->count * sizeof(T));
            while (i < this->count)
            {
                v.list[i] = this->list[i];
                i++;
            }
        }

        int count_aux = this->count;
        this->count = v.count;
        v.count = count_aux;
    }
};

int main()
{
    vector <int> a;
    a.push(5);
    a.push(2);
    a.push(8);
    a.push(7);
    a.insert(2, 4);

    cout << "a initial: ";  a.print();

    vector <int> b;
    b.push(5);
    b.push(12);
    b.push(35);
    b.push(14);
    cout << "b initial: "; b.print();

    a.schimba(b);
    cout << "a dupa schimbare: "; a.print();
    cout << "b dupa schimbare: "; b.print();

    
    a.sort(nullptr);        // a.sort(sortCresc)
    a.print();

    a.sort(sortDesc);
    a.print();
    
    return 0;
}