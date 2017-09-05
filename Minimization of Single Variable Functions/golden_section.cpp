#include <iostream>
#include <cmath>
#include "minfunc.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  // Defining variables
  double xl, xu, x1, x2, fl, fu, f1, f2, tol;
  const double t = 0.61803;

  // Input the bounds
  cout << "x lower = ";
  cin >> xl;
  cout << "x upper = ";
  cin >> xu;
  cout << "Accuracy of Minima = ";
  cin >> tol;

  // Defining golden section points
  x1 = t*xl + (1 - t)*xu;
  x2 = (1 - t)*xl + t*xu;
  
  // Functional values of bounds
  fl = func(xl);
  f1 = func(x1);
  f2 = func(x2);
  fu = func(xu);

  // Golden Section algorithm to find Minima
  int n = 1;
  while (fabs(xu - xl) > tol*xl)
    {
      if (f1 > f2)
	{
	  xl = x1;
	  fl = f1;
	  x1 = x2;
	  f1 = f2;
	  x2 = (1 - t)*xl + t*xu;
	  f2 = func(x2);
	}
      else
	{
	  xu = x2;
	  fu = f2;
	  x2 = x1;
	  f2 = f1;
	  x1 = t*xl + (1 - t)*xu;
	  f1 = func(x1);
	}
      n++;
    }

  // Display the results
  cout << "Minima is at x = " << xl << "\n";
  cout << "Number of iterations = " << n - 1 << "\n";
     
  return 0;
}

