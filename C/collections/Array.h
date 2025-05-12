#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Array
{
    struct Array *next;
    int data;
} *root = NULL, *tail = NULL;

struct Array *ArrCreate(int arr[], int len)
{
    root = (struct Array *)malloc(sizeof(struct Array));
    root->data = arr[0];

    tail = root;
    for (int i = 1; i < len; i++)
    {
        struct Array *t = (struct Array *)malloc(sizeof(struct Array));
        t->data = arr[i];

        tail->next = t;
        tail = t;
    }

    return root;
}

struct Array *ArrCreateIn()
{
    int len = 0;
    printf("Enter the number of values you wish to insert: ");
    scanf("%d", &len);

    int val1 = 0;
    printf("Enter 1st value: ");
    scanf("%d", &val1);

    root = (struct Array *)malloc(sizeof(struct Array));
    root->data = val1;
    tail = root;

    int count = 1;
    while (count < len)
    {
        int value = 0;
        printf("Enter value no. %d: ", count + 1);
        scanf("%d", &value);

        struct Array *t = (struct Array *)malloc(sizeof(struct Array));
        t->data = value;

        tail->next = t;
        tail = t;

        count++;
    }

    return root;
}

void ArrDisplay(const struct Array *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void ArrPush(struct Array *p, int value)
{
    struct Array *t = (struct Array *)malloc(sizeof(struct Array));
    t->data = value;

    tail->next = t;
    tail = t;
}

int ArrPop(struct Array *p)
{
    struct Array *t = root;
    while (t->next->next != NULL)
        t = t->next;

    int x = tail->data;

    free(tail);

    tail = t;
    tail->next = NULL;

    return x;
}

int ArrMinVal(const struct Array *p)
{
    int min = INT_MAX;

    while (p)
    {
        if (p->data < min)
            min = p->data;

        p = p->next;
    }

    return min;
}

int ArrMaxVal(const struct Array *p)
{
    int max = INT_MIN;

    while (p)
    {
        if (p->data > max)
            max = p->data;

        p = p->next;
    }

    return max;
}

int ArrCountValOccurrence(const struct Array *p, int val)
{
    int count = 0;

    while (p)
    {
        if (p->data == val)
            count++;
        p = p->next;
    }

    return count;
}

int ArrSum(const struct Array *p)
{
    int sum = 0;

    while (p)
    {
        sum += p->data;
        p = p->next;
    }

    printf("sum: %d\n", sum);
    return sum;
}

struct Array *ArrReverse(const struct Array *p)
{
    struct Array *tail = (struct Array *)malloc(sizeof(struct Array));
    tail->data = p->data;
    tail->next = NULL;
    p = p->next;

    while (p)
    {
        struct Array *t = (struct Array *)malloc(sizeof(struct Array));
        t->data = p->data;
        t->next = tail;
        tail = t;

        p = p->next;
    }

    return tail;
}

int ArrAverage(const struct Array *p)
{
    int sum = 0;
    int count = 0;

    while (p)
    {
        sum += p->data;
        count++;
        p = p->next;
    }

    return sum / count;
}

int ArrFindPeak(const struct Array *p)
{
    int prev_val = p->data;
    p = p->next;

    if (prev_val >= p->data)
        return prev_val;

    while (p->next != NULL)
    {
        if (p->data >= prev_val && p->data >= p->next->data)
            return p->data;

        prev_val = p->data;
        p = p->next;
    }

    if (p->data >= prev_val)
        return p->data;

    return 0;
}
