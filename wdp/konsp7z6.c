#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double get_distance(double *a, double *b)
{
    return sqrt(pow(b[0]-a[0], 2) + pow(b[1] - a[1], 2));
}

int main()
{
    int size, point1, point2;
    printf("Enter number of points to generate:\n");
    scanf("%d", &size);
    double (*array)[2] = malloc(size * sizeof(double[2]));
    srand(0);

    for (int i = 0; i < size; i++)
    {
        array[i][0] = (double)rand()/RAND_MAX*2.0-1.0;
        array[i][1] = (double)rand()/RAND_MAX*2.0-1.0;
    }

    printf("Enter point one (number between 0 and %d):\n", size -1);
    scanf("%d", &point1);
    printf("Enter point two (number between 0 and %d):\n", size -1);
    scanf("%d", &point2);

    double distance = get_distance(array[point1], array[point2]);
    printf("Point A = (%.2f, %.2f)\n", array[point1][0], array[point1][1]);
    printf("Point B = (%.2f, %.2f)\n", array[point2][0], array[point2][1]);
    printf("Distance between A and B: %lf\n", distance);

    free(array);

    return 0;
}
