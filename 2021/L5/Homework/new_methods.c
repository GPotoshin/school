#include <stdio.h>
#include <math.h>
#define method 1

double f(double a)
{
    return sqrt(1 - 10 * pow(a, 5)) - 2 * a - 7 + sin(5 * a);
}

int main(int argc, const char * argv[]) {
    double a, b, x;
    printf("sqrt(1 - 10*x^5) - 2x - 7 + sin(5x) = 0\n");
    
    //a, b <= 10^(-5)
    
    a = 0;
    b = -5;
    double _a = b;
    double _b = a;
    
    
    if(a > pow(10, -5) || b > pow(10, -5)) return 1;

    
    if ( f(a)*f(b) < 0)
    {
        if (f(a) > f(b))
        {
            a = _a;
            b = _b;
        }
    }
    else return 2;
    
    printf("f(0) = %lf\nf(0) < 0\n", f(a));
    printf("f(5) = %lf\nf(5) > 0\n", f(b));
    
    double accuracy = 0.1;
    int it = (int) log2((a -b)/accuracy);

    
    if (method == 1) {
        x = (a + b)/2;
        for(int i = 0; i < it; i++)
        {
            if (f(x) < 0)
            {
                a = x;
                x = (a + b)/2;
            }
            else if(f(x) > 0)
            {
                b = x;
                x = (a + b)/2;
            }
            else
            {
                i = it;
            }
        }

	printf("%lf\n", a - b);
    }
    else
    {
        x = (f(a) * b - f(b) * a)/(f(a) - f(b));
        for(int i = 0; i < it; i++)
        {
            if (f(x) < 0)
            {
                a = x;
                x = (f(a) * b - f(b) * a)/(f(a) - f(b));
            }
            else if(f(x) > 0)
            {
                b = x;
                x = (f(a) * b - f(b) * a)/(f(a) - f(b));
            }
            else
            {
                i = it;
            }
        }
    }
    
    
    printf("x = %lf\n", x);
    
    return 0;
}
