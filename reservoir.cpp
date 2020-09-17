#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

#include "reservoir.h"

double get_east_storage(std::string entered_date){
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }
  std::string junk;        // new string variable
  getline(fin, junk); // read one line from the file 

  std::string date;
  double eastSt;
  double eastEl;
  double westSt;
  double westEl;

  while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
    fin.ignore(INT_MAX, '\n');
    if (date == entered_date) {
      return eastSt;
    }
  }
  fin.close();
  std::cout << "Invalid date" << std::endl;
  return 0;
}

double get_min_east(){
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }
  std::string junk;        // new string variable
  getline(fin, junk); // read one line from the file 

  std::string date;
  double eastSt;
  double eastEl;
  double westSt;
  double westEl;
  
  fin >> date >> eastSt >> eastEl >> westSt >> westEl;
  fin.ignore(INT_MAX, '\n');
  double min = eastSt;
  while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 

    fin.ignore(INT_MAX, '\n');
    if (eastSt < min) {
      min = eastSt;
    }
  }
  fin.close();
  return min;
}

double get_max_east(){
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }
  std::string junk;        // new string variable
  getline(fin, junk); // read one line from the file 

  std::string date;
  double eastSt;
  double eastEl;
  double westSt;
  double westEl;
  
  double max = 0;
  while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
    fin.ignore(INT_MAX, '\n');
    if (eastSt > max) {
      max = eastSt;
    }
  }
  fin.close();
  return max;
}

std::string compare_basins(std::string entered_date) {
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }
  std::string junk;        // new string variable
  getline(fin, junk); // read one line from the file 

  std::string date;
  double eastSt;
  double eastEl;
  double westSt;
  double westEl;
  
  while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
    fin.ignore(INT_MAX, '\n');
    if (date == entered_date) {
      if (eastEl > westEl) {
        return "East";
      } else if (westEl > eastEl) {
        return "West";
      } else {
        return "Equal";
      }
    }
  }
  fin.close();
  return "Not a valid date.";
}