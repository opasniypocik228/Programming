//
//  main.cpp
//  laba 6v2
//
//  Created by Nikita Barsukov on 18.01.15.
//  Copyright (c) 2015 Nikita Barsukov. All rights reserved.
//
/* Реализовать класс АДРЕСНАЯ КНИГА. Класс должен быть предназначен для хранения адресов различных людей, при этом адрес состоит из улицы, номера дома и номера квартиры. Не должно быть ограничений на количество людей в адресной книге. Человек задаётся строкой, содержащей фамилию на русском или английском языке, опционально можно добавлять (через пробел) имя и отчество.
Требуемые методы: конструктор по умолчанию (создаёт пустую книгу), деструктор, вывод адресной книги в текстовый файл и ввод адресной книги из того же текстового файла (т.е. сохранение и загрузка), добавление пары «человек—адрес», удаление человека из адресной книги, изменение адреса заданного человека, получение адреса заданного человека, поиск всех людей, живущих на заданной улице, поиск всех людей, живущих в заданном доме (улица + номер дома).
Написать главную функцию, тестирующую данный класс путём создания его объектов и проведения над ними различных операций. */


#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;

class AdressBook
{
    public:
    
        string name;
        string street;
        string numhouse;
        string numapp;
    AdressBook(const AdressBook &v):
    name(v.name),street(v.street),numhouse(v.numhouse),numapp(v.numapp){}
    AdressBook() {}
    
    const AdressBook &operator=(const AdressBook &v)
    {
        name=v.name;
        street = v.street;
        numhouse =v.numhouse;
        numapp = v.numapp;
        return v;
    }
    
     void Load()
    {
        ifstream adressbook("/users/nikitabarsukov/desktop/adressbook.txt");
        vector<AdressBook> adrBook;
        while(true)
        {
            AdressBook t;
     
           
            adressbook>>t.name;
            if(adressbook.eof())
           {
           break;
            }
     
     
            adressbook>>t.street;
            if(adressbook.eof())
            {
                break;
            }
            adressbook>>t.numhouse;
            if(adressbook.eof())
            {
                break;
            }
            adressbook>>t.numapp;
            if(adressbook.eof())
            {
                break;
            }
            adrBook.push_back(t);
        }
        
    }

    
    void save(vector<AdressBook> &adrBook)
    {
        ofstream adressbook("/users/nikitabarsukov/desktop/adressbook.txt");
        
        for(int i=0; i<adrBook.size();i++)
        {
            adressbook<<adrBook[i].name;
            adressbook<<adrBook[i].street;
            adressbook<<adrBook[i].numhouse;
            adressbook<<adrBook[i].numapp;
        }
    }
    
    void deletebyname(vector<AdressBook> &adrBook)
    {
        
        
        cout<<"Введите Имя";
        string name;
        cin>>name;
        for(int i=0; i<adrBook.size();i++)
        {
            if(name==adrBook[i].name)
            {   cout<<"Done";
                adrBook.erase(adrBook.begin() +i);
            } else{
                cout<<"Имя не найдено в файле";
            }   break;
        }
   

    }
    
    void searchingbystreet(vector<AdressBook> &adrBook)
    {
        cout<<"Введите Номер дома";
        string street;
        cin>>street;
        for(int i=0; i<adrBook.size();i++)
        {
            if(street==adrBook[i].street)
           
            cout<<adrBook[i].name<<endl;
            cout<<adrBook[i].street<<endl;
            cout<<adrBook[i].numhouse<<endl;
            cout<<adrBook[i].numapp<<endl;
            
        }

    }
   
    void searchingbyname(vector<AdressBook> &adrBook)
    {
        cout<<"Введите Номер дома";
        string name;
        cin>>name;
        for(int i=0; i<adrBook.size();i++)
        {
            if(name==adrBook[i].name)
                
            cout<<adrBook[i].name<<endl;
            cout<<adrBook[i].street<<endl;
            cout<<adrBook[i].numhouse<<endl;
            cout<<adrBook[i].numapp<<endl;
            
        }
        
    }

    
    void searchingbykey(vector<AdressBook> &adrBook)
    {
        cout<<"Введите Номер дома и улицы";
        string street, house;
        cin>>street>>house;
        for(int i=0; i<adrBook.size();i++)
        {
            if(street==adrBook[i].street&&house==adrBook[i].numhouse)
                
            cout<<adrBook[i].name<<endl;
            cout<<adrBook[i].street<<endl;
            cout<<adrBook[i].numhouse<<endl;
            cout<<adrBook[i].numapp<<endl;
            
        }
        
    }

    
};

    
