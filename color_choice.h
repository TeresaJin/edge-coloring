#ifndef _color_choice_h
#define _color_choice_h

#include "derandomized.h"
#define NUM 140

struct clique_4;
bool color_choice (int n,int row,int column,clique_4 *(*index)[NUM][NUM][NUM]);

#endif