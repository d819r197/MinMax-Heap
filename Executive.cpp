#include <iostream>
#include <string>
#include <fstream>

#include "MinMaxHeap.h"
#include "Executive.h"

#define MAXINPUT 6

Executive::Executive(std::string path) {
  filePath = path;
}

int Executive::menuInput() {
  int choice;

  std::cout << "Please choose one of the following commands: \n";
  std::cout << "1. Build Heap \n";
  std::cout << "2. Insert \n";
  std::cout << "3. Delete \n";
  std::cout << "4. MinLevelElements \n";
  std::cout << "5. MaxLevelElements \n";
  std::cout << "6. Exit \n";

  std::cout << ">> ";
  std::cin >> choice;
  std::cout << std::endl;

  return(choice);
}

void Executive::run() {
  bool quit = false;
  while(!quit) {
    switch (menuInput()) {
      //Build Heap
      case 1: {
        std::cout <<"Output: \n";
        mmHeap.Build();
        std::cout << std::endl;
        break;
      }
      //Insert
      case 2: {
        int input;
        std::cout << "Please enter the value which you want to enter into the MinMaxHeap: ";
        std::cin >> input;
        int * value = new int(input);
        mmHeap.Insert(value);
        break;
      }
      //Delete
      case 3: {
        int input;
        std::cout << "Enter the value to be deleted: ";
        std::cin >> input;
        std::cout << std::endl;
        std::cout << "Output: ";
        if(mmHeap.Delete(input)) {
          std::cout << "Deletion was successful.\n";
        }
        else {
          std::cout << "Deletion failed. The value: " <<input <<" is not present in the tree.\n";
        }
        break;
      }
      //MinLevelElements
      case 4: {
        std::cout <<"Output: ";
        mmHeap.MinLevelElements();
        std::cout << std::endl;
        break;
      }
      //MaxLevelElements
      case 5: {
        std::cout <<"Output: ";
        mmHeap.MaxLevelElements();
        std::cout << std::endl;
        break;
      }
      //Exit
      case 6: {
        std::cout <<"Output: Bye!!!\n";
        quit = true;
        break;
      }
      //Invalid Input
      default: {
          std::cout << "Please input a number between 1 and " <<MAXINPUT <<".\n\n";
          break;
      }
    }
  }
}

bool Executive::parseInputFile() {
  // pq = *mmHeap;
  std::ifstream inputFile(filePath);
  std::string input;
  char c;
  if (inputFile.is_open()) {
    while(inputFile.get(c)) {
      if (c != ' ' && c != '\n') {
        input += c;
        // std::cout <<"current input: " <<input <<std::endl;
      }
      else {
        // std::cout << "In loop, inserting: " <<input <<" into pq of size: " <<mmHeap.GetHeap_Size() <<std::endl;
        int strInt = std::stoi(input);
        int * value = new int(strInt);
        mmHeap.Insert(value);
        // mmHeap.PrintHeap();
        input = "";
      }
    }
    inputFile.close();
    return(true);
  }
  else {
    std::cout << "File Path: " <<filePath <<" is an invalid path.\n";
    return(false);
  }
}
