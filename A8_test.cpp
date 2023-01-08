#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Node
{
public:
int id;
char name[50], sal[50], post[50];
friend istream &operator >> (istream &in, Node &temp)
{
  cout<<"ID:";
  in>>temp.id;
  cout<<"Name:";
  in>>temp.name;
  cout<<"Salary:";
  in>>temp.sal;
  cout<<"Post:";
  in>>temp.post;
  return in;
}
friend ostream &operator << (ostream &out, const Node &temp)
{
  cout<<"\nID: ";
  out<<temp.id;
  cout<<"\nName: ";
  out<<temp.name;
  cout<<"\nSalary: ";
  out<<temp.sal;
  cout<<"\nPost: ";
  out<<temp.post<<endl;
  return out;
}
};

class file
{
private:
fstream f;
public:
static int count;
void add();
void display();
void search();
};

int file::count=0;

void file::add()
{
  ++count;
  Node temp;
  f.open("Data.bin", ios::out | ios::binary | ios::app);
  cout<<"Enter:\n";
  cin>>temp;
  f.write((char*)&temp, sizeof(temp));
  f.close();
}

void file::display()
{
  Node temp;
  f.open("Data.bin", ios::in | ios::binary);
  f.seekg(0);
  while (f.read((char*)&temp, sizeof(temp)))
    {
      cout<<temp;
    }
  f.close();
}

void file::search()
{
  Node temp;
  int id;
  cout<<"Enter ID to search: ";
  cin>>id;
  f.open("Data.bin", ios::in | ios::binary);
  f.seekg(0);
  while (f.read((char*)&temp, sizeof(temp)))
    {
      if (temp.id==id)
        {
          cout<<temp;
          break;
        }
    }
  f.close();
}

int main() {
  file obj;
  obj.add();
  obj.add();
  //obj.add();
  obj.display();
  obj.search();
  obj.display();
  return 0;
}


