#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"


int main()
{
 double angle=90.0;
 double rad=radians(angle);
 double a = 12, k = 18, **r, c;
 float cosine = 0;
 float sine = 1;
 double **e2, **q1, **q2, **q, **A;
 
 e2 = loadtxt("e2.dat",2,1);
 q1 = loadtxt("q1.dat",2,2);

        q2 = createMat(2,1);
 q2[0][0] = a*a/k;
 q2[1][0] = k;

 q = matmul(q1,q2,2,2,1);
        r = matmul(transpose(e2,2,1),q,2,2,1);
 c = 1/(2*(1-(a*cosine)/k))*r[0][0];
 A = np_array(c*cosine,c*sine);
 save_D(A,2,1);
 return 0;
}

