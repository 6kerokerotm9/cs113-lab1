/*
Joshua Sjah
CS 113
February 6, 2019
This program prints out truth tables based off of user selected operations. 
*/

#include <iostream>
#include <iomanip>

//function declarations
bool negation(bool);
bool conjunction(bool, bool);
bool disjunction(bool, bool);
bool exclusiveor(bool, bool);
void print(bool);
void change(bool *, bool *, int); 
void printhead(std::string[], std::string, std::string);
void printhead(std::string[], std::string);
void input(std::string[]);
void onevars(std::string[], std::string, std::string, bool, bool);
void twovars(std::string[], std::string, std::string, bool, bool);

int main() {
  //variable declarations
  std::string prop1;
  std::string prop2; 
  std::string name;
  bool value1;
  bool value2;
  char exitinput; 
  
  while(true) {
    std::string choices[4];
    std::cout << "Hello, please enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Welcome, " << name << ", please enter the name for the first proposition: ";
    std::getline(std::cin, prop1);   
    std::cout << "Please enter the name of the second proposition (press enter if you only want one proposition): ";
    std::getline(std::cin, prop2);
    input(choices);
    std::cout << "Thank you. Here is the table for ";
    for(int i=0; i<4; i++) {
      if(choices[i+1] == "" || i+1 == 4) {
        std::cout << choices[i] << "." << std::endl;
        break;
      }
      else {
        std::cout << choices[i] << ", ";
      }
    }
    if(prop2 == "") {
      onevars(choices, prop1, prop2, value1, value2);
    }
    else {
      twovars(choices, prop1, prop2, value1, value2);
    }
    std::cout << "Tables printed. Would you like to quit (y to quit, n to rerun):";
    std::cin >> exitinput;
    if(tolower(exitinput) == 'y') {
     break;
    }
    std::cin.ignore();
  }
}
  
bool negation(bool value) {
  if(value == true) {
    return false;
  }
  return true;
}

bool conjunction(bool value1, bool value2) {
  if(value1 == true && value2 == true) {
    return true;
  }
  return false; 
}

bool disjunction(bool value1, bool value2) {
  if(value1 == true || value2 == true) {
    return true;
  }
  return false; 
}

bool exclusiveor(bool value1, bool value2) {
  return value1 xor value2;
}

void print(bool value) { //used to print out the string values true and false from bool values
  if(value == true) {
    std::cout << std::setw(20) << std::left << "true";
  }
  if(value == false) {
    std::cout << std::setw(20) << std::left << "false";  
  }
}

void change(bool * value1, bool * value2, int counter) { //changes the booleans for table use
  switch(counter) {
    case 3: 
      *value1 = true;
      *value2 = true;
      break;
    case 2: 
      *value1 = true;
      *value2 = false;
      break;
    case 1: 
      *value1 = false;
      *value2 = true;
      break;
    case 0: 
      *value1 = false;
      *value2 = false;
      break;
  }
}

void printhead(std::string choices[], std::string prop1, std::string prop2) {
  std::cout << std::setw(20) << std::left << prop1 << std::setw(20) << std::left << prop2;
  for(int i=0; i<4; i++) {
    if(choices[i] == "negation") {
      std::cout << std::setw(20) << std::left << "~" + prop1 << std::setw(20) << std::left;
      std::cout << std::setw(20) << std::left << "~" + prop2 << std::setw(20) << std::left;  
    }
    else {
      std::cout << std::setw(20) << std::left << choices[i]  << std::setw(20) << std::left; 
    }
  }
  std::cout << std::endl;
}

void printhead(std::string choices[], std::string prop1) {
  std::cout << std::setw(20) << std::left << prop1;
  for(int i=0; i<4; i++) {
    if(choices[i] == "negation") {
      std::cout << std::setw(20) << std::left << "~" + prop1 << std::setw(20) << std::left;
    }
    else {
      std::cout << std::setw(20) << std::left << choices[i]  << std::setw(20) << std::left; 
    }
  }
  std::cout << std::endl;
}

void input(std::string choices[]) {
  std::string temp;
  int size = 0;
  std::string options [] = {"negation", "conjunction", "disjunction", "exclusive or"};
  while(size < 4) {
    std::cout << "Would you like to include negation, conjunction, disjunction, exclusive or, or all (enter one at a time or type \"end\" to finish seletions): ";
    std::getline(std::cin, temp);
    if(temp == "all") {
      choices[0] = "negation";
      choices[1] = "conjunction";
      choices[2] = "disjunction";
      choices[3] = "exclusive or";
      break;
    }
    else if(temp == "end") {
      break;
    }
    else {
      for(int j=0; j<4; j++) {
        if(temp == options[j]) {
          choices[size] = temp;
          size++;
          break;
        }
        else if(temp == choices[j]) {
          std::cout << "Option already chosen, please try again." << std::endl;
          break;
        }
        else if(j == 3) {
          std::cout << "Option not found, please try again." << std::endl;
          break;
        }
      }
    }
  }
}

void onevars(std::string choices[], std::string prop1, std::string prop2, bool value1, bool value2) {
  printhead(choices, prop1);
  int temp = 3;
    for(int i=1; i>=0; i--) {
      change(&value1, &value2, temp);
      temp -= 3;
      print(value1);
      for(int j=0; j<4; j++){
        if(choices[j] == "negation") {
          print(negation(value1));
        }
        else if(choices[j] == "conjunction") {
          print(conjunction(value1, value1));
        }
        else if(choices[j] == "disjunction") {
          print(disjunction(value1, value1));
        }
        else if(choices[j] == "exclusive or") {
          print(exclusiveor(value1, value1));
        }
        else {
          break;
        }
      }
      std::cout << std::endl;
    }
}

void twovars(std::string choices[], std::string prop1, std::string prop2, bool value1, bool value2) {
  printhead(choices, prop1, prop2);
    for(int i=3; i>=0; i--) {
      change(&value1, &value2, i);
      print(value1);
      print(value2);
      for(int j=0; j<4; j++){
        if(choices[j] == "negation") {
          print(negation(value1));
          print(negation(value2));
        }
        else if(choices[j] == "conjunction") {
          print(conjunction(value1, value2));
        }
        else if(choices[j] == "disjunction") {
          print(disjunction(value1, value2));
        }
        else if(choices[j] == "exclusive or") {
          print(exclusiveor(value1, value2));
        }
        else {
          break;
        }
      }
      std::cout << std::endl;
    }
}
