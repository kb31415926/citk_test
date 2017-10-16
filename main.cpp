
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ofstream fout;

  cout << "* TEST CITK ENVIRONMENT" << endl;

  fout.open("test.dat");
  fout << "1.23456789 9.87654321" << endl;
  fout.close();

  return 0;
  }
