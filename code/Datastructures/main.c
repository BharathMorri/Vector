#include<stdio.h>   
#include<stdlib.h>  
#include<math.h>
#include"lib.h"

int main()
{  
	 //Initializing variables
	 double a = 12, k = 18, theta = M_PI * 1/2 ,c, r1;

         double cosine = cos(theta), sine = sin(theta); 
	 double **q1, **q2, **B, **C, **e2, **A;  
         node *q, *matrixq1, *matrixq2, *e2_, *r;
	

         B = createmat(0.0, 0.0);
	 //Constructing linked matrix vertexB from B
         node* vertexB = constructLinkedMatrix(B,2,1);
         createDatMat("B.dat", vertexB); 

	 C = createmat(8, 0);
	 //Constructing linked matrix vertexC from C
         node* vertexC = constructLinkedMatrix(C,2,1);
	 createDatMat("C.dat", vertexC);

         q1 = createMatrix(1, 1, -1, 1);
	 //Constructing linked matrix matrixq1 from q1
	 matrixq1 = constructLinkedMatrix(q1,2,2);
	 
         q2 = createmat(pow(a,2)/k, k); 
	 //Constructing linked matrix matrixq2 from q2
         matrixq2 = constructLinkedMatrix(q2,2,1);        
         

         e2 = createmat(0.0, 1.0); 
         node* vertexe2 = constructLinkedMatrix(e2,2,1);
         
         //matrix multiplication of matrixq1 and matrixq2,storing the result in q
	 q = matMul(matrixq1,matrixq2);
         
	 e2_ = transpose(vertexe2);
	
         r = matMul(e2_,q);
         r1 = get(r);
        
	 c = 1/(2*(1-(a*cosine)/k))*r1;
          
	 //Creating matrix A
	 A = createmat(c*cosine,c*sine); 
	 //Constructing linked matrix vertexA from A
	 node* vertexA = constructLinkedMatrix(A,2, 1);  
        createDatMat("A.dat", vertexA);

    return 0;

}
