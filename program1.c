#include <stdio.h>
#include <stdlib.h>

int main(){
	const char *months[] = {"January", "February", "March", "April", "May", "June","July","August","September","October","November","December"};
	float sales[12];

	FILE* sales_file = fopen("input_p1.txt", "r"); // file I/O

	if (!sales_file)
	{
		printf("Error with File");
		exit(-1);
	}

	for(int i = 0; i < 12; i++)
	{
		fscanf(sales_file, "%f", &sales[i]);
	}
	fclose(sales_file);

	// Monthly sales report
	printf("Monthly sales report for 2022:\nMonth      Sales\n");
	for(int i = 0; i < 12; i++)
	{
		printf("%-10s $%.2f\n", months[i],sales[i]);
	}

	//Sales summary
	float sum = 0; // find avg sales
	float avg;

	for (int m = 0; m < 12; m++)
	{
		sum = sum + sales[m];
	}
	avg = sum / 12; // end avg

	float max = sales[0]; // find max

	for (int n = 1; n < 12; n++)
	{
		if (sales[n] > max){
			max = sales[n];
		}
	} 

	float min = sales[0]; //find min
	for (int k = 1; k < 12; k++)
	{
		if (sales[k] < min){
			min = sales[k];
		}
	} 

	int index_max = -1; // find index of max sales to print corresponding month
	for (int h = 0; h < 12; h++)
	{
		if (sales[h] == max){
			index_max = h;
			break;
		}
	}
	int index_min = -1; // find index of max sales to print corresponding month
	for (int h = 0; h < 12; h++)
	{
		if (sales[h] == min)
		{
			index_min = h;
			break;
		}
	}
	//prints
	printf("\nSales summary:\n");
	printf("Minimum Sales: $%.2f (%s)\n", min, months[index_min]);
	printf("Maximum Sales: $%.2f (%s)\n", max, months[index_max]);
	printf("Average sales: $%.2f\n", avg);


//Moving 6 month report
// month indexes: 0-5, 1-6, 2-7, 3-8, 4-9, 5-10, 6-11
	float sum1 = 0;
	for (int a = 0; a < 6; a++){ //find sum of jan to june
		sum1 = sum1 + sales[a];
	}
	float avg1 = sum1 / 6;

	printf("\nSix-Month Moving Average Report:\n");
	printf("%-10s - %10s $%.2f", months[0], months[5], avg1);

	float sum2 = 0;
	for (int b = 1; b < 7; b++)
	{ // feb to july
		sum2 = sum2 + sales[b];
	}
	float avg2 = sum2 / 6;

	printf("\n%-10s - %10s $%.2f", months[1], months[6], avg2);

	float sum3 = 0;
	for (int c = 2; c < 8; c++)
	{ //march to aug
		sum3 = sum3 + sales[c];
	}
	float avg3 = sum3 / 6;
	//prints
	printf("\n%-10s - %10s $%.2f", months[2], months[7], avg3);

	float sum4 = 0;
	for (int d = 3; d < 9; d++)
	{ //april to sept
		sum4 = sum4 + sales[d];
	}
	float avg4 = sum4 / 6;
	//prints
	printf("\n%-10s - %10s $%.2f", months[3], months[8], avg4);

	float sum5 = 0;
	for (int e = 4; e < 10; e++)
	{ //may to oct
		sum5 = sum5 + sales[e];
	}
	float avg5 = sum5 / 6;
	//prints
	printf("\n%-10s - %10s $%.2f", months[4], months[9], avg5);

	float sum6 = 0;
	for (int f = 5; f < 11; f++)
	{ //may to oct
		sum6 = sum6 + sales[f];
	}
	float avg6 = sum6 / 6;
	printf("\n%-10s - %10s $%.2f", months[5], months[10], avg6);

	float sum7 = 0;
	for (int g = 6; g < 12; g++)
	{ // may to oct
		sum7 = sum7 + sales[g];
	}
	float avg7 = sum7 / 6;
	//prints
	printf("\n%-10s - %10s $%.2f\n", months[6], months[11], avg7);
	
	
//sales report highest to lowest
printf("\nSales Report (Highest to Lowest)\nMonth      Sales\n");

float temp = 0;
 for (int i = 0; i < 12; i++) 
 {
        for (int j = i+1; j < 12; j++) 
        {
           if(sales[i] < sales[j]) 
           {
				const char* temp2 = months[i];
				months[i] = months[j];
				months[j] = temp2;

				temp = sales[i];
				sales[i] = sales[j];
				sales[j] = temp;


           }
        }
    }

    for (int i = 0; i < 12; i++) 
    {
        printf("%-10s $%0.2f\n ", months[i],sales[i]);
    }


return 0;


}
