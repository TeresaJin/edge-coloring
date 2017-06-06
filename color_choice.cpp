#include <fstream>  
#include <iostream>  
#include <stdlib.h>  
#include <ctime>
#include "color_choice.h"
using namespace std; 

bool color_choice (int n,int row,int column,clique_4 *(*index)[NUM][NUM][NUM]){
	bool color;//0 means white,1 means black
	int sum_exp_white = 0;
	int sum_exp_black = 0;
	int i,j; 

	//若当前边染白色，计算数学期望
	for (i = 0; i< n; i++){
		if (i == row || i == column)
			continue;
		for (j = i+1;j < n;j++){
			if (j == row || j == column)
				continue;
			if ((*index[row][column][i][j]).black ==0) {
				if ((*index[row][column][i][j]).white ==0)
					sum_exp_white = sum_exp_white + (*index[row][column][i][j]).expt;
				else
					sum_exp_white = sum_exp_white + (*index[row][column][i][j]).expt * 2;
	
			}
		}
	}

	//若当前边染黑色，计算数学期望
	for (i = 0; i< n; i++){
		if (i == row || i == column)
			continue;
		for (j = i+1;j < n;j++){
			if (j == row || j == column)
				continue;
			if ((*index[row][column][i][j]).white ==0) {
				if ((*index[row][column][i][j]).black ==0)
					sum_exp_black = sum_exp_black + (*index[row][column][i][j]).expt;
				else
					sum_exp_black = sum_exp_black + (*index[row][column][i][j]).expt * 2;
	
			}
		}
	}
	//Determine the color
	if (sum_exp_black == sum_exp_white)
		color = rand()%2;
	else {
		if (sum_exp_black > sum_exp_white)
			color = 0; //white
		else
			color = 1; //black
	}

	return color;

}
