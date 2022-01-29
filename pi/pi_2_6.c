#include <stdio.h>
#include <math.h>

int main(void)
{
	int accuracy, step;
	double sum = 0;

	//input the accuracy and which 
	//steps to show

	printf("Enter accuracy:\n>");
	scanf(" %d", &accuracy);

	printf("Enter step:\n>");
	scanf(" %d", &step);

	int it = pow(12, accuracy);

	for(int i = 1; i <= it; i++)
	{
		sum = sum + 1/pow(i, 2);

		if(i % step == 0 && i + step < accuracy)
		{
			printf("%lf\n", pow(6 * sum, 0.5));
		}

		if(i == accuracy) printf("%lf\n", pow(6 * sum, 0.5));
	}

	return 0;
}
