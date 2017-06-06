# edge-coloring

The program finds a feasible two-coloring of Kn with at most n!/((n-4!)*4!)*2^(-5) monochromatic copies of K4.

Method1: Ramdom coloring
By applying the probabilistic method, we can prove that there exists a feasible two-coloring method because the desired property hold in the probability space with possitive possibility.Then, we just randomly choose the color of each edge, we must find a feasible solution as long as we try enough times.(Actually, it doesn't need many attempts.)
Code for Method1:
prob_method.cpp (main function)
permutation.cpp


Method2: Derandomization
We choose the color of the edges on after another based on a certain principal.After all the edges get a fixed color, there must be less than n!/((n-4!)*4!)*2^(-5) monochromatic copies of K4, which meets the desired property.
Code for Method2:
derandomized.cpp (main function)
derandomized.h
color_choice.cpp
color_choice.h
update.cpp
update.h
permutation.cpp

You can modify the number of node by change the value of NUM in .h files.CLIQUE_MAX and PERMUTATION in derandomized.h should be changed accordingly.

Example output:
Method 1:
Find a clique in the permutation: 0 1 2 5
Find a clique in the permutation: 0 1 2 8
Find a clique in the permutation: 0 1 5 8
Find a clique in the permutation: 0 2 5 8
Find a clique in the permutation: 1 2 5 8
Find a clique in the permutation: 1 3 7 9
Find a clique in the permutation: 1 5 6 8
Find a clique in the permutation: 3 4 7 8
Total number of cliques：8
Find a clique in the permutation: 0 1 2 7
Find a clique in the permutation: 0 1 6 8
Find a clique in the permutation: 1 2 4 7
Find a clique in the permutation: 1 2 4 9
Find a clique in the permutation: 1 2 5 7
Total number of cliques：5
Find a feasible solution:
x 1 1 1 0 0 1 1 1 0 
x x 1 0 1 1 1 1 1 1 
x x x 0 1 1 0 1 0 1 
x x x x 0 1 0 1 0 1 
x x x x x 0 0 1 1 1 
x x x x x x 0 1 1 0 
x x x x x x x 0 1 0 
x x x x x x x x 0 0 
x x x x x x x x x 0 
x x x x x x x x x x 

Method2:
Totol number of cliques：495
Find a feasible solution:
x 0 1 0 1 1 0 1 0 0 1 0 1 1 0 1 0 1 0 0 1 1 0 1 0 0 1 1 0 1 
x x 0 1 1 0 1 0 1 1 0 1 0 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 
x x x 0 0 1 1 0 1 0 1 1 0 0 1 1 0 0 1 1 0 1 0 1 0 1 0 0 1 1 
x x x x 0 1 0 1 1 1 0 0 1 1 0 0 1 1 0 1 0 0 1 0 1 1 0 1 0 0 
x x x x x 0 1 0 0 1 1 0 1 0 1 0 1 0 1 0 1 0 0 1 1 1 0 1 0 1 
x x x x x x 0 1 0 0 0 1 1 1 0 0 0 1 1 1 0 0 1 0 0 1 1 0 1 0 
x x x x x x x 0 1 0 1 1 0 1 0 1 0 0 0 1 1 1 0 0 1 0 1 1 0 0 
x x x x x x x x 0 1 0 1 0 1 1 1 0 1 0 0 0 1 1 1 0 0 0 1 1 0 
x x x x x x x x x 0 1 0 1 0 1 1 1 0 0 0 0 1 1 0 0 1 1 0 1 1 
x x x x x x x x x x 0 1 0 0 1 1 1 0 1 1 0 0 0 1 1 0 0 1 0 1 
x x x x x x x x x x x 0 1 0 0 0 1 1 1 1 0 1 0 0 1 0 1 0 1 0 
x x x x x x x x x x x x 0 1 0 0 1 1 0 0 1 1 0 1 0 1 0 0 1 1 
x x x x x x x x x x x x x 0 1 0 0 1 1 1 1 0 0 0 0 1 0 1 0 1 
x x x x x x x x x x x x x x 1 1 0 0 1 0 1 0 1 1 1 0 1 0 0 1 
x x x x x x x x x x x x x x x 0 0 1 1 0 0 1 1 0 0 0 1 1 1 0 
x x x x x x x x x x x x x x x x 1 0 0 1 1 0 1 1 0 0 1 0 0 1 
x x x x x x x x x x x x x x x x x 1 0 0 1 0 1 1 0 1 0 0 1 0 
x x x x x x x x x x x x x x x x x x 0 1 0 1 0 0 1 1 0 0 0 1 
x x x x x x x x x x x x x x x x x x x 1 0 0 1 1 1 0 0 0 1 1 
x x x x x x x x x x x x x x x x x x x x 1 0 0 0 1 0 1 1 0 0 
x x x x x x x x x x x x x x x x x x x x x 1 1 0 0 1 0 1 0 0 
x x x x x x x x x x x x x x x x x x x x x x 1 0 1 1 0 1 1 0 
x x x x x x x x x x x x x x x x x x x x x x x 0 0 1 1 0 0 0 
x x x x x x x x x x x x x x x x x x x x x x x x 1 1 1 1 1 0 
x x x x x x x x x x x x x x x x x x x x x x x x x 0 1 0 0 1 
x x x x x x x x x x x x x x x x x x x x x x x x x x 0 1 0 1 
x x x x x x x x x x x x x x x x x x x x x x x x x x x 1 1 0 
x x x x x x x x x x x x x x x x x x x x x x x x x x x x 0 0 
x x x x x x x x x x x x x x x x x x x x x x x x x x x x x 1 
x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x 
