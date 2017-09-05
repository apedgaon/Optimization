#include <iostream>
#include <cmath>
#include "minfunc.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  // Defining variables
  double x, df, ddf, tol;

  // Input the initial variables
  cout << "Initial guess x0 = ";
  cin >> x;
  cout << "Accuracy of Minima = ";
  cin >> tol;

  // Computing function value and its derivative
  gfunc(x,df,ddf);

  int n = 1;
  do
    {
      x = x - df/ddf;
      gfunc(x,df,ddf);
      n++;
    }while (fabs(df/ddf) > tol);

  cout << "Minima of function is at x = " << x << "\n";

  cout << " Number of Iterations = " << n << "\n";
    
  return 0;
}

