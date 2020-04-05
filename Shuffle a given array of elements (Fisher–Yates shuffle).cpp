#include <stdio.h>
#include <time.h>
#include <random>
void swap(int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

template  <size_t n>
void shuffle(int (&A)[n])
{
    for (int i = n-1; i >= 1; i--) {
        int j = rand() % i+1;
        printf("%d ",j);
        swap(A,i,j);
    }
}

// main function
int main(void)
{
    int A[] = { 1, 2, 3, 4, 5, 6 };
    srand(time(NULL));
    shuffle(A);
    printf("\n");
    for (int i = 0; i < (*(&A+1) - A); i++)     printf("%d ", A[i]);
    return 0;
}