

#ifndef QUEUE_MYLIST_H
#define QUEUE_MYLIST_H
#include <iostream>
using namespace std;
template<typename T>
class MyList {
public:
    // Конструктор по умолчанию
    MyList(){
        vals = nullptr;
        size = 0;
    }
    // Конструктор с параметром 1
    explicit MyList(int s){
        vals = new T[s];
        size = s;
    }
    // Конструктор с параметром 2
    MyList(T* arr,int arr_size){
        size = arr_size;
        vals = new T[arr_size];
        for (int i = 0; i < size; ++i)
            vals[i] = arr[i];
    }
    // Конструктор копирования
    MyList(MyList const &list){
        size = list.size;
        vals = new T[size];
        for (int i = 0; i < size; ++i)
            vals[i] = list.vals[i];
    }
    // Деструктор
    ~MyList() {
        delete[] vals;
    }
    // Размер
    int Size(){
        return size;
    }
    // Первый элемент
    T& front(){
        return vals[0];
    }
    // Последний элемент
    T& back(){
        return vals[size-1];
    }
    void push_back(T v){
        T* temp = new T[size+1];
        for (int i = 0; i < size; ++i)
            temp[i] = vals[i];
        temp[size] = v;
        vals = temp;
        size ++;
    }
    void push_front(T v){
        T* temp = new T[size+1];
        for (int i = 0; i < size; ++i)
            temp[i+1] = vals[i];
        temp[0] = v;
        vals = temp;
        size++;
    }
    void pop_back(){
        size--;
    }
    void pop_front(){
        vals++;
        size--;
    }
    void insert(int pos, T value){
        T* temp = new T[size+1];
        size++;
        for (int i = 0; i < pos; ++i)
            temp[i] = vals[i];
        temp[pos] = value;
        for (int i = pos+1; i < size; ++i) {
            temp[i] = vals[i-1];
        }
        vals = temp;

    }
    bool isEmpty(){
        return size == 0;
    }
    friend ostream& operator<<(ostream& ostr,MyList<T> l){
        ostr << "( ";
        for (int i = 0; i < l.size-1; ++i)
            ostr << l.vals[i] << ", ";
        ostr << l.vals[l.size-1] << " )" << endl;
    }
private:
    T* vals;
    int size;
};



#endif //QUEUE_MYLIST_H
