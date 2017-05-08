#ifndef logic
#define logic 1

#include "masterheader.h"

void create_vectors(bool, items &, items &, vector<vector<item>> &);
void create_layers(int, string **&, vector<vector<item>> &);
void view_matrix(int, vector<vector<item>> &, string **&, vector<vector<item>> &, string **&);
void preference(int *&, vector<vector<item>>, vector<vector<item>>);
void view_vec(int, bool, vector<vector<item>> &);

#endif
