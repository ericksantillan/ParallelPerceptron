#include <iostream>
#include "data.h"
using namespace std;

int main()
{
  Data data("../Test.txt");
  cout << "Hello, World!";
  data.print();
  data.openFile();
  return 0;
}
