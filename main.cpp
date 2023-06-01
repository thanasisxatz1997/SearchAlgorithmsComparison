#include <iostream>
#include <cstdlib>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Pinakas
{
	private:
		int *p;
		int n;
	public:
		void setArraySize(int n1);
		void createArray();
		void fillArray();
		void printArray();
		int sequentialSearch(int key,int *pcnt);
		int binarySearch(int left, int right,int key, int *pcnt);
		int binarySearchWithArray(int key, int *pcnt);
		void printResults(int pos,int cnt);
		void freeArrayMem();
};

int main(int argc, char** argv) {
	Pinakas aker;
	int n,x,pos1,pos2,pos3,count1,count2,count3;
	cout<<"Dose to megethos tou pinaka: ";
	cin>> n;
	aker.setArraySize(n);
	aker.createArray();
	aker.fillArray();
	aker.printArray();
	cout<<"Dose stoixeio gia anazitisi: ";
	cin>>x;
	cout<<endl;
	count1=0;
	pos1=aker.sequentialSearch(x,&count1);
	cout<<"SEQUENTIAL SEARCH"<<endl;
	cout<<"==========================="<<endl;
	aker.printResults(pos1,count1);
	cout<<endl;
	
	count2=0;
	pos2=aker.binarySearch(0,n,x,&count2);
	cout<<"BINARY SEARCH"<<endl;
	cout<<"==========================="<<endl;
	aker.printResults(pos2,count2);
	cout<<endl;
	
	count3=0;
	pos3=aker.binarySearchWithArray(x,&count3);
	cout<<"ARRAY BINARY SEARCH"<<endl;
	cout<<"==========================="<<endl;
	aker.printResults(pos3,count3);
	cout<<endl;
	aker.freeArrayMem();
	

	return 0;
}

void Pinakas::setArraySize(int n1)
{
	n=n1;
}

void Pinakas::createArray()
{
	p=new int[n];
}

void Pinakas::fillArray()
{
	int i;
	for(i=0;i<n;i++)
	{
		p[i]=10*(i+1);
	}
}

void Pinakas::printArray()
{
	int i;
	for(i=0;i<n;i++)
	{
		cout <<p[i]<<" "<<endl;
	}
	cout<<endl;
}

int Pinakas::sequentialSearch(int key,int *pcnt)
{
	int i,pos;
	bool found;
	pos=-1;
	i=0;
	found=false;
	while(i<n&&found==false)
	{
		(*pcnt)++;
		if(p[i]==key)
		{
			found=true;
			pos=i;
		}
		else
		{
			i++;
		}
	}
	return pos;
}

int Pinakas::binarySearch(int left,int right,int key, int *pcnt)
{
   int mid, pos;

   (*pcnt)++;
   if(left > right)
   {
   	pos = -1;
   }
   else
    {
        mid = (left + right) / 2;
        if(p[mid] == key)
           pos = mid;
        else
           if(key < p[mid])
              pos = binarySearch(left,mid-1,key,pcnt);
           else
              pos = binarySearch(mid+1,right,key,pcnt);
   	}

   return pos;  
}

int Pinakas::binarySearchWithArray(int key, int *pcnt)
{
	int r=n;
	int l=0;
	while(r>=l)
	{
		(*pcnt)++;
		int mid=(l+r)/2;
		if(p[mid]==key)
		{
			return mid;
		}
		if(p[mid]>key)
		{
			r=mid+1;
		}
		if(p[mid]<key)
		{
			l=mid-1;
		}
	}
	return -1;
}

void Pinakas::printResults(int pos,int cnt)
{
	if(pos==-1)
	{
		cout<<"Not found."<<endl;
	}
	else
	{
		cout<<"Found at position: "<< pos<<endl;
	}
	cout<<"Elements examined: "<<cnt<<endl;
}

void Pinakas::freeArrayMem()
{
	delete []p;
}
