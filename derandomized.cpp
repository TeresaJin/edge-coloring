//Use dirandomization to deterministically find a feasible coloring method.
#include "derandomized.h"
using namespace std;

int main() {
	int n = NUM;
	srand(time(NULL));
	int i,j,a,b,c,d;

	ofstream fout;
	fout.open("output.txt",ios::app);
	if(!fout){
        cout << "Open the file failure...\n";
        exit(0);
    }

	static clique_4 clique_table[PERMUTATION]; //Record the color of edges in each 4-clique.
	for (i=0;i < PERMUTATION;i++){
		clique_table[i].white = 0;
		clique_table[i].black = 0;
		clique_table[i].expt = 1;
	}

	static clique_4 *clique_index[NUM][NUM][NUM][NUM] = {NULL};
	int count = 0;
	for (a=0;a<=n-4;a++){
		for (b=a+1;b<=n-3;b++){
			for (c=b+1;c<=n-2;c++){
				for (d=c+1;d<=n-1;d++){
					clique_index[a][b][c][d] = (clique_4 *)(&clique_table[count]);
					clique_index[a][b][d][c] = (clique_4 *)(&clique_table[count]);
					clique_index[a][c][b][d] = (clique_4 *)(&clique_table[count]);
					clique_index[a][c][d][b] = (clique_4 *)(&clique_table[count]);
					clique_index[a][d][b][c] = (clique_4 *)(&clique_table[count]);
					clique_index[a][d][c][b] = (clique_4 *)(&clique_table[count]);
					clique_index[b][a][c][d] = (clique_4 *)(&clique_table[count]);
					clique_index[b][a][d][c] = (clique_4 *)(&clique_table[count]);
					clique_index[b][c][a][d] = (clique_4 *)(&clique_table[count]);
					clique_index[b][c][d][a] = (clique_4 *)(&clique_table[count]);
					clique_index[b][d][a][c] = (clique_4 *)(&clique_table[count]);
					clique_index[b][d][c][a] = (clique_4 *)(&clique_table[count]);
					clique_index[c][a][b][d] = (clique_4 *)(&clique_table[count]);
					clique_index[c][a][d][b] = (clique_4 *)(&clique_table[count]);
					clique_index[c][b][a][d] = (clique_4 *)(&clique_table[count]);
					clique_index[c][b][d][a] = (clique_4 *)(&clique_table[count]);
					clique_index[c][d][a][b] = (clique_4 *)(&clique_table[count]);
					clique_index[c][d][b][a] = (clique_4 *)(&clique_table[count]);
					clique_index[d][a][b][c] = (clique_4 *)(&clique_table[count]);
					clique_index[d][a][c][b] = (clique_4 *)(&clique_table[count]);
					clique_index[d][b][a][c] = (clique_4 *)(&clique_table[count]);
					clique_index[d][b][c][a] = (clique_4 *)(&clique_table[count]);
					clique_index[d][c][a][b] = (clique_4 *)(&clique_table[count]);
					clique_index[d][c][b][a] = (clique_4 *)(&clique_table[count]);
					count += 1;
				}
			}
		}
	}

	bool **color;
	color = new bool*[NUM];
	for (i = 0;i < NUM;i++){
		color[i] = new bool[NUM]; }

	//Assign color for each edge
	for (i = 0;i < (NUM-1);i++){
		for (j = (i+1);j < (NUM);j++){
			color[i][j] = color_choice(n,i,j,clique_index);
			update(n,i,j,color[i][j],clique_index);
			}
	}

	int count_clique = permuatation(n, color);
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
	}
	else
		{fout<<"The algorithm doesn't work."<<endl;}

	for (i = 0;i < NUM;i++){
		delete [] color[i];}
	delete [] color;

	return 0;
}
