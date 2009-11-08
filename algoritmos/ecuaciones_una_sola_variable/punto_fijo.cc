/* 
   Sebastian Arcila Valenzuela
   sebastianarcila@gmail.com
   2009
   @(#)TEMPLATE.c.tpl
 */

/*#include <config.h>
#include "punto_fijo.h"
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <stdarg.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>

using namespace std;

/* DEBUG */
#define D(x) cerr<<__LINE__<<" "#x" "<<x<<endl
#define D_v(x) for(int i=0;i<x.size();cerr<<x[i++]<<" ")

#define ALL(x) x.begin(),x.end()
double f(double x)
{
  return x*x-3;
}
double g(double x)
{
  return x-(x*x-3)/(2*x);
}
void punto_fijo(double x0,double tol, int it)
{
  double y = f(x0);
  double E = tol +1;
  int cont =0;
  double xa;
  while(y!=0 && E>=tol && cont<it)
    {
      xa = x0;
      x0 = g(x0);
      y = f(x0);
      E = fabs(x0-xa);
      ++cont;
    }
  if(y==0)
    printf("%lf es raíz\n",x0);
  else
    if(E<tol)
      printf("%lf es raíz con error\n",x0);
    else
      puts("No hay raíz");
}
int main()
{
  punto_fijo(100,1e-9,100000);
  return 0;
}
