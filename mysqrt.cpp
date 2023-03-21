#include <iostream>
#include <math.h>
#include <regex>

// homebrewed std::sqrt wrapper inputting double
// throws an domain_error exception if input is negative
double mysqrt(double input) {
  if (input >= 0.0) {
    return std::sqrt(input);
  } else {
    throw std::domain_error("  Negative input detected!");
  }
}

// homebrewed std::sqrt wrapper inputting a char array
// uses above wrapper
// throws an invalid_number exception if input is not a char array representing a number
double mysqrt(char* input) {
  std::regex is_number {"[-]?[0-9]*[\.[0-9]*]?"};
  if (std::regex_match(input, is_number)) {
    return mysqrt(atof(input));
  } else {
    throw std::invalid_argument("  Please pass a number!");
  }
}

// test our sqrt wrapper by taking the command line argument as an input
// exceptions can come from the command line argument being either not a valid number
// or from the command line argument being a negative number
// exceptions allow for separate treatment of both cases
// additionally, exceptions are propogated through the unwinding call stack
// and are all ultimately handled here
int main(int argc, char *argv[]) {
  // lets try taking a square root of our command line argument
  try {
    auto result = mysqrt(argv[1]);
    std::cout << "SUCCESS! Result: " << result << std::endl;
  // we can get a domain_error from the double-input version of mysqrt...
  } catch (std::domain_error e) {
    std::cout << "Domain error detected! Error: " << std::endl;
    std::cout << e.what() << std::endl;
  // ..or we can get an invalid_argument exception from the char*-input version...
  } catch (std::invalid_argument e) {
    std::cout << "Invalid argument detected! Error: " << std::endl;
    std::cout << e.what() << std::endl;
  }
  
  return 0;
}
