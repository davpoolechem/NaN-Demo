#include <iostream>
#include <math.h>
#include <regex>

template <typename T>
double mysqrt(T input) {
  if (input >= 0.0) {
    return std::sqrt(input);
  } else {
    throw std::domain_error("  Negative input detected!");
  }
}

template <>
double mysqrt(char* input) {
  std::regex is_number {"[-]?[0-9]*[\.[0-9]*]?"};
  if (std::regex_match(input, is_number)) {
    return mysqrt(atof(input));
  } else {
    throw std::invalid_argument("  Please pass a number!");
  }
}

int main(int argc, char *argv[]) {
  try {
    auto result = mysqrt(argv[1]);
    std::cout << "SUCCESS! Result: " << result << std::endl;
  } catch (std::domain_error e) {
    std::cout << "Domain error detected! Error: " << std::endl;
    std::cout << e.what() << std::endl;
  } catch (std::invalid_argument e) {
    std::cout << "Invalid argument detected! Error: " << std::endl;
    std::cout << e.what() << std::endl;
  }
  
  return 0;
}
