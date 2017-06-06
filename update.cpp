#include <fstream>  
#include <iostream>  
#include <stdlib.h>  
#include "update.h"
using namespace std; 

void update (int n,int row,int column,bool color,clique_4 *(*index)[NUM][NUM][NUM]){
	int i,j; 
	for (i = 0; i< n; i++){
		if (i == row || i == column)
			continue;
		for (j = i+1;j < n;j++){
			if (j == row || j == column)
				continue;
			if (color == 0){ //white
				(*index[row][column][i][j]).white +=1;
				if ((*index[row][column][i][j]).black ==0){
					if ((*index[row][column][i][j]).white!=1)
						(*index[row][column][i][j]).expt *=2;
				}
				else {
						(*index[row][column][i][j]).expt = 0;
				}
			}
			else { //black
				(*index[row][column][i][j]).black +=1;
				if ((*index[row][column][i][j]).white ==0){
					if((*index[row][column][i][j]).black!=1)
						(*index[row][column][i][j]).expt *=2;
				}
				else {
						(*index[row][column][i][j]).expt = 0;
				}
			}
		}
	}


	return;
}