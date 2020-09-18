#include <iostream>

#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  double d = get_east_storage("05/20/2018"); // date format: MM/DD/YYYY (no spaces)
  std::cout << "East basin storage: " << d << " gallons" << std::endl; //expected output: 59.94
  d = get_east_storage("01 / 01 / 2018"); //expected output: Invalid date.
  d = get_east_storage("abcd"); //expected output: Invalid date.
  std::cout << "--" << std::endl;

  double min = get_min_east();
  std::cout << "Minimum storage in East basin: " << min << " gallons" << std::endl;
  double max = get_max_east();
  std::cout << "Maximum storage in East basin: " << max << " gallons" << std::endl;
  std::cout << "--" << std::endl;

  std::string higher = compare_basins("01/01/2018"); //E: 574; W: 574.33; higher should be W
  std::cout << higher << std::endl;
  higher = compare_basins("01/07/2018"); //E: 573.96; W: 573.96; equal (I changed it to be equal for the test)
  std::cout << higher << std::endl;
  higher = compare_basins("07/03/2018"); //E: 586.58; W: 583.64; higher should be E
  std::cout << higher << std::endl;
  higher = compare_basins(""); // Not a valid date.
  std::cout << higher << std::endl;
  std::cout << "--" << std::endl;

  reverse_order("05/29/2018", "06/02/2018");
  std::cout << std::endl;
  reverse_order("", ""); //no output
  reverse_order("05/29/2018", "never"); //no output
  reverse_order("", "05/29/2018"); //no output
  reverse_order("12/20/2018", "11/15/2018"); //no output
  reverse_order("02/22/2018", "02/22/2018");
  std::cout << "--" << std::endl;

  return 0;
}
