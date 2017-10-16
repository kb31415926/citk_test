
#include <omp.h>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;


int main(int argc, char *argv[]) {

  // init rng
  srand(time(NULL));

  // header
  cout << endl;
  cout << "* [MIRA VERSION 0.1]" << endl;
  cout << "------------------------------" << endl;

  // omp parallelization
  cout << "* [omp parallelization]" << endl;
  int nthreads;
  #pragma omp parallel
    {
    #pragma omp master
      { nthreads=omp_get_num_threads(); cout << " -- nthreads=" << nthreads << endl; }
    #pragma omp barrier
    }

  // input file
  cout << "* [input file]" << endl;
  string ifile;
  stringstream s;
  s << argv[1];
  s >> ifile;
  cout << " -- file=\"" << ifile << "\"" << endl;

  // parameters
  cout << "* [parameters]" << endl;
  int L=10;
  int dim=1;
  double norm=1.0e-3;
  string dum;
  ifstream fin;
  fin.open(ifile);
  fin >> dum >> dum >> L;
  fin >> dum >> dum >> dim;
  fin >> dum >> dum >> norm;
  fin.close();
  cout << setprecision(10) << scientific <<" -- L=" << L << endl;
  cout << setprecision(10) << scientific << " -- dim=" << dim << endl;
  cout << setprecision(10) << scientific << " -- norm=" << norm << endl;

  // output file
  cout << "* [output file]" << endl;
  string ofile="mira.dat";
  cout << " -- file=\"" << ofile << "\"" << endl;

  // create data
  cout << "* [create data]" << endl;
  double *library=new double[L*dim];
  for(int i=0;i<(L*dim);i++) {
    library[i]=((double)random())/((double)RAND_MAX)*norm;
    }

  // write data
  cout << "* [write data]" << endl;
  ofstream fout;
  fout.open(ofile);
  for(int i=0;i<(L*dim);i++) {
    fout << i << " " << library[i] << endl;
    }
  fout.close();

  // annihilate data
  cout << "* [aniihilate data]" << endl;
  delete [] library;

  // footer
  cout << "------------------------------" << endl;
  cout << "* [ALL DONE!]" << endl;
  cout << endl;

  return 0;
  }


