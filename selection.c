#include <stdio.h>

int main(void)
{
    int numbers[] = {8,2,9,3,4,6,0,7,5,1};
    int size_num = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size_num - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size_num; j++)
        {
            if(numbers[j] < numbers[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = numbers[i];
        numbers[i] = numbers[min_idx];
        numbers[min_idx] = temp;
    }

    printf("The last number is %i\n", numbers[size_num-1]);
    printf("The 7th number is %i\n", numbers[size_num-4]);
    printf("The first number is %i\n", numbers[0]);
}