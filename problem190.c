#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	double pAx;
	double pAy;
	double pBx;
	double pBy;
	double pCx;
	double pCy;
};

void calcCirc(struct triangle t);

int main()
{
	 int i=0;
	char line[10], ch;
	struct triangle t;
	
	while(ch != EOF)
	{
		fscanf(stdin, "%s", line);
		t.pAx = atof(line);
		fscanf(stdin, "%s", line);
		t.pAy = atof(line);
		fscanf(stdin, "%s", line);
		t.pBx = atof(line);
		fscanf(stdin, "%s", line);
		t.pBy = atof(line);
		fscanf(stdin, "%s", line);
		t.pCx = atof(line);
		fscanf(stdin, "%s", line);
		t.pCy = atof(line);
		ch = fgetc(stdin);
		if(i!=0) printf("\n");
		calcCirc(t);
		i++;
	}
	return(0);
}

void calcCirc(struct triangle t)
{
	double centerX, centerY, mABx, mABy, mBCx, mBCy, cmAB, cmBC, raio, p, a, b, c, cc, d, e;
	mABx = (t.pBx + t.pAx)/2;
	mABy = (t.pBy + t.pAy)/2;
		
	mBCx = (t.pCx + t.pBx)/2;
	mBCy = (t.pCy + t.pBy)/2;
		
	cmAB = -1/((t.pBy - t.pAy)/(t.pBx - t.pAx));
	cmBC = -1/((t.pCy - t.pBy)/(t.pCx - t.pBx));
		
	centerX = (mABy - cmAB*mABx - mBCy + cmBC*mBCx) / (cmBC - cmAB);
	centerY = cmAB * (centerX - mABx) + mABy;
		
	a = pow(pow((t.pCx - t.pBx), 2) + pow((t.pCy - t.pBy), 2), 1/2.);
	b = pow(pow((t.pCx - t.pAx), 2) + pow((t.pCy - t.pAy), 2), 1/2.);
	c = pow(pow((t.pBx - t.pAx), 2) + pow((t.pBy - t.pAy), 2), 1/2.);
	p = (a + b + c)/2;
	raio = (a * b * c) / (4 * pow(p * (p - a) * (p - b) * (p - c), 1/2.));
		
	cc = -2*centerX;
	d = -2*centerY;
	e = pow(centerX,2) + pow(centerY,2) - pow(raio,2);
		
	if(centerX > 0 && centerY > 0) printf("(x - %.3f)^2 + (y - %.3f)^2 = %.3f^2\n", centerX, centerY, raio);
	else if(centerX > 0 && centerY < 0)
	{
		centerY = -1*centerY;
		printf("(x - %.3f)^2 + (y + %.3f)^2 = %.3f^2\n", centerX, centerY, raio);
	}
	else if(centerX < 0 && centerY > 0)
	{
		centerX = -1*centerX;
		printf("(x + %.3f)^2 + (y - %.3f)^2 = %.3f^2\n", centerX, centerY, raio);
	}
	else
	{
		centerX = -1*centerX;
		centerY = -1*centerY;
		printf("(x + %.3f)^2 + (y + %.3f)^2 = %.3f^2\n", centerX, centerY, raio);
	}
	
	if(cc > 0 && d > 0 && e > 0) printf("x^2 + y^2 + %.3fx + %.3fy + %.3f = 0\n", cc, d, e);
	else if(cc < 0 && d > 0 && e > 0)
	{
		cc = -1*cc;
		printf("x^2 + y^2 - %.3fx + %.3fy + %.3f = 0\n", cc, d, e);
	}
	else if(cc < 0 && d < 0 && e > 0)
	{
		cc = -1*cc;
		d = -1*d;
		printf("x^2 + y^2 - %.3fx - %.3fy + %.3f = 0\n", cc, d, e);
	}
	else if(cc > 0 && d < 0 && e > 0)
	{
		d = -1*d;
		printf("x^2 + y^2 + %.3fx - %.3fy + %.3f = 0\n", cc, d, e);
	}
	else if(cc > 0 && d < 0 && e < 0)
	{
		d = -1*d;
		e = -1*e;
		printf("x^2 + y^2 + %.3fx - %.3fy - %.3f = 0\n", cc, d, e);
	}
	else if(cc > 0 && d > 0 && e < 0)
	{
		e = -1*e;
		printf("x^2 + y^2 + %.3fx + %.3fy - %.3f = 0\n", cc, d, e);
	}
	else if(cc < 0 && d > 0 && e < 0)
	{
		cc = -1*cc;
		e = -1*e;
		printf("x^2 + y^2 - %.3fx + %.3fy - %.3f = 0\n", cc, d, e);
	}
	else
	{
		cc = -1*cc;
		d = -1*d;
		e = -1*e;
		printf("x^2 + y^2 - %.3fx - %.3fy - %.3f = 0\n", cc, d, e);
	}
}