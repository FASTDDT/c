#include<stdio.h>
#include<stdlib.h>
#define N 10
void select_sort(int *a,int first) {
	if(first>=N-1)
		return;
	int tmp=first;
	for(int i=first; i<N; i++) {
		if(a[tmp]<a[i]) {
			tmp=i;
		}
	}
	int x=a[tmp];
	a[tmp]=a[first];
	a[first]=x;
	select_sort(a,first+1);
}
int main() {
	int a[N];
	for(int i=0; i<N; i++) {
		a[i]=rand()%107+1;
		printf("%d\t",a[i]);

	}
	printf("\n");
	select_sort(a,0);
	for(int i=0; i<N; i++)
		printf("%d\t",a[i]);
	return 0;
}
