#include <iostream>
#include <cmath>

using namespace std;

void func(double x, double& df, double& ddf);

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
  func(x,df,ddf);

  int n = 1;
  do
    {
      x = x - df/ddf;
      func(x,df,ddf);
      n++;
    }while (fabs(df/ddf) > tol);

  cout << "Minima of function is at x = " << x << "\n";

  cout << " Number of Iterations = " << n << "\n";
    
  return 0;
}

void func(double x, double& df, double& ddf)
{
  //f = - pow(x,3) + 3.0/4*pow(x,4); // Function
  df = - 3*pow(x,2) + 3*pow(x,3); // Change derivative accordingly
  ddf = - 6*x + 9*pow(x,2); // Change double derivative accordingly
}
