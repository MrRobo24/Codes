#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    }

    return n * factorial(n-1);
}


void calcBlending(int* blending, int n) {
    int nFac = factorial(n-1), i;
    for (i=0;i<n;i++) {
        blending[i] = (int)nFac/( factorial(i) * factorial(n-1-i));
    }
}

void printBlending(int* blending, int n) {
    int i;
    printf("The Blending Function Values Are: \n");
    for (i=0;i<n;i++) {
        printf("B[%d,%d](u) = %d (1-u)^%d u^%d\n", n-1, i, blending[i], n-1-i, i);
    }
}

void drawBezier(float* x, float* y, int* blending, int n) {

    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

    int i;
    float u;
    for (u=0.0000;u<=1.0000;u += 0.0001) {
        float xx=0.0,yy=0.0;
        for (i=0;i<n;i++) {
            float pref = blending[i] * pow((1-u),n-1-i) * pow(u,i);
            xx += pref * x[i];
            yy += pref * y[i];
        }

        //printf("%f %f\n", xx, yy);
        putpixel(xx, yy);
    }

    closegraph();
}


void main() {
    int n;
    printf("Enter the number of control points: ");
    scanf("%d", &n);

    float x[n], y[n];
    int blending[n];
    printf("Enter the coordinates of control points\n");
    int i;
    for (i=0;i<n;i++) {
        printf("Enter the control point %d:\n", i+1);
        scanf("%f %f", &x[i], &y[i]);
    }

    calcBlending(blending, n);
    printBlending(blending, n);
    drawBezier(x, y, blending, n);
    getch();
}