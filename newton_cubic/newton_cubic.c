#include <stdio.h>
#include <math.h>


//define LOG(x) printf("%lf\n", x)
#define LOG(x)


void sqr_equation(float a, float b, float c, double *Re_x1, double *Im_x1, double *Re_x2, double *Im_x2)
{
    double d = b * b - 4 * c * a;

    if (b >= 0)
    {
        *Re_x1 = 0.5 * ( (-b) + sqrt(d))/a;
        *Re_x2 = 0.5 * ( (-b) - sqrt(d))/a;
        *Im_x1 = 0;
        *Im_x2 = 0;
    }
    
    if (d < 0)
    {
        *Re_x1 = 0.5 * (-b)/a;
        *Re_x2 = 0.5 * (-c)/a;
        *Im_x1 = 0.5 * sqrt(-d)/a;
        *Im_x2 = 0.5 * sqrt(-d)/a;
    }
}



int main(void) {
    
    
    float a, b, c, d;
    
    
    printf("ax^3 + bx^2 + cx + d = 0");

    // Input a, b, c, d
    printf("\nEnter: a = ");
    scanf("             %f",&a);
    
    printf("\nEnter: b = ");
    scanf("             %f",&b);

    printf("\nEnter: c = ");
    scanf("             %f",&c);

    printf("\nEnter: d = ");
    scanf("             %f",&d);
    
    
    //Linear and constant equation
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

            if (0 == t)
            {
                printf("\nx = %lf\n\n",
                  0.5 * (-c)/b);
            }
            
            if (t < 0)
            {
                printf("\nx1 = %lf + i * %lf.\nx2 = %lf - i * %lf.\n\n",
                  0.5 * (-c)/b, 0.5 * sqrt(-t)/b,
                  0.5 * (-c)/b, 0.5 * sqrt(-t)/b);
            }
        }
    }
    
    
    
    //Newton's method for cubic eq1uation
    
    else
    {
        double Re_x1, Re_x2, Im_x1, Im_x2, o, f_o_;
        
        
        printf("\n\n%fx^3 + %fx^2 + %fx + %f = 0\n", a, b, c, d);
        
        o = -b/(3 * a);
        f_o_ = a*o*o*o + b*o*o + c*o + d;
        
        sqr_equation(3 * a, 2 * b, c, &Re_x1, &Im_x1, &Re_x2, &Im_x2); //That way we find extremum points
        
        
        if (f_o_ == 0)
        {
            sqr_equation(a, b + a*o, c + b*o + a*o*o, &Re_x1, &Im_x1, &Re_x2, &Im_x2);
            LOG(1.0);
            LOG(a);
        }
        else
        {
            int m, n;
            printf("Choose accuracy (Recomended > 15):\n>");
            scanf(" %d", &m);
            if (m<=0) {printf("Error\n Accuracy should be positive\n"); return 1;}
            
            
            LOG(Im_x1);
            if (Im_x1 != 0)
            {
                
                if (a > 0)
                {
                    if (f_o_ < 0)
                    {
                        LOG(2.0);
                        o = o + 1;
                        for (n = 0; n < m; n++)
                        {
                            LOG(o);
                            o = o - (a * pow(o,3) + b * pow(o,2) + c * a + d)/(3*a*o*o + 2*b*o + c);
                        }
                            sqr_equation(a, b + a*o, c + b*o + c*o*o, &Re_x1, &Im_x1, &Re_x2, &Im_x2);
                    }
                    else
                    {
                        LOG(3.0);
                        o = o - 1;
                        for (n = 0; n < m; n++)
                        {
                            LOG(o);
                            o = o - (a * pow(o,3) + b * pow(o,2) + c * a + d)/(3*a*o*o + 2*b*o + c);
                        }
                        sqr_equation(a, b + a*o, c + b*o + c*o*o, &Re_x1, &Im_x1, &Re_x2, &Im_x2);
                    }
                }
                else
                {
                    if (f_o_ < 0)
                    {
                        LOG(4.0);
                        o = o - 1;
                        for (n = 0; n < m; n++)
                        {
                            LOG(o);
                            o = o - (a * pow(o,3) + b * pow(o,2) + c * a + d)/(3*a*o*o + 2*b*o + c);
                        }
                        sqr_equation(a, b + a*o, c + b*o + c*o*o, &Re_x1, &Im_x1, &Re_x2, &Im_x2);
                    }
                    else
                    {
                        LOG(5.0);
                        o = o + 1;
                        for (n = 0; n < m; n++)
                        {
                            LOG(o);
                            o = o - (a * pow(o,3) + b * pow(o,2) + c * a + d)/(3*a*o*o + 2*b*o + c);
                        }
                        sqr_equation(a, b + a*o, c + b*o + c*o*o, &Re_x1, &Im_x1, &Re_x2, &Im_x2);
                    }
                }
            }
        

            // if (im_part == 0)
            else
            {
                if (a > 0)
                {
                    if (Re_x1 > 0)
                    {
                        LOG(6.0);
                        o = Re_x2 - 1;
                        for (n = 0; n < m; n++)
                        {
                            LOG(o);
                            o = o - (a * pow(o,3) + b * pow(o,2) + c * a + d)/(3*a*o*o + 2*b*o + c);
                        }
                        sqr_equation(a, b + a*o, c + b*o + c*o*o, &Re_x1, &Im_x1, &Re_x2, &Im_x2);
                    }
                    else
                    {
                        LOG(7.0);
                        o = Re_x1 + 1;
                        for (n = 0; n < m; n++)
                        {
                            LOG(o);
                            o = o - (a * pow(o,3) + b * pow(o,2) + c * a + d)/(3*a*o*o + 2*b*o + c);
                        }
                        sqr_equation(a, b + a*o, c + b*o + c*o*o, &Re_x1, &Im_x1, &Re_x2, &Im_x2);
                        
                    }
                }
                else
                {
                    if (Re_x1 < 0)
                    {
                        LOG(8.0);
                        o = Re_x2 - 1;
                        for (n = 0; n < m; n++)
                        {
                            LOG(o);
                            o = o - (a * pow(o,3) + b * pow(o,2) + c * a + d)/(3*a*o*o + 2*b*o + c);
                        }
                        sqr_equation(a, b + a*o, c + b*o + c*o*o, &Re_x1, &Im_x1, &Re_x2, &Im_x2);
                    }
                    else
                    {
                        LOG(9.0);
                        o = Re_x1 + 1;
                        for (n = 0; n < m; n++)
                        {
                            LOG(o);
                            o = o - (a * pow(o,3) + b * pow(o,2) + c * a + d)/(3*a*o*o + 2*b*o + c);
                        }
                        sqr_equation(a, b + a*o, c + b*o + c*o*o, &Re_x1, &Im_x1, &Re_x2, &Im_x2);
                        
                    }
                }
            }
        }
        printf("x1 = %f.\nx2 = %f + i * %f.\nx3 = %f - i * %f.\n", o, Re_x1, Im_x1, Re_x2, Im_x2);
    }
    return 0;
}
