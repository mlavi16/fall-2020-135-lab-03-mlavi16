#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2) {
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

    //find size of the array
    int size_of_array = 0;
    bool repeat = false;
    bool sec_val_found = false;
    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n');
        if ((date == date1) && (!sec_val_found)) {
            repeat = true;
        } 
        if (repeat) {
            size_of_array++;
        } 
        if (date == date2) {
            repeat = false;
            sec_val_found = true;
        }
    }
    if (sec_val_found == false) {
        size_of_array = 0;
    }
    std::string dates[size_of_array];
    double westElArray[size_of_array];
    
    fin.clear();
    fin.seekg(0);
    getline(fin, junk);

    //get array values
    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n');
        if (date == date1) {
            for (int i = 0; i < size_of_array; i++){
                dates[i] = date;
                westElArray[i] = westEl;
                fin >> date >> eastSt >> eastEl >> westSt >> westEl;
                fin.ignore(INT_MAX, '\n');
            }
        }
        
    }
    fin.close();

    //print array
    for (int i = (size_of_array-1); i >= 0; i--) {
        std::cout << dates[i] << "  " << westElArray[i] << " ft" << std::endl;
    }
}