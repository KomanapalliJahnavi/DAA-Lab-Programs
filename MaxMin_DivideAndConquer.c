#include<stdio.h>

void MaxMin(int a[],int low, int high, int *max,int *min){
	int mid;
	int max1, max2,min1,min2;
	if(low==high){
		*max=a[low];
		*min=a[low];
	}
	else if(high == low+1){
		if(a[low]>a[high]){
			*max=a[low];
			*min=a[high];
		}
		else{
			*max=a[high];
			*min=a[low];
		}
	}
	else{
		mid=(low+high)/2;
		MaxMin(a,low,mid,&max1,&min1);
		MaxMin(a,mid+1,high,&max2,&min2);
		
		if(max1>max2)
			*max=max1;
		else
			*max=max2;
			
		if(min1<min2)
			*min=min1;
		else
			*min=min2;
	}
}

int main(){
	int n,i,max,min;
	printf("Enter Number of Elements:");
	scanf("%d",&n);
	int a[100];
	printf("Enter Array Elements:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	MaxMin(a,0,n-1,&max,&min);
	printf("Maximum Number In The Array Is %d",max);
	printf("\nMinimum Number In The Array Is %d",min);
	return 0;	
}
