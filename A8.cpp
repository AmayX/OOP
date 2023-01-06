#include <iostream>
#include <fstream>
using namespace std;

class Node
{
public:
int id;
string name;
int age;
string dept;
string post;
int sal;
friend istream &operator >> (istream &in, Node &temp)
{
  cout<<"Enter ID: ";
  in>>temp.id;
  cout<<"Enter Name: ";
  in>>temp.name;
  cout<<"Enter age: ";
  in>>temp.age;
  cout<<"Enter department: ";
  in>>temp.dept;
  cout<<"Enter post: ";
  in>>temp.post;
  cout<<"Enter salary: ";
  in>>temp.sal;
  return in;
}

friend ostream &operator << (ostream &out, const Node &temp)
{
  out << temp.id <<" "<< temp.name <<" "<< temp.age <<" "<< temp.dept <<" "<<temp.post<<" "<<temp.sal;
  return out;
}
};

class File
{
private:
fstream file;
public:
void add();
void display();
static int count;
};

int File::count=0;

void File::add()
{
  Node temp;
  ++count;
  file.open("Data.bin", ios::in  | ios::binary | ios::app | ios::ate);
  cin>>temp;
  file.write((char*)&temp,sizeof(temp));
  file.close();
}

void File::display()
{
  Node temp;
  file.open("Data.bin", ios::out | ios::binary);
  if(!file)
  {
    cout<<"Error\n";
  }
  for (int i=0;i<count;i++)
    {
      file.read((char*)&temp,sizeof(temp));
      cout<<temp;
    }
  file.close();
}

int main() {
  File obj;
  obj.add();
  obj.add();
  obj.display();
}