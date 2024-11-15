#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <fstream>
#include "Perk.h"

class database
{
public:
	int siz;
	int cap;
	perk *array;

  	database() : siz(0), cap(10), array(new perk[cap]) {} //default constructor
  	
  	database(int cap, int siz): siz(siz), cap(cap), array(new perk[cap]) {} //constructor with specific capacity and size
  	
  	perk data(int i) const //getter function for array[i]
	{
     		return array[i];
   	}
  	
  	void readThis(bool readFile) //function to read from file every time database is opened in terminal
  	{
  		if(readFile)
  		{
  			fstream myFile;
        		myFile.open("database.txt");
        		string tempInt;
        		perk readingPerk;
        		if(myFile.is_open())
        		{
        			int i = 0;
        			while(!myFile.eof())
        			{
        				getline(myFile, readingPerk.name);
        				getline(myFile, readingPerk.type);
        				getline(myFile, tempInt);
        				readingPerk.tier = stoi(tempInt);
        				
        				this->array[i].name = readingPerk.name;
        				this->array[i].type = readingPerk.type;
        				this->array[i].tier = readingPerk.tier;
        				this->siz++;
        				i++;
        			}
        		}
        		myFile.close();
        	}
        }
  	
	~database() //destructor
	{
		delete[] array;
		array = nullptr;
	}
   	
	int size() const //size
	{
		return siz;
	}
	
	int capacity() const //cap
	{
		return cap;
	}
	
	void append(perk s) //append
	{
		if(siz >= cap)
		{
			cap = cap * 2;
			database* temp = new database[cap];
			for(int i = 0; i < siz; i++)
			{
				temp->array[i].name = array[i].name;
			}
			delete[] array;
			array = temp->array;
		}
		array[siz] = s; 
		siz += 3;
	}
	
	void print() const
	{
		cout << "print function working... \n";
		cout << "[";
		for(int i = 0; i < this->siz; i++)
		{
			cout << array[i].name << ",";
			cout << array[i].type << ",";
			cout << to_string(array[i].tier) << ",";
		}
		cout << "] ";
		cout << endl;
	}
};
