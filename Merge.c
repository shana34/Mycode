#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
void merge(int* src,int *dst,int begin,int mid,int end)
{
	int begin1=begin;
	int begin2=mid;
	int index=begin;
	while(begin1<mid && begin2<end){
		if(src[begin1]<src[begin2]){
			dst[index++]=src[begin1++];
		}else{
			dst[index++]=src[begin2++];
		}
	}
	while(begin1<mid){
		dst[index++]=src[begin1++];
	}
	while(begin2<end){
		dst[index++]=src[begin2++];
	}
	memcpy(src+begin,dst+begin,(end-begin)*sizeof(int));
}
void _merge_sort(int *arr,int* tmp,int left,int right)
{
	if(left+1>=right){
		return;
	}
	int mid=left+(right-left)/2;
	_merge_sort(arr,tmp,left,mid);
	_merge_sort(arr,tmp,mid,right);
	merge(arr,tmp,left,mid,right);
}
void merge_sort(int* arr,int size)
{
	int* tmp=(int*)malloc(size*sizeof(int));
	_merge_sort(arr,tmp,0,size);
	free(tmp);
}
int main()
{
	int arr[400000]={0};
	time_t t;
    int n = 400000; int i = 0;
    /* 初始化随机数发生器 */
    srand((unsigned)time(&t));
    /* 输出 0 到 49 之间的 5 个随机数 */
    for(i = 0 ; i < n ; i++){
       arr[i] = rand() % 400000;
    }
	int len=sizeof(arr)/sizeof(arr[0]);
	clock_t start, finish;
	double Total_time;

	start = clock();
	merge_sort(arr,len);
	finish = clock();
	Total_time = (double)((finish - start));
	i=0;/*
	for(i=0;i<len;i++){
		printf("%d ",arr[i]);
	}*/
	printf("\n");
	printf("Total  Time : %0.5f(ms)\n", Total_time);
	return 0;
}