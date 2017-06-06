#include <fstream>  
#include <iostream>  
#include <stdlib.h>  
#include <algorithm>  
using namespace std; 


int permuatation  (int n, bool **adj_mat){
	int count;
	count = 0;
	int a,b,c,d;

	ofstream fout;
	fout.open("output.txt",ios::app);
	if(!fout){
        cout << "Open the file failure...\n";
        exit(0);
    }

	for (a=0;a<=n-4;a++){
		for (b=a+1;b<=n-3;b++){
			for (c=b+1;c<=n-2;c++){
				for (d=c+1;d<=n-1;d++){
					int num;
					//cout << "Current permutation:" <<" "<< a<<" "<< b<<" "<< c<<" "<< d<< endl;  
					num = adj_mat[a][b] + adj_mat[a][c] + adj_mat[a][d] + adj_mat[b][c] + adj_mat[b][d] + adj_mat[c][d];
					if (num == 0 || num == 6){
						count += 1;
						//fout << "Find a clique "; 
						//fout << "in the permutation:" <<" "<< a<<" "<< b<<" "<< c<<" "<< d<< endl;  
					}
				}
			}
		}
	}
	fout << "Total number of cliques£º" <<count<< endl;  
	return count;
}