#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"


int main()
{
 // Declaring and initializing variables
 double a = 12, k = 18,theta = M_PI * 1/2 , **r, c;
 float cosine = cos(theta);
 float sine = sin(theta);
 double **e2, **q1, **q2, **q, **A;

 // Loading data from files into matrix e2,q1
 e2 = loadtxt("e2.dat",2,1);
 q1 = loadtxt("q1.dat",2,2);

 // Creating a 2x1 matrix q2 and assigning values 
 q2 = createMat(2,1);
 q2[0][0] = a*a/k;
 q2[1][0] = k;

 // Matrix multiplication of q1 and q2, storing the result in q
 q = matmul(q1,q2,2,2,1);
 r = matmul(transpose(e2,2,1),q,2,2,1);
 c = 1/(2*(1-(a*cosine)/k))*r[0][0];
 A = np_array(c*cosine,c*sine);
 // Saving matrix A to file
 save_D(A,2,1);
 return 0;
}

