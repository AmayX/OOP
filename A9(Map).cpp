#include <iostream>
#include <map>
using namespace std;

class record
{
private:
string name;
string dob;
long int tel;
public:
void input();  
friend ostream &operator << (ostream &out, const record &r);
};

ostream &operator << (ostream &out, const record &r)
{
  out<<r.name<<" "<<r.dob<<" "<<r.tel<<"\n";
  return out;
}

void record::input()
{
  cout<<"Enter the name: ";
  cin>>name;
  cout<<"Enter the Date of Birth (Format: DD/MM/YYYY):";
  cin>>dob;
  cout<<"Enter the telephone number: ";
  cin>>tel;
}

class MapOperations
{
private:
map <int, record> m;
public:
void add();
void display();
void search();
void del(); //delete function
void update();
};

void MapOperations::add()
{
  int key;
  record temp;
  cout<<"Enter the ID value: ";
  cin>>key;
  cout<<"Enter the record values:\n";
  temp.input();
  m.insert(pair<int, record>(key, temp));
}

void MapOperations::display() 
{
  cout<<"Database Enteries:\n";
  cout<<"ID Value\n";
  for (auto i : m)
      cout<<i.first<<"  "<<i.second;
}

void MapOperations::search()
{
  int key,flag=0;
  cout<<"Enter the ID of the person you want to search: ";
  cin>>key;
  for (auto i : m)
    {
      if (i.first==key)
      {
        flag=1;
        cout<<i.second;
        break;
      }
    }
  if (flag==0)
    cout<<"Entered ID value does not exist in the database!\n";
}

void MapOperations::del()
{
  int key,flag=0;
  cout<<"Enter the ID of the person you want to delete: ";
  cin>>key;
  for (auto i : m)
    {
      if (i.first==key)
      {
        flag=1;
        m.erase(key);
        break;
      }
    }
  if (flag==0)
    cout<<"Entered ID value does not exist in the database!\n";
}

int main() {
  MapOperations t;
  t.add();
  t.add();
  t.add();
  t.display();
  t.search();
  t.del();
  t.display();
  return 0;
}