#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int **arr;
    int rows;
    int columns;
};

struct Matrix *MatrixCreateIn(int rows, int columns)
{
    struct Matrix *p = (struct Matrix *)malloc(sizeof(struct Matrix));
    // (IMP) assigning memory for pointers equivalent to the number of rows
    p->arr = malloc(sizeof(int *) * rows); // cast (int *) won't work, thus default void ptr
    p->rows = rows;
    p->columns = columns;

    printf("**** Enter values *****\n");
    for (int i = 0; i < rows; i++)
    {
        int *temp = (int *)malloc(sizeof(int) * columns);

        for (int j = 0; j < columns; j++)
        {
            int val = 0;
            printf("Position [%d][%d]: ", i, j);
            scanf("%d", &val);

            temp[j] = val;
        }

        p->arr[i] = temp;
    }

    return p;
}

void MatrixDisplay(const struct Matrix *p)
{
    for (int i = 0; i < p->rows; i++)
    {
        for (int j = 0; j < p->columns; j++)
        {
            printf("%d ", p->arr[i][j]);
        }
        printf("\n");
    }
}

int MatrixPeak(const struct Matrix *p)
{
    int current_col = 0;
    int current_row = 0;

    int is_running = 1;

    while (is_running)
    {
        int col_max = 0;

        for (int i = 0; i < p->rows; i++)
        {
            int col_val = p->arr[i][current_col];
            if (col_max <= col_val)
            {
                col_max = col_val;
                current_row = i;
            }
        }

        if (current_col == 0 && col_max > p->arr[current_row][current_col + 1])
        {
            int val = p->arr[current_row][current_col + 1];
            return col_max;
            is_running = 0;
        }
        else if (current_col == p->columns - 1 && col_max > p->arr[current_row][current_col - 1])
        {
            return col_max;
            is_running = 0;
        }
        else if (col_max > p->arr[current_row][current_col + 1] && col_max > p->arr[current_row][current_col - 1])
        {
            return col_max;
            is_running = 0;
        }

        current_col++;
    }
}