#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H

#include <iostream>

class MinMaxHeap {
  public:
    //Constructor
    MinMaxHeap();

    //Class Methods
    void RecBuild(int index);
    void Build();

    void RecHeapify(int rootIndex, int level);
    void Heapify() { RecHeapify(0, 0); }

    void RecInsert(int * value, int index);
    void Insert(int * value);

    bool Delete(int value);

    void RecMinLevelElements(int rootIndex, int level);
    void RecMaxLevelElements(int rootIndex, int level);
    void MinLevelElements() { RecMinLevelElements(0,0); }
    void MaxLevelElements() { RecMaxLevelElements(0,0); }

    //Helper Functions
    int getLeftChildOf(int parentNum);
    int getRightChildOf(int parentNum);

    void IncHeap_Size() { heap_size++; }
    void DecHeap_Size() { heap_size--; }
    int GetHeap_Size() { return heap_size; }

  private:
    int ** heap_arr;
    int heap_size;
};

#endif
