#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int n1,n2,n,num,num1,num2,carry,ele;
	stack <int> s1;
	stack <int> s2;
	stack <int> s3;
	carry=0;
	cout<<"Please enter number of bits of first number:\t";
	cin>>n1;
	cout<<"Please enter number of bits of second number:\t";
	cin>>n2;
	if(n1>n2)
    {
        n=n1-n2;
        for(int i=0;i<n;i++)
        {
            s2.push(0);
        }
    }
    else if(n2>n1)
    {
       n=n2-n1;
        for(int i=0;i<n;i++)
        {
            s1.push(0);
        }
    }
	cout<<"\nNote:Enter number bit by bit\n";
	cout<<"\nEnter first number : ";
	for (int i = 0; i < n1; ++i)
	{
		cin>>num;
		s1.push(num);
	}

	cout<<"\nEnter second number : ";
	for (int i = 0; i < n2; ++i)
	{
		cin>>num;
		s2.push(num);
	}

	while(!s1.empty() && !s2.empty())
	{
		num1=s1.top();
		num2=s2.top();
		s1.pop();
		s2.pop();
		if(num1 + num2 + carry==0)
		{
			ele=0;
			carry=0;
		}
		else if(num1 + num2 + carry==1)
		{
			ele=1;
			carry=0;
		}
		else if(num1 + num2 + carry==2)
		{
			ele=0;
			carry=1;
		}
		else if(num1 + num2 + carry>2)
		{
			ele=1;
			carry=1;
		}
		s3.push(ele);
	}
	if(carry==1)
		s3.push(carry);
	cout<<"\nThe addition of entered two binary numbers is : ";
	while(!s3.empty())
	{
		ele=s3.top();
		s3.pop();
		cout<<ele;
	}
	cout<<"\n";
	return 0;
}
