#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void createLL(int *a, int n)
{
    struct node *t, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = NULL;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t; //Important
    }
}

void displayLL(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void recdisplayLL(struct node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        recdisplayLL(p->next);
    }
    // printf("\n");
}

void reverse_LL(struct node *p)
{
    if (p != NULL)
    {
        reverse_LL(p->next);
        printf("%d ", p->data);
    }
    // printf("\n");
}

int main(int argc, char const *argv[])
{
    int n, *a;
    printf("Enter Array Size\n");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter Array Elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    createLL(a, n);
    // printf("Displaying the data using LL\n");
    // displayLL(head);
    // printf("Recursively Displaying the data using LL\n");
    // recdisplayLL(head);
    printf("Recursively Reverse Displaying the data using LL\n");
    reverse_LL(head);

    return 0;
}
