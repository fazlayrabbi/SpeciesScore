/*******************************************************************************
Title: species.h
Author: Fazlay Rabbi 
Created on: 12/14/2014 
Description: Header file of main program which outputs names 
of species based on their score. Purpose of this program is to demonstrate 
usage of tree.
Usage: ./a.out input_file
Build with: g++ -std=c++0x hwk4_frabbi.cpp
Dependencies: One input file that should be in the same directory. 
Modifications: Comments were added on 12/14/2014
*******************************************************************************/
#ifndef SPECIES_H
#define SPECIES_H
/*used to sort a list of type single_node based on score
pre-condition: gets called within std::list function sort()
post-condition: list of single_node is sorted in descending manner
*/
bool sortDescending(single_node& lhs, single_node& rhs);
/*generates nodes for tree mytree for which leaves are in database.
pre-condition: mytree is declared in caller and database contains all leaves
post-condition: all nodes of mytree are generated
*/
void generateNodes(list<single_node>& database, tree& mytree);
#endif