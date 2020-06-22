#include<bits\stdc++.h>
#include <fstream>
using namespace std ;
typedef struct Lich
{
	int TH;
	int TT;
};



void nhaptufile(char filename[], Lich a[],int &n )
	{
		// mo file 
		//File *fi;
	ifstream fi(filename);  
		if(fi==NULL)
		{
			cout<<"Ko m? dc file";
			return ;
		}		
	//	cout<<" so cong viec n = ";
	fi>>n;
		for (int i = 0; i<n ; i++){
		
	//	cout<<"Nhap thoi gian cong viec thu "<< i ;
		fi>>a[i].TH;}
	//	cout<<"Nhap tien thuong cong viec thu "<< i ;
		for (int i = 0; i<n ; i++){
		
		fi>>a[i].TT;
		
	}
	fi.close();
};
void HienThi(Lich a){
	cout <<a.TH<<"," <<a.TT<<endl;
		
}
void swap(Lich &a,Lich &b)
{
	Lich t= a;
	a= b ;
	b = t;
}; 
void SXTangDanTheoThoiHan(Lich a[],int n)
{
for (int i = 0 ; i<n-1;i++){
for(int j = i +1; j<n;j++){
	if(a[i].TH>a[j].TH) swap(a[i],a[j]);
}	
}
}
void SXGiamDanTheoTienThuong(Lich a[] ,int n)
{
for (int i = 0 ; i<n-1;i++){
for(int j = i +1; j<n;j++){
	if(a[i].TT<a[j].TT) swap(a[i],a[j]);
	
}}
};

void SXGiamDanTheoTiLe(Lich a[],int n)
{
for (int i = 0 ; i<n-1;i++){
for(int j = i +1; j<n;j++){
	if((float)a[i].TT/a[i].TH<(float)a[j].TT/a[j].TH) swap(a[i],a[j]);
}
}}
int  greendy(Lich a[], int n , int TH ,int &Tong)
{
//	if(TH<=0) break ;	
 //SXTangDanTheoThoiHan(a, n);
 SXGiamDanTheoTiLe(a, n);
 for (int i = 0;i<n;i++)
 {
 	if(TH>=a[i].TH){
	 
 	TH=TH-a[i].TH;
 	Tong += a[i].TT;
	 }
 }
 return Tong;
}
int main(){	
Lich a[10];
int n;
int TH=20;
int Tong=0 ;	
nhaptufile("test.cpp",a,n);
 Tong = greendy( a,  n , TH,Tong);// thoi han la 15 h 
 // tham lam theo thoi han it nhat    
 //SXTangDanTheoThoiHan(a, n);
for(int i=0;i<n ;i++)
HienThi(a[i]);
cout<<"Gia tri nhan duoc khi tham lam theo ti le voi thoi han  "<<TH<<" la : " <<Tong;

}
