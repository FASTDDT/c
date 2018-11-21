#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void merge(int *a,int head,int mid,int tail,int *tmp) {
	int i=head,j=mid+1,k=head;
	while(i!=mid+1&&j!=tail+1) {
		if(a[i]<=a[j]) {
			tmp[k]=a[i];
			i++;
		} else {
			tmp[k]=a[j];
			j++;
		}
		k++;
	}
	while(i!=mid+1) {
		tmp[k++]=a[i++];
	}
	while(j!=tail+1) {
		tmp[k++]=a[j++];
	}
	for(int s=head; s<=tail; s++) {
		a[s]=tmp[s];
	}
}
void merge_sort(int *a,int head,int tail,int *tmp) {
	if(head>=tail) {
		return ;
	}
	int mid=(head+tail)/2;
	merge_sort(a,head,mid,tmp);
	merge_sort(a,mid+1,tail,tmp);
	merge(a,head,mid,tail,tmp);
}
main() {
	int a[10]={0},b[10]={0};
	int i=0;
	while(i++<10)
		a[i]=rand()%109+1;
	i=0;
	while(i++<10)
		printf("%d\t",a[i]);
	printf("\n");
	merge_sort(a,0,10,b);
	i=0;
	printf("=========================\n");
	while(i++<10)
		printf("%d\t",a[i]);
	return 0;
}
