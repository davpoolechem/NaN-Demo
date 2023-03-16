#include <complex>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>

void nan_demo_a() {
  std::cout << "#==========================#" << std::endl;
  std::cout << "#== Demo A: Getting NaNs ==#" << std::endl;
  std::cout << "#==========================#" << std::endl;
  
  double zero_div_zero_double_nan = 0.0/0.0; 
  std::cout << "0.0/0.0 => " << zero_div_zero_double_nan << std::endl;

  double sqrt_neg_one_nan = sqrt(-1.0);
  std::cout << "sqrt(-1.0) => " << sqrt_neg_one_nan << std::endl;

  std::complex<double> sqrt_neg_one_complex = sqrt(std::complex<double>(-1.0));
  std::cout << "sqrt(complex(-1.0)) => " << sqrt_neg_one_complex << std::endl << std::endl;
}

void nan_demo_b() { 
  std::cout << "#============================#" << std::endl;
  std::cout << "#== Demo B: Comparing NaNs ==#" << std::endl;
  std::cout << "#============================#" << std::endl;
 
  double sqrt_neg_one_nan = sqrt(-1.0);

  std::cout << "sqrt(-1.0) == sqrt(-1.0)? " << (sqrt_neg_one_nan == sqrt_neg_one_nan ? "True" : "False") << std::endl;
  std::cout << "isnan(sqrt(-1.0))? " << (isnan(sqrt_neg_one_nan) ? "True" : "False") << std::endl << std::endl;
}
  
void nan_demo_c() { 
  std::cout << "#==============================#" << std::endl;
  std::cout << "#== Demo C: Propogating NaNs ==#" << std::endl;
  std::cout << "#==============================#" << std::endl;
 
  double sqrt_neg_one_nan = sqrt(-1.0);
  std::complex<double> sqrt_neg_one_complex = sqrt(std::complex<double>(-1.0));

  std::cout << "sqrt(-1.0) + 1.0 => " << (sqrt_neg_one_nan + 1.0) << std::endl;
  std::cout << "sqrt(-1.0) * 3.0 => " << (sqrt_neg_one_nan*3.0) << std::endl;
  std::cout << "sqrt(-1.0)^2.0 => " << (std::pow(sqrt_neg_one_nan, 2.0)) << std::endl << std::endl;

  std::cout << "x = sqrt(-1.0) + 1.0 => " << (sqrt_neg_one_nan + 1.0) << std::endl;
  std::cout << "y = x * 3.0 => " << ((sqrt_neg_one_nan + 1.0)*3.0) << std::endl;
  std::cout << "z = y^2.0 => " << (std::pow((sqrt_neg_one_nan + 1.0)*3.0, 2.0)) << std::endl << std::endl;

  //std::cout << "sqrt(complex(-1.0)) + 1.0 => " << (sqrt_neg_one_complex + 1.0) << std::endl;
  //std::cout << "sqrt(complex(-1.0)) * 3.0 => " << (sqrt_neg_one_complex*3.0) << std::endl;
  //std::cout << "sqrt(complex(-1.0))^2.0 => " << (std::pow(sqrt_neg_one_complex, 2.0)) << std::endl;
}

int main(int argc, char *argv[]) {
    if (atoi(argv[1])) nan_demo_a();
    if (atoi(argv[2])) nan_demo_b();
    if (atoi(argv[3])) nan_demo_c();

    return 0;
}
