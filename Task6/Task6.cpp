//
//  main.cpp
//  Task6v3
//
//  Created by Nikita Barsukov on 01.02.15.
//  Copyright (c) 2015 Nikita Barsukov. All rights reserved.
//
/*Реализовать класс АДРЕСНАЯ КНИГА. Класс должен быть предназначен для хранения адресов различных людей, при этом адрес состоит из улицы, номера дома и номера квартиры. Не должно быть ограничений на количество людей в адресной книге. Человек задаётся строкой, содержащей фамилию на русском или английском языке, опционально можно добавлять (через пробел) имя и отчество.
Требуемые методы: конструктор по умолчанию (создаёт пустую книгу), деструктор, вывод адресной книги в текстовый файл и ввод адресной книги из того же текстового файла (т.е. сохранение и загрузка), добавление пары «человек—адрес», удаление человека из адресной книги, изменение адреса заданного человека, получение адреса заданного человека, поиск всех людей, живущих на заданной улице, поиск всех людей, живущих в заданном доме (улица + номер дома).
Написать главную функцию, тестирующую данный класс путём создания его объектов и проведения над ними различных операций.*/



#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
int razm();




class AdressBook
{
public:
    const int a=0;
    vector<string> name;
    vector<string> street;
    vector<string> numhouse;
    vector<string> numofappartament;
    
    AdressBook(){}
    ~AdressBook(){}
    
   
    
    void add(string nm, string st, string nh, string na)
    {
        name.push_back(nm);
        street.push_back(st);
        numhouse.push_back(nh);
        numofappartament.push_back(na);

        
    }
   //////////////////////////////////////////
    void show()
    {
        for(int i=0; i<name.size(); i++)
        {
            cout<<name[i]<<endl;
            
        }
    
    }
   ////////////////////////////////////////
    void get(string nm)
    {
        int j=0;
        for(int i=0; i<name.size(); i++)
        {
            if (name[i]==nm)
            {
                j=i;
                //cout<<name[i]<<" "<<street[i]<<" дом: "<<numhouse[i]<<" квартира: "<<numofappartament[i];
            }
        }
        
        if(j==0)
        {
            cout<<"Такой записи нет" << endl;
        }
        else
        {
            cout<<name[j]<<" улица "<<street[j]<<" дом: "<<numhouse[j]<<" квартира: "<<numofappartament[j]<<endl;
        }
        

        
    
    }
    ///////////////////////////////////////
    
    void erase(string nm)
    {
        for(int i=0; i<name.size(); i++)
        {
            if(name[i]==nm)
            {
                name[i].erase();
                street[i].erase();
                numhouse[i].erase();
                numofappartament[i].erase();
                
            }
        }
    }
    //////////////////////////////////////
    void save()
    {
        ofstream out("/Users/nikitabarsukov/Desktop/AdressBook.txt");
        string a;
        for(int i=0; i<name.size(); i++)
        {
            out<<name[i]<<" "<<street[i]<<" "<<numhouse[i]<<" "<<numofappartament[i]<<endl;
        }
        
        
    }
    //////////////////////////////////////
    void load()
    {
     ifstream in("/Users/nikitabarsukov/Desktop/AdressBook.txt");
        int r;
        r=razm();
        
        for(int i=0; i<r; i++)
        {
            string nam;
            string stret;
            string numhuse;
            string numofa;
            
            in>>nam>>stret>>numhuse>>numofa;
            name.push_back(nam);
            street.push_back(stret);
            numhouse.push_back(numhuse);
            numofappartament.push_back(numofa);
            
            
        }
        
    }
  //////////////////////////////////////////////////////////////
    void sbystreet (string n)
    {
        for(int i=0; i<name.size(); i++)
        {
            if(street[i]==n)
            {
                cout<<name[i]<<" ";
            }
        }
    }
    /////////////////////////////////////////////////////////////
    void sbystandhs (string a,string b)
    {
        for(int i=0; i<name.size(); i++)
        {
            if(street[i]==a&&numhouse[i]==b)
            {
                cout<<name[i]<<" ";
            }
        }
    }
    
    void change (string nm, string st, string nh, string na)
    {
        for(int i=0; i<name[i].size(); i++)
        {
            if(nm==name[i])
            {
                street[i]=st;
                numhouse[i]=nh;
                numofappartament[i]=na;
                
                
            }
        }
    }
    
};


int razm()
{
    ifstream in("/Users/nikitabarsukov/Desktop/AdressBook.txt");
    char szPeremen;
    unsigned int nN = 0;
    while ((szPeremen = in.get()) != EOF){
        if(szPeremen=='\n')
        {
            nN++;
        }
        
    }
    in.close();
    return nN;
}


int main()
{
    AdressBook ab;
    ab.load();
    ab.add("Alexandr", "Murinskiy", "23", "45");
    ab.change("Miron", "Orbely", "23", "33");
    ab.save();
    ab.get("Alexand");
  
}