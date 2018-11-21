#include<stdio.h>
#include<stdlib.h>
void create_rand(int *a,int n) {
	for(int i=0; i<n; i++) {
		a[i]=rand()%100+1;
	}
}
void swap(int &a,int &b) {
	int tmp=a;
	a=b;
	b=tmp;

}

//void quick_sort(int *a, int left, int right) {
//	if(left >= right) { /*�������������ڻ��ߵ����ұߵ������ʹ����Ѿ��������һ������*/
//		return ;
//	}
//	int i = left;
//	int j = right;
//	int key = a[left];
//
//	while(i < j) {                             /*�����ڵ�����Ѱ��һ��*/
//		while(i < j && key <= a[j])
//			/*��Ѱ�ҽ������������ǣ�1���ҵ�һ��С�ڻ��ߴ���key���������ڻ�С��ȡ����������
//			���ǽ���2��û�з�������1�ģ�����i��j�Ĵ�Сû�з�ת*/
//		{
//			j--;/*��ǰѰ��*/
//		}
//
//		a[i] = a[j];
//		/*�ҵ�һ������������Ͱ�������ǰ��ı����ߵ�i��ֵ�������һ��ѭ����key��
//		a[left]����ô���Ǹ�key��*/
//
//		while(i < j && key >= a[i])
//			/*����i�ڵ�������ǰѰ�ң�ͬ�ϣ�����ע����key�Ĵ�С��ϵֹͣѭ���������෴��
//			��Ϊ����˼���ǰ����������ӣ������������ߵ�����С��key�Ĺ�ϵ�෴*/
//		{
//			i++;
//		}
//
//		a[j] = a[i];
//	}
//
//	a[i] = key;/*���ڵ���������һ���Ժ�Ͱ��м���key�ع�*/
//	quick_sort(a, left, i - 1);/*�����ͬ���ķ�ʽ�Էֳ�������ߵ�С�����ͬ�ϵ�����*/
//	quick_sort(a, i + 1, right);/*��ͬ���ķ�ʽ�Էֳ������ұߵ�С�����ͬ�ϵ�����*/
//	/*��Ȼ�����ܻ���ֺܶ�����ң�ֱ��ÿһ���i = j Ϊֹ*/
//}
void quick_sort(int *a,int left,int right){
	if(left>=right){
		return;
	}
	int flag=a[left];
	int i=left;
	int j=right;
	while(i<j){
		while(i<j&&flag<=a[j]){
			j--;
		}
		a[i]=a[j];
		while(i<j&&flag>=a[i]){
			i++;
		}
		a[j]=a[i];
	}
	a[i]=flag;
	quick_sort(a,left,i-1);
	quick_sort(a,i+1,right);
}

main() {
	int a[10];
	int n=sizeof(a)/sizeof(int);
	create_rand(a,n);
	for(int i=0; i<n; i++) {
		printf("%d\t",a[i]);
	}
	printf("\n");
	quick_sort(a,0,n);
	for(int i=0; i<n; i++) {
		printf("%d\t",a[i]);
	}
	return 0;
}
