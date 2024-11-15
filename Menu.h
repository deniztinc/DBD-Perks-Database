#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <fstream>
#include "Database.h"
 
using namespace std;

class menu
{
    private:
    
    public:
    	string input;
        database temp = baseTemp();
    	
    	database baseTemp() //function to read from text into a database class every time database is opened in the terminal
    	{
    	    database temp(1000, 0);
            temp.readThis(true);
            temp.print();
            return temp;
        }
        
        void findName(database temp) const //function that looks for target array[i].name type data
        {
        	bool found = false;
        	string name;
        	cout << "please enter the perk name" << endl;
        	getline(cin, name);
        	
        	for(int i = 0; i < temp.size(); i++)
        	{
        		if(temp.array[i].name == name)
        		{
        			found = true;
        			cout << temp.array[i].name << "-" << temp.array[i].type << "-" << temp.array[i].tier << "\n";
        		}
        		if((temp.array[i].name).find(name) != std::string::npos)
        		{	
        			cout << "substring: " << temp.array[i].name << "-" << temp.array[i].type << "-" << temp.array[i].tier << "\n";
        		}
        	}
        	if(found == false)
        	{
        		cout << endl;
        		cout << "The perk you are looking for is not in the database, returning to main menu\n" << endl;
        	}
        	cout << endl;
        }
        
        void findType(database temp) const //function that looks for target array[i].type type data
        {
        	bool found = false;
        	string type;
        	cout << "please enter the perk type" << endl;
        	getline(cin, type);
        	string tier;
        	
        	for(int i = 0; i < temp.size(); i++)
        	{
        		if(temp.array[i].type == type)
        		{
        			found = true;
        			cout << temp.array[i].name << "-" << temp.array[i].type << "-" << temp.array[i].tier << "\n";
        		}
        		if((temp.array[i].type).find(type) != std::string::npos)
        		{	
        			cout << "substring: " << temp.array[i].name << "-" << temp.array[i].type << "-" << temp.array[i].tier << "\n";
        		}
        	}
        	if(found == false)
        	{
        		cout << endl;
        		cout << "The perk you are looking for is not in the database, returning to main menu\n" << endl;
        	}
        	cout << endl;
        }
        
        void findTier(database temp) const //function that looks for target array[i].tier type data
        {
        	bool found = false;
        	int tierSearch;
        	cout << "please enter the perk tier" << endl;
        	cin >> tierSearch;
        	string tier;
        	
        	for(int i = 0; i < temp.size(); i++)
        	{
        		if(temp.array[i].tier == tierSearch)
        		{
        			found = true;
        			cout << temp.array[i].name << "-" << temp.array[i].type << "-" << temp.array[i].tier << "\n";
        		}
        	}
        	if(found == false)
        	{
        		cout << endl;
        		cout << "The perk you are looking for is not in the database, returning to main menu\n" << endl;
        	}
        	cout << endl;
        }
    	
        menu()
        {
            menu_display();
        }
        
        void addRecord(string choice) //function for adding a new perk class type input
        {
        	if(choice == "A")
        	{
        		perk newPerk;
        		cout << "Please input the perk name" << endl;
        		getline(cin, newPerk.name);
        		cout << "Please input the perk type" << endl;
        		getline(cin, newPerk.type);
        		cout << "Please input the perk tier" << endl;
        		cin >> newPerk.tier;
        		while(newPerk.tier < 1 || newPerk.tier > 3)
        		{
        			cout << "please enter a valid tier" << endl;
        			cin >> newPerk.tier;
        			//ENDLESS LOOP IF WRONG TYPE
        		}
        		cout << endl;
        		
        		perk fileSearch;
        		string tier; 
        		fstream myFile;
        		myFile.open("database.txt");
        		if(myFile.is_open())
        		{
        			while(!myFile.eof())
        			{
        				getline(myFile, fileSearch.name);
        				getline(myFile, fileSearch.type);
        				getline(myFile, tier);
        				fileSearch.tier = stoi(tier);
        				
        				if(fileSearch.name == newPerk.name)
        				{
        					if(fileSearch.type == newPerk.type)
        					{
        						if(fileSearch.tier == newPerk.tier)
        						{
        							cout << "this perk already exists in the database, returning to main menu\n\n" << endl;
        							menu_display();
        						}
        					}
        				}
        			}
        		myFile.close();
        		}
        		temp.append(newPerk);
        		temp.print();
        		cout << "Record has been added to the database" << endl;
        		cout << endl;
        	}
        }
        
        void findRecord(string choice) //find sub-screen and calls of find name/type/tier functions
        {
        	if(choice == "F")
        	{
        		cout << "Find a Perk" << endl;
        		cout << "~~~~~~~~~~~" << endl;
        		cout << endl;
        		cout << "You can search by:" << endl;
        		cout << endl;
        		cout << "(N)ame of perk" << endl;
        		cout << "(TY)pe of perk" << endl;
        		cout << "(TI)er of perk" << endl;
        		cout << endl;
        		cout << "(R)eturn to main menu" << endl;
        		cout << endl;
        		cout << "Please enter the letter of your choice:" << endl; 
        	}
        	getline(cin, choice);
        	if(choice == "R")
        	{
        		menu();
        	}
        	//FOR NAME
        	if(choice == "N")
        	{
        		findName(temp);
        	}
        	//FOR TYPE
        	if(choice == "TY")
        	{
        		findType(temp);
        	}
        	//FOR TIER
        	if(choice == "TI")
        	{
        		findTier(temp);
        	}
        }
        
        int deleteRecord(string choice) //function for delete sub-screen and delete name/type/tier function calls
        {
        	if(choice == "D")
        	{
        		cout << "Please type in >> name << , >> type << or >> tier << based on how you want to delete the perk" << endl;
        		string how;
        		getline(cin, how);
        		if(how == "name")
        		{
        			bool found = false;
        			string name;
        			cout << "Please enter the name of the perk you want to delete " << endl;
        			getline(cin, name);
        			string tier;
        	
        			for(int i = 0; i < temp.size(); i++)
        			{
        				if(temp.array[i].name == name)
        				{
        					found = true;
        					cout << temp.array[i].name << "-" << temp.array[i].type << "-" << temp.array[i].tier << "\n";
        				}
        				if((temp.array[i].name).find(name) != std::string::npos)
        				{	
        					found = true;
        					cout << "substring: " << temp.array[i].name << "-" << temp.array[i].type << "-" << temp.array[i].tier << "\n";
        				}
        			}
        			if(found == false)
        			{
        				cout << endl;
        				cout << "The perk you are looking for is not in the database, returning to main menu\n" << endl;
        				cout << endl;
        				return 0;
        			}
        			cout << "Would you like to delete the exact perk(s) or all the substrings as well?" << endl;
        			cout << "Please type in >> exact << or >> substring << to choose, or >>cancel<< to go back to the main menu" << endl;
        			cout << endl;
        			string answer;
        			getline(cin, answer);
        			database junk(1000, 0);
        			if(answer == "exact")
        			{
        				for(int i = 0; i < temp.size(); i++)
        				{
        					if(temp.array[i].name != name)
        					{
        						junk.array[i].name = temp.array[i].name;
        						junk.array[i].type = temp.array[i].type;
        						junk.array[i].tier = temp.array[i].tier;
        					}
        				}
        				delete[] temp.array;
        				temp.array = junk.array;
        			}
        			else if(answer == "substring")
        			{
        				for(int i = 0; i < temp.size(); i++)
        				{
        					if((temp.array[i].name).find(name) == std::string::npos)
        					{
        						junk.array[i].name = temp.array[i].name;
        						junk.array[i].type = temp.array[i].type;
        						junk.array[i].tier = temp.array[i].tier;
        					}
        				}
        				delete[] temp.array;
        				temp.array = junk.array;
        			}
        			cout << endl;
        			return 0;
        		}
        		if(how == "type")
        		{
        			bool found = false;
        			string type;
        			cout << "Please enter the type of the perks you want to delete " << endl;
        			getline(cin, type);
        			string tier;
        	
        			for(int i = 0; i < temp.size(); i++)
        			{
        				if(temp.array[i].type == type)
        				{
        					found = true;
        					cout << temp.array[i].name << "-" << temp.array[i].type << "-" << temp.array[i].tier << "\n";
        				}
        				if((temp.array[i].type).find(type) != std::string::npos)
        				{	
        					found = true;
        					cout << "substring: " << temp.array[i].name << "-" << temp.array[i].type << "-" << temp.array[i].tier << "\n";
        				}
        			}
        			if(found == false)
        			{
        				cout << endl;
        				cout << "The perk you are looking for is not in the database, returning to main menu\n" << endl;
        				cout << endl;
        				return 0;
        			}
        			cout << "Would you like to delete the exact perk(s) or all the substrings as well?" << endl;
        			cout << "Please type in >> exact << or >> substring << to choose, or >>cancel<< to go back to the main menu" << endl;
        			cout << endl;
        			string answer;
        			getline(cin, answer);
        			database junk(1000, 0);
        			if(answer == "exact")
        			{
        				for(int i = 0; i < temp.size(); i++)
        				{
        					if(temp.array[i].type != type)
        					{
        						junk.array[i].name = temp.array[i].name;
        						junk.array[i].type = temp.array[i].type;
        						junk.array[i].tier = temp.array[i].tier;
        					}
        				}
        				delete[] temp.array;
        				temp.array = junk.array;
        			}
        			else if(answer == "substring")
        			{
        				for(int i = 0; i < temp.size(); i++)
        				{
        					if((temp.array[i].type).find(type) == std::string::npos)
        					{
        						junk.array[i].name = temp.array[i].name;
        						junk.array[i].type = temp.array[i].type;
        						junk.array[i].tier = temp.array[i].tier;
        					}
        				}
        				delete[] temp.array;
        				temp.array = junk.array;
        			}
        			cout << endl;
        			return 0;
        		}
        		if(how == "tier")
        		{
        			bool found = false;
        			int tierSearch;
        			cout << "Please enter the tier of the perks you want to delete " << endl;
        			cin >> tierSearch;
        			database junk(1000, 0);
        	
        			for(int i = 0; i < temp.size(); i++)
        			{
        				if(temp.array[i].tier == tierSearch)
        				{
        					found = true;
        					cout << temp.array[i].name << "-" << temp.array[i].type << "-" << temp.array[i].tier << "\n";
        				}
        			}
        			if(found == false)
        			{
        				cout << endl;
        				cout << "The perk you are looking for is not in the database, returning to main menu\n" << endl;
        				cout << endl;
        				return 0;
        			}
        			for(int i = 0; i < temp.size(); i++)
        			{
        				if(temp.array[i].tier != tierSearch)
        				{
        					junk.array[i].name = temp.array[i].name;
        					junk.array[i].type = temp.array[i].type;
        					junk.array[i].tier = temp.array[i].tier;
        				}
        			}
        			delete[] temp.array;
        			temp.array = junk.array;
        			temp.print();
        			cout << endl;
        			return 0;
        		}	
      		}
      		return 0;
      	}
         
        void listRecord(string choice)
        {
        	if(choice == "L")
        	{
        		cout << "List a Perk" << endl;
        		cout << "~~~~~~~~~~~" << endl;
        		cout << endl;
        		cout << "You can search by:" << endl;
        		cout << endl;
        		cout << "(A)lphabetical" << endl;
        		cout << endl;
        		cout << "(RE)everse Alphabetical" << endl;
        		cout << endl;
        		cout << "(AS)cending Tiers" << endl;
        		cout << endl;
        		cout << "(DE)scending Tiers" << endl;
        		cout << endl;
        		cout << "(R)eturn to main menu" << endl;
        		cout << endl;
        		cout << "Please enter the letter of your choice:" << endl;
        		
        		getline(cin, choice);
        		if(choice == "R")
        		{
        			exit(0);
        		}
        		if(choice == "AS")
        		{
        			int tierCount = 3; //max value tier can have
        			int tierRank = 1;
        			for(int j = 0; j < tierCount; j++, tierRank++)
        			{
        				for(int i = 0; i < temp.size(); i++)
        				{
        					if(temp.array[i].tier == tierRank)
        					{
        						cout << temp.array[i].name << "-" << temp.array[i].type << "-" << temp.array[i].tier << "\n";
        					}
        				}
        			}
        		}
        		if(choice == "DE")
        		{
        			int tierCount = 3; //max value tier can have
        			int tierRank = 3;
        			for(int j = 0; j < tierCount; j++, tierRank--)
        			{
        				for(int i = 0; i < temp.size(); i++)
        				{
        					if(temp.array[i].tier == tierRank)
        					{
        						cout << temp.array[i].name << "-" << temp.array[i].type << "-" << temp.array[i].tier << "\n";
        					}
        				}
        			}
        			
        		}	
        		if(choice == "A" || choice == "RE")
        		{
        			cout << endl;
        			cout << ">> Sorry, I cannot do that yet. <<" << endl;
        			cout << endl;
        		}
        	}
        }
        
        void quitProgram(string choice)
        {
        	if(choice == "Q")
        	{
        		cout << "Quitting the database" << endl;
        		fstream myFile;
        		myFile.open("database.txt");
        		for(int i = 0; i < temp.size(); i++)
        		{
        			myFile << temp.array[i].name;
        			myFile << "\n"; 
        			myFile << temp.array[i].type;
        			myFile << "\n";
        			myFile << temp.array[i].tier;
        			myFile << "\n";
        		}
        		myFile.close();
        		exit(0);
        	}
        }
        
        void menu_display()
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Welcome to the Dead by Daylight Perk Database" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << endl;
            cout << "(A)dd a perk.\n(F)ind a perk.\n(D)elete a perk.\n(L)ist perks.\n(Q)uit." << endl;
            cout << endl;
            
            string choice;
            bool validInput = 0;
            
            cout << "Please enter the letter of your choice:" << endl;
            while(validInput != true)
            {
                getline(cin, choice);
                
                if(choice == "A" || choice == "F" || choice == "D" || choice == "L" || choice == "Q")
                {
                    validInput = true;
                    addRecord(choice);
                    findRecord(choice);
                    deleteRecord(choice);
                    listRecord(choice);
                    quitProgram(choice);
                    
                    menu_display();
                }
                else if(validInput == false)
                {
                    cout << "Please enter a valid letter" << endl;
                }
            }
        }  
};
