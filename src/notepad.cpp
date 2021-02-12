#include "s23578/19ToDo.h"
#include <iostream>
#include <string>
#include <vector>
struct MyToDo ToDoList[100];

bool addToList(string description, int priority, string dueDate) {

  if (listSize < 101) {
    MyToDo y = {description, priority, dueDate};
    ToDoList[listSize] = y;
    listSize++;

    return true;
  } else {
    return false;
  }
}
bool getNextItem(MyToDo &mytodo) {
  if (listSize == 0) {

    return false;
  } else if (listSize < positionInList) {
    positionInList = 0;
    mytodo = ToDoList[positionInList];
    positionInList++;
  } else {
    mytodo = ToDoList[positionInList];
    positionInList++;
  }
  return true;
}
bool getByPriority(MyToDo matches[100], int search) {
  int count = 0;

  for (int i = 0; i < listSize; i++) {
    if (ToDoList[i].priority == search) {
      matches[count] = ToDoList[i];
      count++;
    }
  }

  return true;
}
void printToDo() {

  for (int i = 0; i < listSize; i++) {

    std::cout << ToDoList[i].description << std::endl;
    std::cout << ToDoList[i].priority << std::endl;
    std::cout << ToDoList[i].dueDate << std::endl;
    std::cout << "" << std::endl;
  }
}

bool addToList(string description, int priority, string dueDate);
bool getNextItem(MyToDo &mytodo);
bool getByPriority(MyToDo matches[100], int search);
void printToDo();

int notepad() {
  int choice = 0;
  char nextmove = 'y';

  while ('y' == nextmove) {
    std::cout << "This will keep of the things you need to do!" << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1. Add to my to do list" << std::endl;
    std::cout << "2. Display the next item in my list" << std::endl;
    std::cout << "3. Search for activites of a certain priority" << std::endl;
    std::cout << "4. Print out my whole list" << std::endl;

    std::cin >> choice;

    if (choice == 1) {
      string description;
      int priority;
      string dueDate;

      std::cout << "what is the description of the activity?" << std::endl;
      std::cin.ignore();
      getline(std::cin, description);
      std::cout << "how urgent is this? rank 1-5. 1 for not really important, "
                   "5 for very important"
                << std::endl;
      std::cin >> priority;
      std::cout << "when is the due date? is day/month format" << std::endl;
      std::cin >> dueDate;

      addToList(description, priority, dueDate);
    } else if (choice == 2) {

      MyToDo y;

      getNextItem(y);

      std::cout << "Description: " << y.description << std::endl;
      std::cout << "Priority :" << y.priority << std::endl;
      std::cout << "Due Date :" << y.dueDate << std::endl;

    } else if (choice == 3) {
      struct MyToDo matches[100];
      int search = 0;

      std::cout << "Enter a priority level to search for 1-5" << std::endl;
      std::cin >> search;

      getByPriority(&matches[100], search);
      for (int i = 0; i < 10; i++) {
        std::cout << "Description: " << matches[i].description << std::endl;
        std::cout << "Priority : " << matches[i].priority << std::endl;
        std::cout << "Due Date : " << matches[i].dueDate << std::endl;
      }
    } else if (choice == 4) {

      printToDo();
    } else {
      std::cout << "That was an incorrect choice!" << std::endl;
    }
    std::cout << "would you like to keep playing? y for YES" << std::endl;
    std::cin >> nextmove;
  }

  std::cout << "Good job keeping yourself on schedule!" << std::endl;
  return 0;
}
