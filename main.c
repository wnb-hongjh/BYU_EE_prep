#include <stdio.h>

int main()
{
    float temperature[5] = {23.5, 27.1, 19.8, 31.2, 25.0};
    float sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += temperature[i];
    }
    printf("avg: \n", sum / 5);
    return 0;
}