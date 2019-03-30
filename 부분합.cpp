#include<stdio.h>
int list[100000];
int sorted[100000];

void merge(int list[], int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;

  /* 분할 정렬된 list의 합병 */
  while(i<=mid && j<=right){
    if(list[i]<=list[j]){	
      sorted[k++] = list[i++];
      
    }else{
      sorted[k++] = list[j++];
     
  	}
  }

  // 남아 있는 값들을 일괄 복사
  if(i>mid){
    for(l=j; l<=right; l++){
      sorted[k++] = list[l];
   	}
  }
  // 남아 있는 값들을 일괄 복사
  else{
    for(l=i; l<=mid; l++){
      sorted[k++] = list[l];
    }
  }

  // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
  for(l=left; l<=right; l++){
    list[l] = sorted[l];
  }
}

// 합병 정렬
void merge_sort(int list[], int left, int right){
  int mid;

  if(left<right){
    mid = (left+right)/2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
    merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
    merge_sort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
    merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
  }
}

int main()
{
	int N,S,total=0,c=0;
	scanf("%d %d",&N,&S);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&list[i]);
	}
	merge_sort(list,0,N-1);//정렬
	//더하기,비교 
	for(int i=0;i<N;i++)
	{
		printf("%d ",list[i]);
	}
	printf("\n");
	for(int i=N-1;i>=0;i--)
	{
		if(S>total){
			total=total+list[i];
			c++;
			printf("%d %d %d\n",total,list[i],c);
		}else if(S<=total)
		{
			printf("%d",c);
			break;
		}
	}
	if(S>total)
	{
		printf("0");
	}
}
