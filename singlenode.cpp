/*******************************************************************************
Title: singlenode.cpp
Author: Fazlay Rabbi 
Created on: 12/14/2014 
Description: Implementation file of singlenode.h for a program which outputs names 
of species based on their score. Purpose of this program is to demonstrate 
usage of tree.
Usage: ./a.out input_file
Build with: g++ -std=c++0x hwk4_frabbi.cpp
Dependencies: One input file that should be in the same directory. 
Modifications: Comments were added on 12/14/2014
*******************************************************************************/
#include <string>
#include <iostream>
#include <cstdlib>
#include "singlenode.h"
using namespace std;


void single_node::setScore(double s){ 
	score= s;
}

void single_node::setName(string n){ 
	name = n; 
}
single_node::single_node(double g){
	score = g;
	left = NULL;
	right = NULL;
}

double single_node::getScore(){ 
	return score; 
}
string single_node::getName(){ 
	return name; 
}

single_node* single_node::getLeft(){ 
	return left;
}
single_node* single_node::getRight(){ 
	return right;
}


void single_node::setLeft(single_node* node){ 
	left= node;
}
void single_node::setRight(single_node* node){ 
	right= node;
}