#include<stdio.h>
#include<stdlib.h>
#define N 10
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
void bubble_sort0(int *a) {

	for(int i=0; i<N; i++) {
		for(int j=i;j>0;j--){
		   if(a[j]<a[j-1]){
		   	swap(&a[j-1],&a[j]);
		   }
		}
	}
}
void bubble_sort(int *a) {
	int n=N;
	for(bool sorted=false;sorted=!sorted;n--)
	for(int i=0;i<n-1;i++){
		if(a[i]<a[i+1]){
		  swap(&a[i],&a[i+1]);
		  sorted=false;
		}
	}
}

int main() {
	int a[N];
	for(int i=0; i<N; i++) {
		a[i]=rand()%107+1;
		printf("%d\t",a[i]);

	}
	printf("\n");
	bubble_sort(a);
	for(int i=0; i<N; i++)
		printf("%d\t",a[i]);
	return 0;
}
