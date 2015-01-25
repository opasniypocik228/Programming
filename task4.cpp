// created by Nikitos

// Латинским квадратом порядка n называется квадратная таблица размером n x n, каждая строка и каждый столбец которой содержат все числа от 1 до n. Проверить, является ли заданная целочисленная матрица латинским квадратом. Входную матрицу следует читать из файла in.txt (первые два числа в файле – размерности матрицы, далее – элементы матрицы), результат следует записывать в файл out.txt (одной строчкой – латинский квадрат, не латинский квадрат)



#include<iostream>
#include<stdlib.h>
#include <fstream>
using namespace std;
int main()
{
    const int MAX_SIZE = 50;
    int a[MAX_SIZE][MAX_SIZE];
    int y, n ;
    ifstream in("/Users/nikita/Desktop/in.txt");
    ofstream out("/Users/nikita/Desktop/out.txt");
    if (!in.is_open())
    {
        out<<"Файл in.txt не существует"<<endl;
        return -1;
    }
    in>>y>>n;
    if (in.fail() || y<1 || y>MAX_SIZE ||
        n<1 || n>MAX_SIZE)
    {
        out<<"Некорректные размерности"<<endl;
        return -2;
    }
    
    for (int i=0; i<y; i++)
        for (int j=0; j<n; j++)
            in>>a[i][j];
    if (in.fail())
    {
        out<<"Не удалось прочитать матрицу"<<endl;
        return -3;
    }
    if(y!=n)
    {
        out<< "Некорректные размерности";
    }
    cout<< y<<n;
    for (int i=0; i<y; i++)
    {
        cout<<endl;
        { for (int j=0; j<n; j++)
            cout<<a[i][j];
        }
    }

    int m[y];
   
    
    for(int i=0; i<y;i++)
    {
        m[i]=i+1;
    }
   
    
    int sum=0;
    int s;
    int s2;
  
    
    for(int b=0;b<y; b++ )
    {
        for(int i=0; i<y; i++)
        {
            s=0;
            for(int j=0; j<n; j++)
            {
                if(a[i][j]==m[b])
                {
                    s++;
                    
                    if(s==2)
                    {
                        goto s2;
                    }
                    
                }
            }
        }
    }
    
    
s2: for(int b=0;b<y; b++ )
{
    for(int j=0; j<n; j++)
    {
        s2=0;
        for(int i=0; i<n; i++)
        {
            if(a[i][j]==m[b])
            {
                s2++;
                if(s2==2)
                {
                    goto end;
                }
                sum+=s2;
            }
        }
    }
}
    for (int i=0; i<y; i++)
    {
        for (int j=0; j<n; j++)
        {
            if(a[i][j]==0||a[i][j]>y)
            {
                s=15;
            }
        }
    }
    
    
    

    
    
    
        end: if(s==1&&s2==1)
        {
            out<<"Латинский квадрат"<<endl;
        }
        else
        {
             out<<"Не латинский квадрат"<<endl;
        }
}







    




