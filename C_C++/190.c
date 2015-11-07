#include <stdio.h>
#include <math.h>

struct triangle
{
	double Ax;
	double Ay;
	double Bx;
	double By;
	double Cx;
	double Cy;
};

void calcCirc(struct triangle t);

int main ()
{
    struct triangle t;
    double input = 0.0;
    int ch = 00, i = 0;

    while (ch != EOF)
    {
        fscanf(stdin, "%lf", &input);
        t.Ax = input;
        fscanf(stdin, "%lf", &input);
        t.Ay = input;
        fscanf(stdin, "%lf", &input);
        t.Bx = input;
        fscanf(stdin, "%lf", &input);
        t.By = input;
        fscanf(stdin, "%lf", &input);
        t.Cx = input;
        fscanf(stdin, "%lf", &input);
        t.Cy = input;
        ch = fgetc(stdin);
        if (ch == EOF) return(0);
        if (i != 0) printf("\n");
        calcCirc(t);
        i++;
    }
    return(0);
}

void calcCirc(struct triangle t)
{
    double mABx, mABy, mBCx, mBCy, cAB, cBC, cmAB, cmBC, AB, AC, BC, ABC;
    double h, k, r, c, d, e, p;
    int op1=45, op2=45, op3=43, op4=43, op5=43;

    mABx = (t.Ax + t.Bx)/2.0;
    mABy = (t.Ay + t.By)/2.0;
    mBCx = (t.Bx + t.Cx)/2.0;
    mBCy = (t.By + t.Cy)/2.0;

    cAB = (t.By - t.Ay)/(t.Bx - t.Ax);
    cBC = (t.Cy - t.By)/(t.Cx - t.Bx);
    cmAB = -1.0/cAB;
    cmBC = -1.0/cBC;

    h = (mABy - cmAB*mABx - mBCy + cmBC*mBCx)/(cmBC - cmAB);
    k = mABy - cmAB*mABx + cmAB*h;

    AB = sqrt(pow((t.Bx - t.Ax),2.0) + pow((t.By - t.Ay),2.0));
    AC = sqrt(pow((t.Cx - t.Ax),2.0) + pow((t.Cy - t.Ay),2.0));
    BC = sqrt(pow((t.Cx - t.Bx),2.0) + pow((t.Cy - t.By),2.0));
    p = (AB + AC + BC)/2.0;
    ABC = AB * AC * BC;
    r = ABC / (4.0 * sqrt(p * (p - AB) * (p - AC) * (p - BC)));
    c = -2.0 * h;
    d = -2.0 * k;
    e = pow(h, 2.0) + pow(k, 2.0) - pow(r,2.0);

    if (h < 0)
    {
        h*=-1.0;
        op1 = 43;
    }
    if (k < 0)
    {
        k*=-1.0;
        op2 = 43;
    }
    if (c < 0)
    {
        c*=-1.0;
        op3 = 45;
    }
    if (d < 0)
    {
        d*=-1.0;
        op4 = 45;
    }
    if (e < 0)
    {
        e*=-1.0;
        op5 = 45;
    }

    printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\nx^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n", op1,h,op2,k,r,op3,c,op4,d,op5,e);
}
