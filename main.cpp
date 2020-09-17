#include <iostream>

#include "reservoir.h"

int main()
{
  double d = get_east_storage("01/01/2018"); // date format: MM/DD/YYYY
  std::cout << "East basin storage: " <<d << " gallons" << std::endl; //expected output: 59.94
  //more tests:
  // d = get_east_storage("12/30/2018");
  // std::cout << d << std::endl; //expected output: 74.76
  // d = get_east_storage("2/3/2018");
  // std::cout << d << std::endl; //expected output: 74.76
  // d = get_east_storage("02-03-2018");
  // std::cout << d << std::endl; //expected output: Invalid date 0
  // d = get_east_storage("02/21/2019");
  // std::cout << d << std::endl; //expected output: Invalid date 0
  // d = get_east_storage("abcd");
  // std::cout << d << std::endl; //expected output: Invalid date 0
  double min = get_min_east();
  std::cout << "Minimum storage in East basin: " << min << " gallons" << std::endl;
  double max = get_max_east();
  std::cout << "Maximum storage in East basin: " << max << " gallons" << std::endl;

  return 0;
}
