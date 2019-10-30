#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H

#include <iostream>

class MinMaxHeap {
  public:
    //Constructor
    MinMaxHeap();

    //Class Methods
    void Build();

    void RecHeapify(int rootIndex, int level);
    void Heapify() { RecHeapify(0, 0); }

    bool RecInsert(int * value, int index);
    void Insert(int * value);

    bool Delete(int value);

    void RecMinLevelElements(int rootIndex, int level);
    void RecMaxLevelElements(int rootIndex, int level);
    void MinLevelElements() { RecMinLevelElements(0,0); }
    void MaxLevelElements() { RecMaxLevelElements(0,0); }

    //Helper Functions
    int getLeftChildOf(int parentNum) { return(2*parentNum+1); }
    int getRightChildOf(int parentNum) { return(2*parentNum+2); }

    void IncHeap_Size() { heap_size++; }
    void DecHeap_Size() { heap_size--; }
    int GetHeap_Size() { return heap_size; }
    int GetHeap_LastIndex() { return lastNodeIndex; }

    void PrintHeap();

    bool FindValue(int value);
    int IndexOfValue(int value);
    
  private:
    int ** heap_arr;
    int heap_size;
    int lastNodeIndex;
    bool isBalanced;
};

#endif
