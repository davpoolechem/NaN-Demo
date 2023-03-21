#include <complex>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>

// first demo - how one can run into a NaN in their own code
void nan_demo_a() {
  std::cout << "#==========================#" << std::endl;
  std::cout << "#== Demo A: Getting NaNs ==#" << std::endl;
  std::cout << "#==========================#" << std::endl;
  
  // 0.0/0.0 gives a NaN
  double zero_div_zero_double_nan = 0.0/0.0; 
  std::cout << "0.0/0.0 => " << zero_div_zero_double_nan << std::endl;

  // sqrt of a negative double gives a NaN...
  double sqrt_neg_one_nan = sqrt(-1.0);
  std::cout << "sqrt(-1.0) => " << sqrt_neg_one_nan << std::endl;

  // ..but one can get around this with a complex number
  std::complex<double> sqrt_neg_one_complex = sqrt(std::complex<double>(-1.0));
  std::cout << "sqrt(complex(-1.0)) => " << sqrt_neg_one_complex << std::endl << std::endl;
}

// second demo - how to detect if a variable is a NaN
void nan_demo_b() { 
  std::cout << "#============================#" << std::endl;
  std::cout << "#== Demo B: Comparing NaNs ==#" << std::endl;
  std::cout << "#============================#" << std::endl;
 
  double sqrt_neg_one_nan = sqrt(-1.0);

  // sadly, we cant use a simple comparison operator. even a NaN variable compared to itself is false...
  std::cout << "sqrt(-1.0) == sqrt(-1.0)? " << (sqrt_neg_one_nan == sqrt_neg_one_nan ? "True" : "False") << std::endl;
  
  // ... so we have to use the isnan function from math.h
  std::cout << "isnan(sqrt(-1.0))? " << (isnan(sqrt_neg_one_nan) ? "True" : "False") << std::endl << std::endl;
}
  
// third demo - how NaNs propogate through a code
void nan_demo_c() { 
  std::cout << "#==============================#" << std::endl;
  std::cout << "#== Demo C: Propogating NaNs ==#" << std::endl;
  std::cout << "#==============================#" << std::endl;
 
  double sqrt_neg_one_nan = sqrt(-1.0);
  std::complex<double> sqrt_neg_one_complex = sqrt(std::complex<double>(-1.0));

  // arithmetic operations of a NaN lead to a NaN
  std::cout << "sqrt(-1.0) + 1.0 => " << (sqrt_neg_one_nan + 1.0) << std::endl;
  std::cout << "sqrt(-1.0) * 3.0 => " << (sqrt_neg_one_nan*3.0) << std::endl;
  std::cout << "sqrt(-1.0)^2.0 => " << (std::pow(sqrt_neg_one_nan, 2.0)) << std::endl << std::endl;

  // NaNs will propogate through the code
  std::cout << "x = sqrt(-1.0) + 1.0 => " << (sqrt_neg_one_nan + 1.0) << std::endl;
  std::cout << "y = x * 3.0 => " << ((sqrt_neg_one_nan + 1.0)*3.0) << std::endl;
  std::cout << "z = y^2.0 => " << (std::pow((sqrt_neg_one_nan + 1.0)*3.0, 2.0)) << std::endl << std::endl;

  //std::cout << "sqrt(complex(-1.0)) + 1.0 => " << (sqrt_neg_one_complex + 1.0) << std::endl;
  //std::cout << "sqrt(complex(-1.0)) * 3.0 => " << (sqrt_neg_one_complex*3.0) << std::endl;
  //std::cout << "sqrt(complex(-1.0))^2.0 => " << (std::pow(sqrt_neg_one_complex, 2.0)) << std::endl;
}

// choose demos to run
// argv[1] != 0 runs the first demo
// argv[2] != 0 runs the second demo
// argv[3] != 0 runs the third demo
int main(int argc, char *argv[]) {
    if (atoi(argv[1])) nan_demo_a();
    if (atoi(argv[2])) nan_demo_b();
    if (atoi(argv[3])) nan_demo_c();

    return 0;
}
