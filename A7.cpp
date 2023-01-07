#include <iostream>
using namespace std;

template <class T>
class vector {
private:
T *a;
int n;
public:
void read();
void modify(int Old, int New);
void ScalarMultiply(int n);
void display();
};

template <class T> void vector<T>::read()
{
  cout<<"Enter the size of the vector: ";
  cin>>n;
  a=new T[n];
  cout<<"Enter "<<n<<" data elements: ";
  for (int i=0;i<n;i++)
    cin>>*(a+i);
}

template <class T> void vector<T>::modify(int Old, int New)
{
  int pos=0,found=0;
  for (int i=0;i<n;i++)
    {
      if (Old==*(a+i))
      {
        found=1;
        pos=i;
        break;
      } 
    }
  if (!found)
    cout<<"Element is not present in the vector!\n";
  else
    *(a+pos)=New;
}

template <class T> void vector<T>::ScalarMultiply (int n)
{
  for (int i=0;i<this->n;i++)
      *(a+i)*=n;
}

template <class T> void vector<T>::display()
{
  cout<<"\nVector Elements:\n";
  cout<<"(";
  for (int i=0;i<n;i++)
    {
      if (i!=n-1)
        cout<<*(a+i)<<", ";
      else
        cout<<*(a+i)<<")\n";
    }
}

int main() {
  vector<int> v1;
  int a,b;
  v1.read();
  v1.display();
  cout<<"Enter two numbers for modifying a data element (Format:   Value_in_vector New_Value): ";
  cin>>a>>b;
  v1.modify(a, b);
  v1.display();
  cout<<"Enter a scaler to multiply a vector by: ";
  cin>>a;
  v1.ScalarMultiply(a);
  v1.display();
  return 0;
}