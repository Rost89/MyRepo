#include <fstream>
#include <iostream>

using namespace std;

int PGM_detector(fstream *);
int read_pgm_file(fstream *, char);
void build_histogram(fstream *f, unsigned int *, int, int);
void print_in_file(unsigned int *, int, int, char**);
