//Randomly choose the colour of each edge, the program repeats the process until find a feasible solution

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include "permutation.h"
using namespace std;

#define NUM 80
#define CLIQUE_MAX 49424

int main() {
	int n = NUM;
	srand(time(NULL));
	int i,j;

	ofstream fout;
	fout.open("output.txt",ios::app);
	if(!fout){
        cout << "Open the file failure...\n";
        exit(0);
    }

	bool **color; //adjacent matrix;the value means the color of each edge
	color = new bool*[NUM];
	for (i = 0;i < NUM;i++){
		color[i] = new bool[NUM]; }

	while (true){
		for (i = 0;i < (NUM-1);i++){
			for (j = (i+1);j < (NUM);j++){
				color[i][j] = rand()%2;  //ramdomly choose the color of the edge
			}
		}
		int count_clique = permuatation(n, color); //Caculate the number of cliques
		if (count_clique <= CLIQUE_MAX){
			fout<<"Find a feasible solution:"<<endl;
			for (i = 0;i < (NUM);i++){
				for (j = 0;j < (NUM);j++){
					if (i>=j)
					{fout<<"x ";}
					else
					{fout<<color[i][j]<<" ";}
				}
				fout<<endl;
			}
			break;
		}
	}

	for (i=0; i < NUM; i++){
		delete [] color[i];}
	delete [] color;

	return 0;
}
