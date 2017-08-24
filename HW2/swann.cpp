#include <iostream>
#include <cmath>

using namespace std;

// Function to be minimized
// Defined below int main()
double func(double x);


int main(int argc, char* argv[])
{
  // Variable Definition
  double xm, x, xp, delta, fm, f, fp;

  // Input initial guess and increment for the problem
  cout << "x = ";
  cin >> x;
  cout << "Increment = ";
  cin >> delta;
  cout << "\n\n";

  // Determining which side does the Minima lie
  xm = x - delta;
  fm  = func(xm);

  f = func(x);

  xp = x + delta;
  fp = func(xp);


  int q;
  if (fm < f && f < fp)
    q = 1;
  else if (fm > f && f > fp)
    q = 2;
  else if (fm > f && f < fp)
    q = 0;

  // Applying Swann's Algorithm to bound Minima
  int n = 1;
  if (q == 0)
    cout << "Bounds of Minima = (" << xm << "," << xp << ")\n";
  else
    {
      xm = x;
      fm = f;
      x = x + pow(-1,q)*delta;
      f = func(x);
      xp = x + pow(2,n)*pow(-1,q)*delta;
      fp = func(xp);
      n++;
      while (fp < f)
	{
	  xm = x;
	  x = xp;
	  f = fp;
	  xp = x + pow(2,n)*pow(-1,q)*delta;
	  fp = func(xp);
	  n++;
	}      
    }

  // Display bounds for minima obtained from Swann's Algorithm
  if (q == 1)
    cout << "Bounds of Minima = (" << xp << "," << xm << ")\n";
  else if (q == 2)
    cout << "Bounds of Minima = (" << xm << "," << xp << ")\n";

  cout << "iterations = " << n - 1 << "\n";
  cout << q <<"\n";

  return 0;
}


double func(double x)
{
  double f;
  f = -pow(x,3) + 3.0/4*pow(x,4); // Change the funtion here
  return f;
}
