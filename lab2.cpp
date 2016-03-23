/*
 * lab31.cpp
 *
 *  Created on: 24-Feb-2016
 *      Author: 1CR13IS083
 */
#include <iostream>
#include<sstream>
#include<fstream>
#include<string.h>
using namespace std;


class student{
			string name;
			string usn;
			string branch;
			string sem;
	public: void pack();
			void unpack();
			void modify();
			int search(string);
			void read();
			void delet(string);
			void insert();
			string buffer;
			fstream f1;

};

int main()
{
	int choice,pos;
	student s;
	string key;
	while(1)
	{
		cout<<"\n\n1.insert 2.search 3.modify 4.delete 5.Exit\n	";
		cin>>choice;
		switch(choice)
		{
		case 1: s.insert();
				break;
		case 2: cout<<"\nEnter the key"<<endl;
				cin>>key;
				pos=s.search(key);
				cout<<"Position at"<<pos;
				break;
		case 3:s.modify();
			break;		
		case 5: return 1;
		}
	}
	return 0;
}




void student:: read()
{
	cout<<"\n\nenter the name"<<endl;
	cin>>name;
	cout<<"enter the usn"<<endl;
	cin>>usn;
	cout<<"enter the branch"<<endl;
	cin>>branch;
	cout<<"enter the semester"<<endl;
	cin>>sem;
}
void student :: pack()
{

	buffer=name+'|'+usn+'|'+branch+'|'+sem;
	buffer.resize(100,'$');
	f1.open("data.txt",ios::out|ios::app);
	f1<<buffer<<endl;
	f1.close();
}

void student ::insert()
{
	read();
	pack();
}


int student::search(string key)
{

		int flag=0,pos;
		f1.open("data.txt",ios::in);
		while(!f1.eof())
		{
			getline(f1,buffer);

			unpack();
			if(key==usn)
			{
				cout<<"Record Found"<<endl;
				pos=f1.tellp();
				cout<<"Buffer is "<<buffer<<endl;
				f1.close();
				return pos;
			}
						
		}
		cout<<"Record not found"<<endl;
		f1.close();
}

void student::unpack()
{
	int i=0;
	name.erase();
	usn.erase();
	while(buffer[i]!='|')
		name+=buffer[i++];
	i++;
	while(buffer[i]!='|')
		usn+=buffer[i++];
	i++;
	while(buffer[i]!='|')
		branch+=buffer[i++];
	i++;
	while(buffer[i]!='$')
		sem+=buffer[i++];
	i++;

}


void student::modify()
{
	int pos,choice;
	string key;
	cout<<"Enter the key"<<endl;
	cin>>key;
	pos=search(key);
	pos=pos-101;
	cout<<"Before modify position is\n"<<pos;
	cout<<"Enter which field to modify";
	cout<<"\n\n1.NAME,2.USN,3.BRANCH,4.SEM";
	cin>>choice;
	
	/*name.erase();
	usn.erase();
	branch.erase();
	sem.erase();*/
	switch(choice)
	{
		case 1:cout<<"\n\nenter the name"<<endl;
			cin>>name;
			break;
		case 2:cout<<"enter the usn"<<endl;
			cin>>usn;
			break;
		case 3:cout<<"enter the branch"<<endl;
			cin>>branch;
			break;
		case 4:cout<<"enter the semester"<<endl;
			cin>>sem;
			break;
		default:cout<<"Wrong selection,Try again";
	}
	
	cout<<"In delete the position is"<<pos<<endl;
	buffer.erase();
	buffer=name+'|'+usn+'|'+branch+'|'+sem;
	buffer.resize(100,'$');
	f1.open("data.txt");
	f1.seekp(pos,ios::beg);
	f1<<buffer<<endl;
	f1.close();
	
}

