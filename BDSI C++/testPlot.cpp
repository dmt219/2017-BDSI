#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <koolplot.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include<cmath>
using namespace std;
int main()
{
   plotdata x(-6.0, 6.0);
   plotdata y = sin(x) + x/5;
   plot(x, y);
   return 0;
}

