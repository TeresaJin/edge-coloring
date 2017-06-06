#ifndef _derandomized_h
#define _derandomized_h

#include <fstream>  
#include <iostream>  
#include <stdlib.h>  
#include <ctime>
#include "permutation.h"
#include "color_choice.h"
#include "update.h"

#define NUM 140
#define CLIQUE_MAX 479050
#define PERMUTATION 15329615

	struct clique_4{
		int white; //特定K4中被染为白色的边数
		int black;//特定K4中被染为白色的边数
		int expt;//特定K4中所有边同色的概率，初始值为1，代表概率为1/32
	};

#endif