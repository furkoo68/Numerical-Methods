#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141593

float f1(float x, float y, float z)
{
	return (3*x-cos(y*z)-0.5);
}

float f2(float x, float y, float z)
{
	return (x*x-81*(y+0.1)*(y+0.1)+sin(z)+1.06);
}

float f3(float x, float y, float z)
{
	return (exp(-x*y)+20*z+(10*PI-3)/3);
}

float df1x(float x, float y, float z)
{
	return 3;
}

float df1y(float x, float y, float z)
{
	return (z*sin((y*z)));
}

float df1z(float x, float y, float z)
{
	return (y*sin(y*z));
}

float df2x(float x, float y, float z)
{
	return (2*x);
}

float df2y(float x, float y, float z)
{
	return ((-162)*y-16.2);
}

float df2z(float x, float y, float z)
{
	return (cos(z));
}

float df3x(float x, float y, float z)
{
	return ((-y)*exp((-x)*y));
}

float df3y(float x, float y, float z)
{
	return ((-x)*exp(-x*y));
}

float df3z(float x, float y, float z)
{
	return 20;
}

//________________________________________________________

int main()
{
	// put the x, y, z values for every iteration and run the program again.
	float x0=0.1,y0=0.1,z0=-0.1; 
	float f1x,f1y,f1z,f2x,f2y,f2z,f3x,f3y,f3z;
	float nf1,nf2,nf3;

		  	
	f1x=df1x(x0,y0,z0); // J[1][1]
    f1y=df1y(x0,y0,z0); // J[1][2]
    f1z=df1z(x0,y0,z0); // J[1][3]
    f2x=df2x(x0,y0,z0); // J[2][1]
    f2y=df2y(x0,y0,z0); // J[2][2]
    f2z=df2z(x0,y0,z0); // J[2][3]
    f3x=df3x(x0,y0,z0); // J[3][1]
    f3y=df3y(x0,y0,z0); // J[3][2]
    f3z=df3z(x0,y0,z0); // J[3][3]
    
    
    nf1=f1(x0,y0,z0);
    nf2=f2(x0,y0,z0);
    nf3=f3(x0,y0,z0);
	
    
    printf("\n");
	printf("f1x=%f \nf1y=%f \nf1z=%f \n",f1x,f1y,f1z);
	printf("f2x=%f \nf2y=%f \nf2z=%f \n",f2x,f2y,f2z);
	printf("f3x=%f \nf3y=%f \nf3z=%f \n",f3x,f3y,f3z);
    printf("\n\n");
    printf("nf1=%f \nnf2=%f \nnf3=%f \n",nf1,nf2,nf3);
    printf("\n\n");
}
