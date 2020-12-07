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
	cout<<"�п�J��Ƽƶq�G ";
	cin>>size;

	
	int data[size];
	
	cout<<"�п�� (1)��ʿ�J �� (2)�q����J : ";
	int c;
	
	do{
		cout<<"\n��J���~�A�бq�s��J : ";
		cin>>c;
	}while ( c!=1 && c!=2 );
	
	cout<<"�п�J���"<<endl;
	if(c==1){// ��ʿ�J 
		for(int i=0; i<size; i++)
			cin>>data[i];
	}
	else{//	�ѹq����J
		srand(time(NULL));
		for(int i=0; i<size; i++)
			data[i]=rand()%1000;
	}
	
	
	clock_t start_B, end_B, start_Q,end_Q;
	
//�Ƨ� 

	//�w�j�ƧǪk
//	start_B=time(NULL);

	Bsort(data);
	
//	end_B=time(NULL);
//	cout<<"�w�j�ƧǪk�O�ɡG "<<difftime(end_B, start_B)<<endl;

	//�ֳt�ƧǪk
//	start_Q=time(NULL);

//	Qsort(data, 0, size-1);

//	end_Q=time(NULL);
//	cout<<"�ֳt�ƧǪk�O�ɡG "<<difftime(end_Q, start_Q)<<endl;

	show(data);//�L�X�}�C
	
	int index;
	cout<<"�п�J�z�n�d�ߪ��Ʀr: ";
	cin>>index;
	
	//�G���j�M�k
	int num=Bsearch(data, index, 0, size-1);
//	cout<<num<<endl;
	
	if( num==-1)
		cout<<index<<"���b�}�C��"<<endl;
	else 
		cout<<index<<"�b�}�C�� ["<<num<<"] ����m"<<endl;
	
}

int Bsearch(int arr[], int index, int min, int max){//�G���j�M�k
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

void show(int arr[]){	//�L�X�}�C
	for(int i=0; i<size; i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

void Bsort (int arr[]){		//�w�j�ƧǪk

	int t;
	for(int i=0; i<size; i++)
		for(int j=0; j< size-i; j++ )
			if( arr[j] > arr[j+1] ){
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
	
}

void Qsort ( int arr[], int start,int end){		//�ֳt�ƧǪk
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
