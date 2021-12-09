#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void append(struct Array *arr)
{
    int n;
    printf("Enter the element you want to append\n");
    scanf("%d", &n);
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = n;
    }
}

void insert(struct Array *arr)
{
    int index, ele;
    printf("Enter the index where you want to insert an element\n");
    scanf("%d", &index);
    printf("Enter the element\n");
    scanf("%d", &ele);
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = ele;
        arr->length++;
    }
}

void pop(struct Array *arr)
{
    arr->A[arr->length--];
}

void delete (struct Array *arr)
{
    int index;
    printf("Enter the index you want to delete the element\n");
    scanf("%d", &index);
    if (index < 0 || index > arr->length)
    {
        printf("You've given an invalid index\n");
    }
    else
    {
        for (int i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->A[arr->length--];
    }
}

void l_search(struct Array *arr)
{
    int ele;
    printf("Enter the element you want a Linear Search\n");
    scanf("%d", &ele);
    int flag = 0, temp;
    for (size_t i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == ele)
        {
            flag++;
            temp = arr->A[0];
            arr->A[0] = arr->A[i];
            arr->A[i] = temp;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Element is found\n");
    }
    else
    {
        printf("Element is not found\n");
    }
}

int b_search(struct Array arr)
{
    int ele;
    printf("Enter the element you want a Binary Search\n");
    scanf("%d", &ele);
    int first = 0, last = arr.length - 1;
    while (first <= last)
    {
        int mid = (first + last) / 2;
        if (arr.A[mid] == ele)
        {
            return 1;
        }
        else if (arr.A[mid] < ele)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    return -1;
}

void get(struct Array arr)
{
    int in;
    printf("Enter an index you want to know about the element\n");
    scanf("%d", &in);
    if (in >= 0 && in <= arr.length)
    {
        printf("Element is %d\n", arr.A[in - 1]);
    }
    else
    {
        printf("There is not element present in this index\n");
    }
}

void set(struct Array *arr)
{
    int in, val;
    printf("Enter an index you want to change the element\n");
    scanf("%d", &in);
    printf("Enter the new value\n");
    scanf("%d", &val);
    int x = arr->A[in - 1];
    if (in >= 0 && in <= arr->length)
    {
        arr->A[in - 1] = val;
        printf("Deleted value is %d\n", x);
    }
    else
    {
        printf("There is not element present in this index\n");
    }
}

void max_ele(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (max < arr.A[i])
        {
            max = arr.A[i];
        }
    }
    printf("Max element is %d\n", max);
}

void min_ele(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (min > arr.A[i])
        {
            min = arr.A[i];
        }
    }
    printf("Min element is %d\n", min);
}

void sum(struct Array arr)
{
    int accumulate = 0;
    for (int i = 0; i < arr.length; i++)
    {
        accumulate = accumulate + arr.A[i];
    }
    printf("Sum is %d\n", accumulate);
}

void average(struct Array arr)
{
    int accumulate = 0;
    for (int i = 0; i < arr.length; i++)
    {
        accumulate = accumulate + arr.A[i];
    }
    printf("Average is %0.2f\n", ((float)accumulate / arr.length));
}

void reverse(struct Array *arr)
{
    int *b;
    b = (int *)malloc((arr->length) * sizeof(int));
    for (int i = 0; i < arr->length; i++)
    {
        b[i] = arr->A[(arr->length) - 1 - i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = b[i];
    }
}

void rrev(struct Array *arr)
{
    int temp;
    for (int i = 0, j = (arr->length - 1); i < j; i++, j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void insert_sort(struct Array *arr)
{
    int ele;
    printf("Enter the element you want to insert in a Sorted Array\n");
    scanf("%d", &ele);
    //In increasing order
    int flag = 0;
    for (int i = 0; i < arr->length; i++)
    {
        if (ele > arr->A[i])
        {
            flag++;
        }
    }
    for (int i = (arr->length - 1); i >= flag; i--)
    {
        arr->A[i + 1] = arr->A[i];
    }
    arr->A[flag] = ele;
    arr->length++;

    //In decreasing order
    //     int flag = 0;
    //     for (int i = 0; i < arr->length; i++)
    //     {
    //         if (ele < arr->A[i])
    //         {
    //             flag++;
    //         }
    //     }
    //     for (int i = (arr->length - 1); i >= flag; i--)
    //     {
    //         arr->A[i + 1] = arr->A[i];
    //     }
    //     arr->A[flag] = ele;
    //     arr->length++;
}

void check_sort(struct Array arr)
{
    int inc = 1, dec = 1;
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] < arr.A[i + 1])
        {
            inc++;
            // break;
        }
        else if (arr.A[i] > arr.A[i + 1])
        {
            dec++;
        }
    }
    if (inc == arr.length)
    {
        printf("All elements are sorted in increasing order\n");
    }
    else if (dec == arr.length)
    {
        printf("All elements are sorted in decreasing order\n");
    }
    else
    {
        printf("All elements are in random order\n");
    }
}

void swap(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}

void sort(struct Array *arr) //wrong
{
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

void merge(struct Array arr)
{
    int len, *b, *c;
    int s = arr.length;
    printf("Enter the 2nd array length\n");
    scanf("%d", &len);
    b = (int *)malloc(len * sizeof(int));
    c = (int *)malloc((len + s) * sizeof(int));
    printf("Enter 2nd array elements\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &b[i]);
    }
    int i = 0, j = 0, k = 0;
    while ((i < s) && (j < len))
    {
        if (arr.A[i] < b[j])
        {
            c[k++] = arr.A[i++];
            // i++;
            // k++;
        }
        else if (arr.A[i] > b[j])
        {
            c[k++] = b[j++];
            // j++;
            // k++;
        }
    }
    // if (j == len)
    // {
    for (; i < arr.length; i++)
    {
        c[k++] = arr.A[i];
    }
    // }
    // else if (i == arr.length)
    // {
    for (; j < len; j++)
    {
        c[k++] = arr.A[j];
    }
    // }
    // int nn = sizeof(c) / sizeof(c[0]);
    printf("After Merging two array\n");
    for (int i = 0; i < (len + s); i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
}

void Display(struct Array arr)
{
    printf("Array elements are\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

int main()
{
    struct Array arr;
    int choice, sea, x;

    //Basics
    printf("Enter the size\n");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    printf("Enter how many elements you want\n");
    scanf("%d", &arr.length);
    printf("Enter Array elements\n");
    for (int i = 0; i < arr.length; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    while (1)
    {
        //MENU
        printf("--------------ARRAY ADT--------------\n");
        printf("1. Append\n");
        printf("2. Insert\n");
        printf("3. Pop\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Search\n");
        printf("7. Get\n");
        printf("8. Set\n");
        printf("9. Max\n");
        printf("10. Min\n");
        printf("11. Sum\n");
        printf("12. Average\n");
        printf("13. Reverse\n");
        printf("14. Insert in Sorted Array\n");
        printf("15. Check Sort\n");
        printf("16. Sort\n");
        printf("17. Merge\n");
        printf("18. Exit\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: //Append Element in an Array
            append(&arr);
            break;

        case 2: //Insert an Element in an Array
            insert(&arr);
            break;

        case 3: //Popping Element in an Array
            pop(&arr);
            // printf("After Pop Operation\n");
            break;

        case 4: //Deleting Element in an Array
            delete (&arr);
            break;

        case 5: //Display
            Display(arr);
            break;

        case 6: //Search
            printf("1. Linear Search\n");
            printf("2. Binary Search\n");
            printf("Enter which search you want\n");
            scanf("%d",&sea);
            switch (sea)
            {
            case 1: //Linear Search on Array
                l_search(&arr);
                break;

            case 2: //Binary Search on Array
                x = b_search(arr);
                if (x == 1)
                {
                    printf("Element is found\n");
                }
                else
                {
                    printf("Element is not found\n");
                }
                // break;
            }
            break;

        case 7: //Get the element at a position
            get(arr);
            break;

        case 8: //Set the element at a position
            set(&arr);
            break;

        case 9: //Max element in Array
            max_ele(arr);
            break;

        case 10: //Min element in Array
            min_ele(arr);
            break;

        case 11: //Sum of all element in Array
            sum(arr);
            break;

        case 12: //Average of all element in Array
            average(arr);
            break;

        case 13: //Reverse Array
            reverse(&arr);
            rrev(&arr);
            printf("After Reversing the array\n");
            Display(arr);
            break;

        case 14: //Insert an element in a sorted Array
            insert_sort(&arr);
            break;

        case 15: //Checking an Array if all elements are sorted or not
            check_sort(arr);
            break;

        case 16: //Sorting Array elements
            sort(&arr);
            break;

        case 17: //Merging two arrays
            merge(arr);
            break;

        case 18:
            free(arr.A);
            exit(1);
            // break;

        default:
            printf("You've entered a wrong input\n");
            break;
        }
    }

    // Display(arr);

    return 0;
}