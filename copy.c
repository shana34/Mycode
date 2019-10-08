#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *rand_init_arr(int *arr, int n){
    int m = n;
    time_t t;
    t = (unsigned)time(&t);
    srand(t);
    while(n){
        arr[m-(n--)] = rand()%10000;
    }
}

void quicksort(int arr[], int left, int right){
    //boarder
    if(left >= right) return;
    int key = arr[left];
    int begin = left; int end = right;
    while(begin != end){
        while(end > begin && arr[end] > key){
            end--;
        }
        if (end > begin) arr[begin] = arr[end];
        while(begin < end && arr[begin] < key){
            begin++;
        }
        if (begin < end) arr[end] = arr[begin];
    }arr[begin] = key;
    quicksort(arr, left, end-1);
    quicksort(arr, end+1, right);
}
int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    int m = atoi(argv[1]);
    int *arr = NULL;
    arr = (int*)malloc(n*sizeof(int));
    rand_init_arr(arr, n);
    int left = 0; int right = n - 1;
    quicksort(arr, left, right);
    while(n){
        printf("%d ",arr[m-(n--)]);
    }return 0;
}
