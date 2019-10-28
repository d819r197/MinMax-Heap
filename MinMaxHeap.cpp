#include <iostream>
#include <ctime>

#include "MinMaxHeap.h"

//Constructor
MinMaxHeap::MinMaxHeap() {
  heap_arr = new int*[100];
  heap_size = 0;
}

//Class Methods
void MinMaxHeap::RecBuild(int index){

}

void MinMaxHeap::Build(){

}

void MinMaxHeap::RecHeapify(int rootIndex, int level){
  if(heap_arr[rootIndex] != nullptr) {
    //MinNodes
    if(level % 2 == 0) {
      if(heap_arr[getLeftChildOf(rootIndex)] != nullptr && heap_arr[getLeftChildOf(rootIndex)] < heap_arr[rootIndex]) {
        int * temp = heap_arr[getLeftChildOf(rootIndex)];
        heap_arr[getLeftChildOf(rootIndex)] = heap_arr[rootIndex];
        heap_arr[rootIndex] = temp;
        RecHeapify(0, 0);
      }
      else if(heap_arr[getRightChildOf(rootIndex)] != nullptr && heap_arr[getRightChildOf(rootIndex)] < heap_arr[rootIndex]) {
        int * temp = heap_arr[getRightChildOf(rootIndex)];
        heap_arr[getRightChildOf(rootIndex)] = heap_arr[rootIndex];
        heap_arr[rootIndex] = temp;
        RecHeapify(0, 0);
      }
      else {
        RecHeapify(getLeftChildOf(rootIndex), level++);
        RecHeapify(getRightChildOf(rootIndex), level++);
      }
    }
    //Max Nodes
    else {
      if(heap_arr[getLeftChildOf(rootIndex)] != nullptr && heap_arr[getLeftChildOf(rootIndex)] > heap_arr[rootIndex]) {
        int * temp = heap_arr[getLeftChildOf(rootIndex)];
        heap_arr[getLeftChildOf(rootIndex)] = heap_arr[rootIndex];
        heap_arr[rootIndex] = temp;
        RecHeapify(0, 0);
      }
      else if(heap_arr[getRightChildOf(rootIndex)] != nullptr && heap_arr[getRightChildOf(rootIndex)] > heap_arr[rootIndex]) {
        int * temp = heap_arr[getRightChildOf(rootIndex)];
        heap_arr[getRightChildOf(rootIndex)] = heap_arr[rootIndex];
        heap_arr[rootIndex] = temp;
        RecHeapify(0, 0);
      }
      else {
        RecHeapify(getLeftChildOf(rootIndex), level++);
        RecHeapify(getRightChildOf(rootIndex), level++);
      }
    }
  }
}

void MinMaxHeap::RecInsert(int * value, int rootIndex) {
  if(heap_arr[rootIndex] != nullptr) {
      if(heap_arr[getLeftChildOf(rootIndex)] == nullptr) {
        heap_arr[getLeftChildOf(rootIndex)] = value;
      }
      else if(heap_arr[getRightChildOf(rootIndex)] == nullptr) {
        heap_arr[getRightChildOf(rootIndex)] = value;
      }
      else {
        RecInsert(value, getLeftChildOf(rootIndex));
        RecInsert(value, getRightChildOf(rootIndex));
      }
  }
}

void MinMaxHeap::Insert(int * value) {
  if(heap_arr[0] == nullptr) {
    // std::cout <<"Empty Array, adding first item.\n";
    heap_arr[0] = value;
  }
  else {
    // std::cout <<"First Node: " <<*heap_arr[0] <<std::endl;
    RecInsert(value, 0);
  }
  IncHeap_Size();
}

bool MinMaxHeap::Delete(int value) {
  // DecHeap_size();
  return true;
}

void MinMaxHeap::RecMinLevelElements(int rootIndex, int level) {
  if(heap_arr[rootIndex] != nullptr) {
    //Max Nodes
    if(level % 2 == 0) {
      std::cout << *heap_arr[rootIndex] <<", " ;
    }
  }
  if(heap_arr[getLeftChildOf(rootIndex)] != nullptr) {
    RecMinLevelElements(getLeftChildOf(rootIndex), level++);
  }
  if(heap_arr[getRightChildOf(rootIndex)] != nullptr) {
    RecMinLevelElements(getRightChildOf(rootIndex), level++);
  }
}

void MinMaxHeap::RecMaxLevelElements(int rootIndex, int level) {
  if(heap_arr[rootIndex] != nullptr) {
    //Max Nodes
    if(level % 2 == 1) {
      std::cout << *heap_arr[rootIndex] <<", ";
    }
  }
  if(heap_arr[getLeftChildOf(rootIndex)] != nullptr) {
    RecMaxLevelElements(getLeftChildOf(rootIndex), level++);
  }
  if(heap_arr[getRightChildOf(rootIndex)] != nullptr) {
    RecMaxLevelElements(getRightChildOf(rootIndex), level++);
  }
}

//Helper Functions
int MinMaxHeap::getLeftChildOf(int parentNum) {
  return(2*parentNum+1);
}

int MinMaxHeap::getRightChildOf(int parentNum) {
  return(2*parentNum+2);
}
