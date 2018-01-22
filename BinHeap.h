//
//  BinHeap.h
//  Dz_Algoritm
//
//
//  Copyright © 2017 Ivan Slavyanskiy. All rights reserved.
//

#ifndef BinHeap_h
#define BinHeap_h
#include<iostream>
#include<fstream>
using namespace std;

// Метод swap двух значений int
void swap(int *x, int *y);

// Класс min-кучи
class MinHeap
{
public:
    int *harr; // указатель на массив значений кучи
    int capacity; // максиимально возможный размер кучи
    int heap_size; // текущее количество элементов в кучи
    int max_key;
public:
    MinHeap();
    // Констурктор с параметром
    MinHeap(int capacity);
    
    // хипифай
    void MinHeapify(int );
    
    int parent(int i) { return (i-1)/2; }
    
    // индекс левого ребенка
    int left(int i) { return (2*i + 1); }
    
    // индекс правого ребенка
    int right(int i) { return (2*i + 2); }
    
    // возвращение минимальго элемента, который является корнем
    int extractMin();
    
    // Уменьшает ключевое значение ключа в индексе i до new_val
    void decreaseKey(int i, int new_val);
    
    // Возвращает минимальный ключ (ключ от корня) с минимальной кучи
    int getMin() { return harr[0]; }
    
    // Удаляет ключ, сохраненный в индексе i
    void deleteKey(int i);
    
    // Вставляет новый ключ 'k'
    void insertKey(int k);
    void printheap();
    void printfile(string file_out);
    MinHeap merge_bin_heaps(MinHeap a, MinHeap b);
    MinHeap makeheap(MinHeap p);
    inline const int getmax();
    bool search_key(int key);
};

bool MinHeap::search_key(int key)
{
    
    for (int i=0; i< heap_size-1; i++)
        if (key == harr[i]) return true;
    
    return false;
}

inline const int MinHeap::getmax() {return  max_key; }
MinHeap::MinHeap():capacity(1), heap_size(0), harr(new int),max_key(-2147483648){};
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
    max_key = -2147483648;
}


void MinHeap::insertKey(int k)
{
    if (k>max_key) max_key=k;
    //если размер кучи равен макисмально возомжно
    //увеличиваем выделяемую память под кучу
    if (heap_size == capacity)
    {
        capacity = 2*heap_size;
        int * a = new int [capacity];
        copy(harr, harr + heap_size, a);
        harr = new int[capacity];
        copy(a,a + heap_size,harr);
        delete[] a;
    }
    
    // Сначала вставьте новый ключ в конец
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
    
    // Исправьте свойство min heap, если оно нарушено
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// Уменьшает значение ключа в индексе 'i' до new_val. Предполагается, что
// new_val меньше, чем harr [i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// Метод удаления минимального элемента (или root) из min heap
int MinHeap::extractMin()
{
    if (heap_size <= 0)
    {
        cout<< "MinHeap is empty";
        return NULL;
    }
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
    
    // Сохраняем минимальное значение и удаляем его из кучи
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    
    return root;
}


// Эта функция удаляет ключ из индекса i. Сначала он уменьшил значение до минус
//, затем вызывает extractMin ()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, getMin()-1);
    extractMin();
}

// Рекурсивный метод для heapify поддерева с корнем при заданном индексе
// Этот метод предполагает, что поддеревья уже скопированы
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
void MinHeap::printheap()
{
    int i = 0;
    int k = 1;
    while(i < heap_size)
    {
        while((i < k) && (i < heap_size))
        {
            cout << harr[i] << " ";
            i++;
        }
        cout << endl;
        k = k * 2 + 1;
    }
    
}

void MinHeap::printfile(string file_out)
{
    ofstream fout (file_out, ios::out | ios::app);
    int i = 0;
    int k = 1;
    while(i < heap_size)
    {
        while((i < k) && (i < heap_size))
        {
            fout << harr[i] << " ";
            i++;
        }
        fout << endl;
        k = k * 2 + 1;
    }
    
}


// Функция для свапа двух элементов
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
MinHeap MinHeap::makeheap(MinHeap p)
{
    for (int i=p.heap_size/2-1; i>=0; i--)
        p.MinHeapify(i);
    return p;
    
};
MinHeap MinHeap::merge_bin_heaps(MinHeap a, MinHeap b)
{
    MinHeap mearged(a.heap_size + b.heap_size);
    for (int i=0; i<a.heap_size;i++)
        mearged.harr[i]=a.harr[i];
    for (int i=0; i<b.heap_size;i++)
        mearged.harr[a.heap_size + i]=b.harr[i];
    
    
    return makeheap(mearged);
};
#endif /* BinHeap_h */
