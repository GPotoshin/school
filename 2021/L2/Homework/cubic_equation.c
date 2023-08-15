#include <stdio.h>
#include <math.h>

#define f(x) (a * pow(x, 3) + b * pow(x, 2) + c * x + d)
#define LOG(x) printf(">>> %lf\n", (double)x)



int main (void)
{
    
    float a, b, c, d;
    
    
    

        
    printf("ax^3 + bx^2 + cx + d = 0");

    printf("\nEnter: a = ");
    scanf("             %f",&a);
        
    printf("\nEnter: b = ");
    scanf("             %f",&b);

    printf("\nEnter: c = ");
    scanf("             %f",&c);

    printf("\nEnter: d = ");
    scanf("             %f",&d);
        
        
        
        
        
        
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                printf("\n\n%f = 0", d);
                if (d != 0)
                {
                    printf("\nNo solutions!\n\n");
                }
                
                else
                {
                    printf("\nAny number\n\n");
                }
            }
                
            else
            {
                printf("\n\n %fx + %f = 0", c, d);
                printf("\nx = %lf\n\n", (-d)/c);
            }
        }
            
            
            
            
        //square equation
        else
        {
            double t = c * c - 4 * b * d;
            printf("\n\n%fx^2 + %fx + %f\n", b, c, d);

            if (0 < t)
            {
                printf("\nx1 = %lf.\nx2 = %lf.\n\n",
                    0.5 * ( (-c) + sqrt(t))/b,
                    0.5 * ( (-c) - sqrt(t))/b);
            }

            else if (0 == t)
            {
                printf("\nx = %lf\n\n",
                    0.5 * (-c)/b);
            }
                
            else
            {
                printf("\nx1 = %lf + i * %lf.\nx2 = %lf - i * %lf.\n\n",
                    0.5 * (-c)/b, 0.5 * sqrt(-t)/b,
                    0.5 * (-c)/b, 0.5 * sqrt(-t)/b);
            }
        }
    }
    
    else
    {
        double m, n;
        double _a = a * 3;
        double _b = b * 2;
        double _c = c;
        double x = 0;
        double x0 = -0.5 * _b / _a;
        
        if(f(x0) > 0)
        {
            n = x0;
            
            if(a > 0)
            {
                while (f(n) > 0)
                {
                    n--;
                }
                n++;
                m = n - 1;
            }
            else
            {
                while (f(n) > 0)
                {
                    n++;
                }
                n--;
                m = n + 1;
            }
        }
        else if (f(x0) < 0)
        {
            m = x0;
            if(a > 0)
            {
                while (f(m) < 0)
                {
                    m++;
                }
                m--;
                n = m + 1;
            }
            else
            {
                while (f(m) > 0)
                {
                    m--;
                }
                m++;
                n = m - 1;
            }
        }
        else
        {
            x = x0;
            _a = a;
            _b = a * x + b;
            _c = a * pow(x, 2) + b * x + c;
            
            double t = _b * _b - 4 * _a * _c;

            if (0 < t)
            {
                printf("\nx1 = %lf.\nx2 = %lf.\nx3 = %lf.\n\n",
                    0.5 * ( (-_b) + sqrt(t))/_a,
                    0.5 * ( (-_b) - sqrt(t))/_a,
                    x);
            }

            else if (0 == t)
            {
                printf("\nx1 = %lf.\nx2 = %lf.\n\n",
                    0.5 * (-_b)/_a,
                    x);
            }
                
            else
            {
                printf("\nx1 = %lf + i * %lf.\nx2 = %lf - i * %lf.\nx3 = %lf\n\n",
                    0.5 * (-_b)/_a, 0.5 * sqrt(-t)/_a,
                    0.5 * (-_b)/_a, 0.5 * sqrt(-t)/_a,
                    x);
            }
            return 0;
        }

        //m < n
        for (int i = 0; i < 25; i++)
        {
            x = 0.5 * (m + n);
            
            if (f(x) > 0)
            {
                n = 0.5 * (m + n);
            }
            
            else if (f(x) < 0)
            {
                m = 0.5 * (m + n);
            }
            else
            {
                i = 20;
            }
            
        }
        
        _a = a;
        _b = a * x + b;
        _c = a * pow(x, 2) + b * x + c;
        
        double t = _b * _b - 4 * _a * _c;

        if (0 < t)
        {
            printf("\nx1 = %lf.\nx2 = %lf.\nx3 = %lf.\n\n",
                0.5 * ( (-_b) + sqrt(t))/_a,
                0.5 * ( (-_b) - sqrt(t))/_a,
                x);
        }

        else if (0 == t)
        {
            printf("\nx1 = %lf.\nx2 = %lf.\n\n",
                0.5 * (-_b)/_a,
                x);
        }
            
        else
        {
            printf("\nx1 = %lf + i * %lf.\nx2 = %lf - i * %lf.\nx3 = %lf\n\n",
                0.5 * (-_b)/_a, 0.5 * sqrt(-t)/_a,
                0.5 * (-_b)/_a, 0.5 * sqrt(-t)/_a,
                x);
        }
    }
    return 0;
}
