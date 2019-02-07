#include <iostream>
#include <iomanip>

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

int main() {
  std::string choices[4];
  input(choices);
  for(int i=0; i<4; i++) {
    if(choices[i] == "") {
      break;
    }
    std::cout << choices[i] << std::endl;
  }
}
