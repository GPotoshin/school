#include <stdio.h>
#include <math.h>

#define f(x)  (R * sqrt(1 - pow(x/R, 2)))

int main(void){
    double delta;
    int n;
    double R, x;
    double sigmaR = 0;
    double sigmaL = 0;

    printf("Enter n:\n>");
    scanf(" %d", &n);
    if(n <= 0){
        printf("n should be positive!");
        return 1;
    }


    printf("Enter R:\n>");
    scanf(" %lf", &R);
    if(R <= 0){
        printf("R should be positive!\n");
        return 2;
    }

    delta = 2 * R / n;
    x = -R;
    for(int i = 0; i < n; i++){
        x = x + delta;
        sigmaR = sigmaR + delta * f(x);
    }

    x = -R;
    for(int i = 0; i < n; i++){
        sigmaL = sigmaL + delta * f(x);
        x = x + delta;
    }

    printf("PI * R^2 / 2 = %lf\n", M_PI * R * R / 2);
    printf("sigmaL = %lf\n", sigmaL);
    printf("sigmaR = %lf\n", sigmaR);

    return 0;
}

