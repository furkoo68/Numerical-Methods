#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

float max1(float e1,float f1,float g1,float h1,float e0,float f0,float g0,float h0);

float max2(float a,float b,float c,float d);

float f1(float x,float y,float z,float w)
{
  return ((1-1.2)*x+1.2*((-y+z-w-2)/4));
}

float f2(float x,float y,float z,float w)
{
  return ((1-1.2)*y+1.2*((-x+z+w-1)/4));
}

float f3(float x,float y,float z,float w)
{
  return ((1-1.2)*z+1.2*((x+y-w)/5));
}

float f4(float x,float y,float z,float w)
{
  return ((1-1.2)*w+1.2*((-x+y-z+1)/3));
}

void main()
{
  float x0,y0,z0,w0,x1=0,y1=0,z1=0,w1=0,tempx,tempy,tempz,tempw,Es=0.01;
  float numerator, denominator, Ea; 
  int iteration=0;
  
  printf("Enter initial guesses:\n");
  scanf("%f %f %f %f",&x0,&y0,&z0,&w0);
 
  printf("___________________________________");
  printf("\n");
 
  do
  {
    tempx=x1;
    tempy=y1;
    tempz=z1;
    tempw=w1;

    x1=f1(x0,y0,z0,w0);
    y1=f2(x1,y0,z0,w0);
    z1=f3(x1,y1,z0,w0);
	  w1=f4(x1,y1,z1,w0);
	  
    iteration++;
    
    numerator = max1(x1,y1,z1,w1,x0,y0,z0,w0);
	  denominator = max2(x1,y1,z1,w1);
    Ea = numerator/denominator;
	
	  x0=x1;
    y0=y1;
    z0=z1;
    w0=w1;
    
    printf("\n");
    printf("%d. ITERATION\n\n",iteration);
    printf("x=%f \ny=%f \nz=%f \nw=%f \n",x1,y1,z1,w1);
    printf("\n");
    printf("Ea = %f", Ea);
    printf("\n");
    printf("\n");
    printf("___________________________________");
    printf("\n");
  }while(Ea > Es);

  printf("\nAt the end of %d iterations:\n\n", iteration);
  printf("x=%f \ny=%f \nz=%f \nw=%f \n",x1,y1,z1,w1);
  printf("\n");
  printf("Ea = %f", Ea);
  printf("\n");
  printf("___________________________________");
  
  getch();
}
//________________________________________________________

float max1(float e1,float f1,float g1,float h1,float e0,float f0,float g0,float h0)
{
  float maxdif; // maximum difference

  maxdif = fabs(e1-e0);   // initially assume that |e1-e0| is the maximum difference.

  if (fabs(f1-f0) > maxdif)
      maxdif = fabs(f1-f0);
      
  if (fabs(g1-g0) > maxdif)
      maxdif = fabs(g1-g0);
	 
  if (fabs(h1-h0) > maxdif)
      maxdif = fabs(h1-h0);  

  return maxdif;
}

float max2(float a,float b,float c,float d)
{
  float max;

  max = fabs(a);   // initially assume that a is the max.

  if (fabs(b) > max)
      max = fabs(b);
      
  if (fabs(c) > max)
      max = fabs(c);
	 
  if (fabs(d) > max)
      max = fabs(d);  

  return max;
}

