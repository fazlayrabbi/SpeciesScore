/*******************************************************************************
Title: hwk4_frabbi.cpp
Author: Fazlay Rabbi 
Created on: 12/14/2014 
Description: Main file for a program which outputs names of species based 
on their score. Purpose of this program is to demonstrate usage of tree.
Usage: ./a.out input_file
Build with: g++ -std=c++0x hwk4_frabbi.cpp
Dependencies: One input file that should be in the same directory. 
Modifications: Comments were added on 12/14/2014
*******************************************************************************/
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <locale>
#include "species.cpp"
#include "tree.cpp"
#include "singlenode.cpp"
using namespace std;

int main(int argc, char* argv[])
{
	ifstream fin;
	string input, name;/* input gets input value from file while name is 
							used to store name of the species.*/
	double score; /*Used to store score of the species.*/
	fin.open(argv[1]);
	if (fin.fail()){
		cerr << "File could not be opened!\n";
		exit(1);
	}
	list<single_node> database;//stores species' name and score
	list<single_node>::iterator it_i;
	int database_index = 0;// use to keep track of index number of database
	while (getline(fin, input)){
		istringstream iss( input);//used to determine whether input line is in correct format
		list<string> lineInput;//used to store input values within line.
		string temp;// used to store lineInput, name and score.
		int count= 0;// number of iss 
		while(iss >> temp){
			lineInput.push_back(temp);
			count++;
		}
		if (lineInput.size()<2||lineInput.size()>2)// invalid format
			continue;
		list<string>::iterator i;		
		i= lineInput.begin();
		temp= *i;
		locale loc;// used to determine whether input line is in correct format
		if (isdigit(temp[0], loc))// if first value is digit, then the line is in wrong format
			continue;
		else
 			name= temp;
		i++;
		temp= *i;
		if (!isdigit(temp[0], loc))// if second value is digit, then the line is in wrong format
			continue;
		else
 			score= stof(temp);// temp is converted to float
		database.push_back(score);// score is set
		if (database.size() == 1)
			it_i = database.begin();
		else{
			int j = 0;
			for (it_i = database.begin(); it_i != database.end(); ++it_i){
				if (j == database_index)
					break;
				j++;
			}
		}
		it_i->setName(name);// name is set
		database_index++;
	}
	
	tree species;
	generateNodes(database, species);
	species.print( cout);
	species.deleteTree();
	fin.close();
	return 0;
}