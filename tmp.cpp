#include<bits/stdc++.h> 
int arr1[1010000],arr2[10100],Next[10100]={0};
void KMP(int num);
int main()
{
	int k,n,m,t,cnt=0,i,j;
	scanf("%d",&t);
	while(t--){
		// scanf("%d %d",&n,&m);
		// for(i=0;i<n;++i){
		// 	scanf("%d",&arr1[i]);
		// }for(i=0;i<m;++i){
		// 	scanf("%d",&arr2[i]);
		// 	Next[i]=0;
		// }
    
		getNext(m);
		k=0;
		for(i=0;i<n;++i){
			while(k&&arr2[k]!=arr1[i]){
				k=Next[k-1];
			}if(arr1[i]==arr2[k]){
				++k;
			}
			if(k==m){
				break;
			}
		}
		printf("%d\n",k==m?i-k+2:-1);
	}
	return 0;
}
void getNext(int num)
{
	int i,k=0;
	for(i=1;i<num;++i){
		while(k>0&&arr2[k]!=arr2[i]){
			k=Next[k-1];
		}if(arr2[i]==arr2[k]){
			++k;
		}
		Next[i]=k;
	}
	return;
}
