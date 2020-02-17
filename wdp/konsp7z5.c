#include <stdio.h>
#include <stdlib.h>

void init_array(int **array, int size)
{
        *array =(int*) malloc(size * sizeof(int));
}

int *copy_array(int *from, int size)
{
    int *to;
    init_array(&to, size);

    for (int i = 0; i < size; i++)
        to[i] = from[i];

    return to;
}

int *resize(int *array, int prev_size, int new_size)
{
    int *new;

    init_array(&new, new_size);

    for (int i = 0; i < new_size; i++)
        new[i] = i < prev_size ? array[i] : 0;

    return new;
}

int main()
{
    int *array;
    int *new;
    int size = 3;

    init_array(&array, size);

    array[0] = 1;
    array[1] = 2;
    array[2] = 3;

    new = copy_array(array, size);

    printf("new[2] = %d\n", new[2]);

    new = resize(new, size, 10);

    printf("new[9] = %d\n", new[9]);

    free(array);

    return 0;

}
