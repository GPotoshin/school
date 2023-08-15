#include <stdio.h>
#include <stdbool.h>


long A_(int n, int k)
{
    long out = n;
    for (int i = 1; i < k; i++)
    {
        out = out * (n - i);
    }
    
    return out;
}

long C_(int n, int k)
{
    long out = 1;
    bool does_it_divide = false;
    int dividend;
    
    
    int part_of_k_factorial[k + 1];
    for (int i = 2; i <= k; i++)
    {
        part_of_k_factorial[i] = i;
    }
    
    for (int i = 0; i < k; i++)
    {
        dividend = n - i;
        for (int x = k; does_it_divide == false && x > 1; x--)
        {
            if (dividend % part_of_k_factorial[x] == 0 && part_of_k_factorial[x] != 1)
            {
                out = out * dividend/part_of_k_factorial[x];
                does_it_divide = true;
                part_of_k_factorial[x] = 1;
            }
            else
            {
                if (x == 2)
                {
                    out = out * dividend;
                }
                else
                {
                does_it_divide = false;
                }
            }
        }
        does_it_divide = false;
    }
    
    return out;
}





int main(void)
{
    int k, n;
    int what_you_have_pressed;
    printf("What do you want to solve:\nIf C_n_k, press 1\nIf A_n_k, press numeral you like except 1\n>");
    scanf(" %d", &what_you_have_pressed);
    
    printf("\nn >= k > 0\n");

    printf("enter n:\n>");
    scanf(" %d", &n);

    printf("enter k:\n>");
    scanf(" %d", &k);
    
    if (n < 0 || k < 0 || n < k)
    {
        printf("\nError...\nn should be bigger or equal to k,\nWhile k should be bigger than zero\n");
        printf("%d >= %d > 0 --> contradiction\n", n, k);
        return 1;
    }

    
    if (what_you_have_pressed == 1)
    {
        printf("Answer is %ld\n", C_(n, k));
    }
    
    else
    {
        printf("Answer is %ld\n", A_(n, k));
    }

    
    return 0;
}
