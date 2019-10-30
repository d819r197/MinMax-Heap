#include <iostream>
#include <ctime>

#include "MinMaxHeap.h"

//Constructor
MinMaxHeap::MinMaxHeap() {
  heap_arr = new int*[100];
  heap_size = 0;
  lastNodeIndex = 0;
  isBalanced = true;
}

//Class Methods
void MinMaxHeap::Build(){
  int maxNodesInLevel = 1;
  int nodesInLevel = 0;
  for(int lcv = 0; lcv <= GetHeap_Size(); lcv++) {
    if(heap_arr[lcv] != nullptr) {
      std::cout << *heap_arr[lcv] <<" ";
      nodesInLevel++;
    }
    if(nodesInLevel == maxNodesInLevel) {
      std::cout << std::endl;
      maxNodesInLevel = maxNodesInLevel * 2;
      nodesInLevel = 0;
    }
  }
}

void MinMaxHeap::RecHeapify(int rootIndex, int level){
  if(heap_arr[rootIndex] != nullptr) {
    //MinNodes
    if(level % 2 == 0) {
    //   std::cout << "Left) In MinNodes comparing: ";
    //   if(heap_arr[getLeftChildOf(rootIndex)] != nullptr) {
    //     std::cout <<*heap_arr[getLeftChildOf(rootIndex)];
    //   }
    //   else {
    //     std::cout << "Nullptr";
    //   }
    //   std::cout <<" < " <<*heap_arr[rootIndex] <<".\n";
    //
    //   std::cout << "Right) In MinNodes comparing: ";
    //   if(heap_arr[getRightChildOf(rootIndex)] != nullptr) {
    //     std::cout <<*heap_arr[getRightChildOf(rootIndex)];
    //   }
    //   else {
    //     std::cout << "Nullptr";
    //   }
    //   std::cout <<" < " <<*heap_arr[rootIndex] <<".\n";

      if(heap_arr[getLeftChildOf(rootIndex)] != nullptr && *heap_arr[getLeftChildOf(rootIndex)] < *heap_arr[rootIndex]) {
        // std::cout << "Swapping: " <<*heap_arr[getLeftChildOf(rootIndex)] <<" and " <<*heap_arr[rootIndex] <<std::endl;
        int * temp = heap_arr[getLeftChildOf(rootIndex)];
        heap_arr[getLeftChildOf(rootIndex)] = heap_arr[rootIndex];
        heap_arr[rootIndex] = temp;
        RecHeapify(0, 0);
      }
      else if(heap_arr[getRightChildOf(rootIndex)] != nullptr && *heap_arr[getRightChildOf(rootIndex)] < *heap_arr[rootIndex]) {
        // std::cout << "Swapping: " <<*heap_arr[getLeftChildOf(rootIndex)] <<" and " <<*heap_arr[rootIndex] <<std::endl;

        int * temp = heap_arr[getRightChildOf(rootIndex)];
        heap_arr[getRightChildOf(rootIndex)] = heap_arr[rootIndex];
        heap_arr[rootIndex] = temp;
        RecHeapify(0, 0);
      }
      else {
        level++;
        RecHeapify(getLeftChildOf(rootIndex), level);
        RecHeapify(getRightChildOf(rootIndex), level);
      }
    }
    //Max Nodes
    else {
      // std::cout << "Left) In MaxNodes comparing: ";
      // if(heap_arr[getLeftChildOf(rootIndex)] != nullptr) {
      //   std::cout <<*heap_arr[getLeftChildOf(rootIndex)];
      // }
      // else {
      //   std::cout << "Nullptr";
      // }
      // std::cout <<" > " <<*heap_arr[rootIndex] <<".\n";
      //
      // std::cout << "Right) In MaxNodes comparing: ";
      // if(heap_arr[getRightChildOf(rootIndex)] != nullptr) {
      //   std::cout <<*heap_arr[getRightChildOf(rootIndex)];
      // }
      // else {
      //   std::cout << "Nullptr";
      // }
      // std::cout <<" > " <<*heap_arr[rootIndex] <<".\n";


      if(heap_arr[getLeftChildOf(rootIndex)] != nullptr && *heap_arr[getLeftChildOf(rootIndex)] > *heap_arr[rootIndex]) {
        // std::cout << "Swapping: " <<*heap_arr[getLeftChildOf(rootIndex)] <<" and " <<*heap_arr[rootIndex] <<std::endl;

        int * temp = heap_arr[getLeftChildOf(rootIndex)];
        heap_arr[getLeftChildOf(rootIndex)] = heap_arr[rootIndex];
        heap_arr[rootIndex] = temp;
        RecHeapify(0, 0);
      }
      else if(heap_arr[getRightChildOf(rootIndex)] != nullptr && *heap_arr[getRightChildOf(rootIndex)] > *heap_arr[rootIndex]) {
        // std::cout << "Swapping: " <<*heap_arr[getLeftChildOf(rootIndex)] <<" and " <<*heap_arr[rootIndex] <<std::endl;

        int * temp = heap_arr[getRightChildOf(rootIndex)];
        heap_arr[getRightChildOf(rootIndex)] = heap_arr[rootIndex];
        heap_arr[rootIndex] = temp;
        RecHeapify(0, 0);
      }
      else {
        level++;
        RecHeapify(getLeftChildOf(rootIndex), level);
        RecHeapify(getRightChildOf(rootIndex), level);
      }
    }
  }
}

bool MinMaxHeap::RecInsert(int * value, int rootIndex) {
  if(heap_arr[rootIndex] != nullptr) {
      if(heap_arr[getLeftChildOf(rootIndex)] == nullptr) {
        heap_arr[getLeftChildOf(rootIndex)] = value;
        lastNodeIndex = getLeftChildOf(rootIndex);
        return(true);
      }
      else if(heap_arr[getRightChildOf(rootIndex)] == nullptr) {
        heap_arr[getRightChildOf(rootIndex)] = value;
        lastNodeIndex = getRightChildOf(rootIndex);
        return(true);
      }

      else {
        if(RecInsert(value, getLeftChildOf(rootIndex))) {
          return(true);
        }
        else if(RecInsert(value, getRightChildOf(rootIndex))) {
          return(true);
        }
        return(false);
      }
  }
  return(false);
}

void MinMaxHeap::Insert(int * value) {
  if(!FindValue(*value)) {
    if(heap_arr[0] == nullptr) {
      // std::cout <<"Empty Array, adding first item.\n";
      heap_arr[0] = value;
    }
    else {
      // std::cout <<"Adding node Node at index: " <<GetHeap_Size() <<std::endl;
      heap_arr[GetHeap_Size()] = value;
      // RecInsert(value, 0);
    }
    Heapify();
    IncHeap_Size();
  }
  else {
    std::cout << "Error: Duplicate value: " <<*value <<" attempted to be inserted into the heap.\n";
  }
}

bool MinMaxHeap::Delete(int value) {
  int index = IndexOfValue(value);
  int * lastNode = heap_arr[GetHeap_Size()];

  //No Value Found
  if(index == -1) {
    return (false);
  }

  heap_arr[index] = lastNode;
  lastNode = nullptr;

  DecHeap_Size();
  Heapify();

  return true;
}

void MinMaxHeap::RecMinLevelElements(int rootIndex, int level) {
  // if(heap_arr[rootIndex] != nullptr) {
  //   //Max Nodes
  //   if(level % 2 == 0) {
  //     std::cout << "MIN) At current level: " <<level <<" with node val: ";
  //
  //     std::cout << *heap_arr[rootIndex] <<", \n" ;
  //   }
  // }
  // if(heap_arr[getLeftChildOf(rootIndex)] != nullptr) {
  //   level++;
  //   RecMinLevelElements(getLeftChildOf(rootIndex), level);
  // }
  // if(heap_arr[getRightChildOf(rootIndex)] != nullptr) {
  //   level++;
  //   RecMinLevelElements(getRightChildOf(rootIndex), level);
  // }
  int maxNodesInLevel = 1;
  int nodesInLevel = 0;
  int levels = 0;
  for(int lcv = 0; lcv <= GetHeap_Size(); lcv++) {
    if(heap_arr[lcv] != nullptr) {
      if(levels % 2 == 0) {
        std::cout << *heap_arr[lcv] <<", ";
      }
      nodesInLevel++;
    }
    if(nodesInLevel == maxNodesInLevel) {
      maxNodesInLevel = maxNodesInLevel * 2;
      nodesInLevel = 0;
      levels++;
      // std::cout <<"cur level: " <<levels <<std::endl;
    }
  }
}

void MinMaxHeap::RecMaxLevelElements(int rootIndex, int level) {
  // if(heap_arr[rootIndex] != nullptr) {
  //   //Max Nodes
  //   if(level % 2 == 1) {
  //     std::cout << "MAX) At current level: " <<level <<" with node val: ";
  //
  //     std::cout << *heap_arr[rootIndex] <<", \n";
  //   }
  // }
  // if(heap_arr[getLeftChildOf(rootIndex)] != nullptr) {
  //   level++;
  //   RecMaxLevelElements(getLeftChildOf(rootIndex), level);
  // }
  // if(heap_arr[getRightChildOf(rootIndex)] != nullptr) {
  //   level++;
  //   RecMaxLevelElements(getRightChildOf(rootIndex), level);
  // }

  int maxNodesInLevel = 1;
  int nodesInLevel = 0;
  int levels = 0;
  for(int lcv = 0; lcv <= GetHeap_Size(); lcv++) {
    if(heap_arr[lcv] != nullptr) {
      if(levels % 2 == 1) {
        std::cout << *heap_arr[lcv] <<", ";
      }
      nodesInLevel++;
    }
    if(nodesInLevel == maxNodesInLevel) {
      maxNodesInLevel = maxNodesInLevel * 2;
      nodesInLevel = 0;
      levels++;
      // std::cout <<"cur level: " <<levels <<std::endl;
    }
  }
}

void MinMaxHeap::PrintHeap() {
  std::cout <<"HEAP: ";
  for(int lcv = 0; lcv < GetHeap_Size(); lcv++) {
    if(heap_arr[lcv] != nullptr) {
      std::cout << *heap_arr[lcv] <<", ";
    }
  }
  std::cout << std::endl;
}

bool MinMaxHeap::FindValue(int value) {
  for(int lcv = 0; lcv < GetHeap_Size(); lcv++) {
    if(heap_arr[lcv] != nullptr) {
      if(*heap_arr[lcv] == value) {
        return(true);
      }
    }
  }
  return(false);
}

int MinMaxHeap::IndexOfValue(int value) {
  for(int lcv = 0; lcv < GetHeap_Size(); lcv++) {
    if(heap_arr[lcv] != nullptr) {
      if(*heap_arr[lcv] == value) {
        return(lcv);
      }
    }
  }
  return(-1);
}
