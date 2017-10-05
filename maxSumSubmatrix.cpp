#include <stdio.h>
#include <string.h>
#include <limits.h>
#define ROW 401
#define COL 401

int N;
int a[ROW][COL];
int kadane(int* arr, int* start, int* finish, int n)
{
    int sum = 0, maxSum = INT_MIN, i;

    *finish = -1;

    int local_start = 0;

    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i+1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }

     // There is at-least one non-negative number
    if (*finish != -1)
        return maxSum;

    // Special Case: When all numbers in arr[] are negative
    maxSum = arr[0];
    *start = *finish = 0;

    // Find the maximum element in array
    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}
// The main function that finds maximum sum rectangle in M[][]
void findMaxSum(int M[][COL])
{
    // Variables to store the final output
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;

    int left, right, i;
    int temp[ROW], sum, start, finish;

    // Set the left column
    for (left = 0; left < N; ++left)
    {
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));

        // Set the right column for the left column set by outer loop
        for (right = left; right < N; ++right)
        {
            for (i = 0; i < N; ++i)
                temp[i] += M[i][right];

            sum = kadane(temp, &start, &finish, N);

            if (sum > maxSum)
            {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }
    printf("%d\n", maxSum);
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i<N; i++)
    {
        for(int j =0 ; j<N;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }


    findMaxSum(a);

    return 0;
}
