#include<bits/stdc++.h>
using namespace std;

class page
{
private:
    
public:
    vector<int> data;
    int rem;
    page(int total);
    ~page();
};

page::page(int total)
{
    rem = total-16;
}

page::~page()
{
}

class file
{
private:
    int total; 
    vector<page> ve;
    
public:
    file(int tot);
    void insert(int,int);
    void status();
    void search(int);
    ~file();
};

file::file(int tot)
{
    total=tot;
}

void file::insert(int cap,int val)
{
   int flag = 0;

   for(int i=0;i<ve.size();i++)
   {
       if(ve[i].rem - cap - 4 >= 0)
       {
           ve[i].data.push_back(val);
           ve[i].rem = ve[i].rem - cap - 4;
           flag =1;
           break;
       }
   }

   if(flag==0)
   {    
       page *p = new page(total);
       ve.push_back(*p);
       ve[ve.size() -1].data.push_back(val);
       ve[ve.size()-1].rem=ve[ve.size()-1].rem-cap-4;
   }
}

void file::status()
{
    cout << ve.size() << " ";

    for(int i=0;i<ve.size();i++)
        cout << ve[i].data.size()  <<" ";

    cout << endl;
}

void file:: search(int val)
{
    int flag=0;
    for(int i=0;i<ve.size();i++)
    {
        for(int j=0;j<ve[i].data.size();j++)
        {
            if(ve[i].data[j] == val)
            {
                cout << i << " " << j << endl;
                flag=1;
                break;
            }
        }

        if(flag==1)
            break;
    }

    if(flag==0)
        cout << -1 << " " << -1 << endl;
}

file::~file()
{
}

int main()
{
    int s;
    cin >> s;

    file fe(s);

    int x;
    
    while(cin >> x)
    {
        switch (x)
        {
        case 1:
            int a,b;
            cin >> a >> b;
            fe.insert(a,b);
            break;

        case 2:
            fe.status();
            break;
        
        case 3:
            int c;
            cin >> c;
            fe.search(c);
            break;
        
        default:
            break;
        }
    }
}