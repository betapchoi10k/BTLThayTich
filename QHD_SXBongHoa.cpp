#include<bits\stdc++.h>
using namespace std;
class SXHoa
{
	int  m , n , a[100][100] , b[100][100];
	 
	 public :void nhap(){
		
		cout <<"Nhap so bong hoa "<<"\nM=";cin>>m;
		cout <<"Nhap so binh hoa "<<"\nN=";cin>>n;
		for(int i=0;i<=n;i++)
		for(int j= 0 ; j<=n;j++)
		{
			a[i][j]=0;
			b[i][j]=0;
		}
		//nhap gia tri tham mi khi xem bog hoa i vao lo thu j 
		for(int i=1;i<=m;i++)
		for(int j=i;j<=n;j++)
		{
			cout<<"a"<<i<<""<<j<<"=";
			cin>>a[i][j];
		}
		
		cout<<"\n";
		for(int i=1;i<=m;i++){		
		for(int j= 1 ; j<=n;j++){
		cout<<a[i][j]<<"\t";	
		}
		
		cout<<"\n";}
		}
	public :void buocthuan(){
		if(m>n) 
		{cout<<"Khong co cac sx "<<m<<" bong hoa vao "<<n<<"lo hoa";return;}
		if(m==n) {
		for(int i=1;i<=m;i++)
		for(int j= i ; j<=n;j++)
		{
			b[i][j]=a[i][j]+b[i-1][j-1];
			}
		cout<<"Gia tri tham my ="<<b[n][n];}
		
		else {
		
		for(int i=1;i<=m;i++)
		for(int j= i ; j<=n;j++)
		
		{
			b[i][j]= max(b[i-1][j-1]+a[i][j],b[i][j-1]);
			
			//b[i][j] =b[i-1][j-1]+a[i][j];
			/*if(b[i][j]<b[i][j-1])
			{
				b[i][j]= b[i][j-1]
			} */
		}
		cout<<"Gia tri tham my cao nhat la "<<b[m][n];
	}
	
		cout<<"\n";
		for(int i=1;i<=m;i++){		
		for(int j= 1 ; j<=n;j++){
		cout<<b[i][j]<<"\t";	
		}
		
		cout<<"\n";}
	
	}	
	public : void buocnghich(int i,int j )
	{ if(b[i][j]==0) return ;
	while(b[i][j]==b[i][j-1]) j--;
	buocnghich(i-1,j-1);		
			cout<<"\ta"<<i<< ""<<j;

	}
	public : int  getM(){ return m;};
	
	public : int  getN(){ return n;};
		
};
int main(){


SXHoa a;
a.nhap();
a.buocthuan();
cout<<"chon vi tri xep :";
a.buocnghich(a.getM(),a.getN());


}

