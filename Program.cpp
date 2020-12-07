#include <iostream>
using namespace std;
#include <stdlib.h>
#include <math.h>
#include <time.h>

void show(int[]);
void Bsort(int[]);
void Qsort (int[], int ,int );
int Bsearch(int[], int, int, int ); 
int size;

int main(){
	cout<<"請輸入資料數量： ";
	cin>>size;

	
	int data[size];
	
	cout<<"請選擇 (1)手動輸入 或 (2)電腦輸入 : ";
	int c;
	
	do{
		cout<<"\n輸入錯誤，請從新輸入 : ";
		cin>>c;
	}while ( c!=1 && c!=2 );
	
	cout<<"請輸入資料"<<endl;
	if(c==1){// 手動輸入 
		for(int i=0; i<size; i++)
			cin>>data[i];
	}
	else{//	由電腦輸入
		srand(time(NULL));
		for(int i=0; i<size; i++)
			data[i]=rand()%1000;
	}
	
	
	clock_t start_B, end_B, start_Q,end_Q;
	
//排序 

	//泡沫排序法
//	start_B=time(NULL);

	Bsort(data);
	
//	end_B=time(NULL);
//	cout<<"泡沫排序法費時： "<<difftime(end_B, start_B)<<endl;

	//快速排序法
//	start_Q=time(NULL);

//	Qsort(data, 0, size-1);

//	end_Q=time(NULL);
//	cout<<"快速排序法費時： "<<difftime(end_Q, start_Q)<<endl;

	show(data);//印出陣列
	
	int index;
	cout<<"請輸入您要查詢的數字: ";
	cin>>index;
	
	//二元搜尋法
	int num=Bsearch(data, index, 0, size-1);
//	cout<<num<<endl;
	
	if( num==-1)
		cout<<index<<"不在陣列中"<<endl;
	else 
		cout<<index<<"在陣列中 ["<<num<<"] 的位置"<<endl;
	
}

int Bsearch(int arr[], int index, int min, int max){//二元搜尋法
	int mid;
	while( min <= max ) {
		mid = (min+max) / 2;
//		cout<<"Hello\n";
		if( arr[mid] == index)
			return mid;
		else if( arr[mid] < index )
			min=mid+1;
		else if( arr[mid] > index )
			max=mid-1;
//		cout<<min<<" "<<mid<<" "<<max<<endl;
	}
	
	return -1;	
}

void show(int arr[]){	//印出陣列
	for(int i=0; i<size; i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

void Bsort (int arr[]){		//泡沫排序法

	int t;
	for(int i=0; i<size; i++)
		for(int j=0; j< size-i; j++ )
			if( arr[j] > arr[j+1] ){
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
	
}

void Qsort ( int arr[], int start,int end){		//快速排序法
	if(start<end){
		int i=start,j=end+1;
		do{
			do{
				i++;
			}while(arr[start]>arr[i]);
			do{
				j--;
			}while(arr[start]<arr[j]);
			if(i<j){
				int t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;
//				//cout<<i<<" "<<j<<" "<<arr[i]<<" "<<arr[j]<<endl;
			}
		}while(i<j);
		int t=arr[start];
		arr[start]=arr[j];
		arr[j]=t;
		Qsort(arr, start, j-1);
		Qsort(arr, j+1, end);
//		show();//
	}
}
