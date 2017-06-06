#ifndef _update_h
#define _update_h

#include "derandomized.h"

#define NUM 140

struct clique_4;
void update (int n,int row,int column,bool color,clique_4 *(*index)[NUM][NUM][NUM]);

#endif