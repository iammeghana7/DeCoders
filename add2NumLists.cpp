//Add 2 numbers represented by linked list 

#include<iostream>
using namespace std;


struct node 																		//singly linked list
{
	int info;
	struct node * link;
};

typedef struct node * NODEPTR;

NODEPTR fnGetNode()																	
{
	NODEPTR temp=(NODEPTR) malloc(sizeof(struct node));
	if(temp==NULL)
		return NULL;
	else
		return temp;
}

NODEPTR insertF(NODEPTR num,int ele)														// to insert 0's for smaller number
{
	NODEPTR first=num;
	if(num==NULL)																	//to insert first element
	{
		num=fnGetNode();
		num->link=NULL;
		num->link=NULL;
		num->info=ele;
		return num;
	}

	NODEPTR temp;
	temp=fnGetNode();
	temp->info=ele;
	
	temp->link=num;
	

	return temp;
}
	
int len(NODEPTR d1)
{
	int l=0;
	while(d1)
	{
		l+=1;
		d1=d1->link;
	}
	return l;
}

int main()
{
	
	int t;
	int d;
	cout<<"\nEnter number of test cases:\t";
	cin>>t;
	int d1,d2;
	while(t)
	{
		NODEPTR dnum1=NULL,dnum2=NULL;													//to store 2 numbers we take 2lists
		int n1,n2;
		
		cout<<"\nEnter num1:\t";
		cin>>n1;
		
		while(n1)
		{
			dnum1=insertF(dnum1,n1%10);														//storing the number in linked list
			n1/=10;
		}
		
		cout<<"\nEnter num2:\t";
		cin>>n2;
		
		while(n2)
		{
			dnum2=insertF(dnum2,n2%10);														//storing the number in linked list
			n2/=10;
		}
		int l1=len(dnum1);
		int l2=len(dnum2);
		
		
		
		
		
		if(l1>l2)
		{
			d=l1-l2;
			while(d)
			{
				dnum2=insertF(dnum2,0);
				d-=1;
				
			}
		}
		if(l2>l1)
		{
			d=l2-l1;
			while(d)
			{
				dnum1=insertF(dnum1,0);
				d-=1;
			}
		}
	
		
		
		
		int sum=0;

		sum+=(dnum1->info+dnum2->info);
	
		dnum1=dnum1->link;dnum2=dnum2->link;
		
		
		
			
		while(dnum1!=NULL ||dnum2!=NULL)
		{
			
			
			sum=sum*10;
	
			
			sum+=(dnum1->info+dnum2->info);
			dnum1=dnum1->link;
			dnum2=dnum2->link;
			
		}
	
		
		cout<<"\nSum is "<<sum<<"\n";
		t-=1;
	}
		
}

	
