/*
Assignment: PA4 
	Description : This program compares an avl tree and an optimized tree
	Author : Jeffrey Heredia
*/
#pragma once
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <queue>
#include "Priority.h"
#include "AvlTree.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	string file_name, input;
	AvlTree<string> avl_tree;
	BinarySearchTree<string> bi_tree;
	
	//prompt the user to enter the name of input file
	cout << "What is the name of the input file?" << endl;
	getline (cin, file_name);
	
	//open the file
	ifstream text(file_name);
	
	//declare an unordered map to hash the input values to
	unordered_map<string, int> map{};
	
	//loop through the input file and extract the words
	//if it is a new word add it to the map
	//otherwise incriment count by one
	while (text >> input)
	{
		//take the input and put it to all caps
		//this prevents "Word" from being different then "word"
		//use temp_word to assist this process
		string temp_word = "";
		for(int i = 0; i < input.size(); i++)
		{
			temp_word += toupper(input.at(i));
		}
		input = temp_word;
		
		//now add the element to the hash tabale
		map[input]++;
		
		
		//check if input is in the AVL if its not add it
		if(!avl_tree.containsElement(input))
			avl_tree.addElement(input);
	}

	//now loop through and add elements to the priority queue
	priority_queue<Priority> pq{};
	Priority element;
	for (auto item : map)
	{
		element.setWord(item.first);
		element.setCount(item.second);
		pq.push(element);
	}
	
	//go through the priority queue grabbing most used word
	//add the most used word to a BST and then grab the next 
	while(!pq.empty())
	{
		element = pq.top();
		pq.pop();
		bi_tree.addElement(element.getWord());
	}

	//loop back through the text this time getting counts
	//of how many nodes you have to visit each time a word appears
	int bi_counter = 0;
	int avl_counter = 0;
	ifstream text_count(file_name);
	while (text_count >> input)
	{
		//convert the input to all caps again
		string temp_word = "";
		for (int i = 0; i < input.size(); i++)
		{
			temp_word += toupper(input.at(i));
		}
		//assign the input to have the caps version
		input = temp_word;

		//call the travel counter function on input to find 
		//the number of nodes traveled to reach that word
		//then add that to a running total for each tree
		avl_counter += avl_tree.travelCounter(temp_word);
		bi_counter += bi_tree.travelCounter(temp_word);
	}

	//print out the grand total of traveled nodes for each tree
	cout << "Total nodes visited for avl tree: " << avl_counter << endl;
	cout << "Total nodes visited for optimized tree: " << bi_counter << endl;
		
	
	return 0;
}