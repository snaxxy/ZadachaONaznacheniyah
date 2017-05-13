#ifndef logicheader
#define logicheader 1

#include "items.h"
#include "element.h"
//#include "list.h"

void calculateVectors(bool, items &, items &, vector<vector<item>> &);
void create_layers(int, string **&, vector<vector<item>> &);
void view_matrix(int, vector<vector<item>> &, string **&, vector<vector<item>> &, string **&);
void preference(int *&, vector<vector<item>>, vector<vector<item>>);
void printVector(int, bool, vector<vector<item>> &);

#endif
