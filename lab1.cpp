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
void twovars(std::string[], std::string, std::string, bool, bool);
void onevars(std::string[], std::string, std::string, bool, bool);


int main() {
  //variable declarations
  std::string prop1; //first proposition name
  std::string prop2; //second propsition name
  std::string name; //user name
  bool value1; //for the truth tables
  bool value2;
  char exitinput; 
  
  while(true) { //program loop so user can keep rerunning 
    std::string choices[4]; //array reinitialized every run so all the old operations chosen before are cleared out
    std::cout << "Hello, please enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Welcome, " << name << ", please enter the name for the first proposition: ";
    std::getline(std::cin, prop1);   
    std::cout << "Please enter the name of the second proposition (press enter if you only want one proposition): ";
    std::getline(std::cin, prop2);
    input(choices);
    std::cout << "Thank you. Here is the table for "; 
    for(int i=0; i<4; i++) { //prints out the operations that the user chose as confirmation
      if(choices[i+1] == "" || i+1 == 4) { //prints out a period and the last operation 
        std::cout << choices[i] << "." << std::endl;
        break;
      }
      else {
        std::cout << choices[i] << ", ";
      }
    }
    if(prop2 == "") { //if the user only chooses one proposition
      onevars(choices, prop1, prop2, value1, value2);
    }
    else {
      twovars(choices, prop1, prop2, value1, value2);
    }
    std::cout << "Tables printed. Would you like to quit (y to quit, n to rerun):";
    std::cin >> exitinput;
    if(tolower(exitinput) == 'y') { //if the user decides to quit then break out of the loop
     break;
    }
    std::cin.ignore(); //clear the input buffer for the next run
  }
}
  
bool negation(bool value) { //basic negation function 
  if(value == true) {
    return false;
  }
  return true;
}

bool conjunction(bool value1, bool value2) { //conjunction function 
  if(value1 == true && value2 == true) { //only returns true when both propositions are true
    return true; //returns true and exits function 
  }
  return false; //any other combination will yield false
}

bool disjunction(bool value1, bool value2) { //disjunction
  if(value1 == true || value2 == true) { //if either proposition is true then return true
    return true;
  }
  return false; 
}

bool exclusiveor(bool value1, bool value2) { //xor function
  return value1 xor value2; //uses c++ operation xor and returns value
}

void print(bool value) { //used to print out the string values true and false from bool values
  if(value == true) {
    std::cout << std::setw(20) << std::left << "true"; //changes the 1 and 0 boolean values to string values
  }
  if(value == false) {
    std::cout << std::setw(20) << std::left << "false";  
  }
}

void change(bool * value1, bool * value2, int counter) { //changes the booleans for table use
  switch(counter) {
    case 3: //goes from 3-0 and assigns boolean values like binary digits
      *value1 = true; //i.e. 3 in binary is 0011 as seen here	
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

void printhead(std::string choices[], std::string prop1, std::string prop2) { //first print head which works with two propositions
  std::cout << std::setw(20) << std::left << prop1 << std::setw(20) << std::left << prop2; //uses setw to set 20 spaces in between each value 
  for(int i=0; i<4; i++) {
    if(choices[i] == "negation") { //if negation is chosen print ~<prop name> for both props
      std::cout << std::setw(20) << std::left << "~" + prop1 << std::setw(20) << std::left;
      std::cout << std::setw(20) << std::left << "~" + prop2 << std::setw(20) << std::left;  
    }
    else { //if anything else is chosen then print out the operation for the header row
      std::cout << std::setw(20) << std::left << choices[i]  << std::setw(20) << std::left; 
    }
  }
  std::cout << std::endl;
}

void printhead(std::string choices[], std::string prop1) { //prints the head row for only one proposition
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

void input(std::string choices[]) { //function that takes user input 
  std::string temp; //temporary string to hold the user input
  int size = 0; //counter that keeps track of how many operations the user has chosen
  std::string options [] = {"negation", "conjunction", "disjunction", "exclusive or"}; //list of operations that will be used to compare later
  while(size < 4) {
    std::cout << "Would you like to include negation, conjunction, disjunction, exclusive or, or all (enter one at a time or type \"end\" to finish seletions): ";
    std::getline(std::cin, temp);
    if(temp == "all") { //if all is picked then fills up the list with all the operations
      choices[0] = "negation";
      choices[1] = "conjunction";
      choices[2] = "disjunction";
      choices[3] = "exclusive or";
      break;
    }
    else if(temp == "end") { //quits
      break;
    }
    else {
      for(int j=0; j<4; j++) {
        if(temp == options[j]) { //uses the loop to check to see if the user input is in the list of operations
          choices[size] = temp; //if it is then put the operation in the list of user choices
          size++; //increment counter to keep track of list size
          break;
        }
        else if(temp == choices[j]) { //if the user choice is found in the current list of user choices
          std::cout << "Option already chosen, please try again." << std::endl; //print error message and move on
          break;
        }
        else if(j == 3) { //if the loop ends then print out error message and move on
          std::cout << "Option not found, please try again." << std::endl;
          break;
        }
      }
    }
  }
}

void twovars(std::string choices[], std::string prop1, std::string prop2, bool value1, bool value2) { //table operation for two propositions
  printhead(choices, prop1, prop2); //calls the print head for two propositions
    for(int i=3; i>=0; i--) { //basic loop that prints out each individual row
      change(&value1, &value2, i); //uses the change function to set the boolean values for the table
      print(value1);
      print(value2);
      for(int j=0; j<4; j++){ //now goes through the list and choses each function and prints out the values accordingly
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

void onevars(std::string choices[], std::string prop1, std::string prop2, bool value1, bool value2) { //table operation for one proposition
  printhead(choices, prop1); //calls the print head function to print out the first row
  int temp = 3; //use this temporary variable to pass in the change function as this function only requires one true and one false value
    for(int i=1; i>=0; i--) {
      change(&value1, &value2, temp); //calls the change function to set values
      temp -= 3; //change temp to zero right afterwards to be used int the change function
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
