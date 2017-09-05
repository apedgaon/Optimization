#include <cmath>
#include "minfunc.hpp"

void gfunc(double x, double& df, double& ddf)
{
  //f = - pow(x,3) + 3.0/4*pow(x,4); // Function
  df = - 3*pow(x,2) + 3*pow(x,3); // Change derivative accordingly
  ddf = - 6*x + 9*pow(x,2); // Change double derivative accordingly
}
