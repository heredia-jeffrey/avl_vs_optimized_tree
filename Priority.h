/*
Assignment: PA4
Description : This program compares an avl tree and an optimized tree
Author : Jeffrey Heredia
*/
#pragma once
#include <queue>
#include <string>

using namespace std;

class Priority
{
private:
	string _word;
	int _count;
public:
	Priority()
	{
		_word = "";
		_count = 0;
	}

	void setWord(string word)
	{
		_word = word;
	}

	void setCount(int count)
	{
		_count = count;
	}

	string getWord()
	{
		return _word;
	}

	int getCount()
	{
		return _count;
	}

	string const getWord() const
	{
		return _word;
	}

	int const getCount() const
	{
		return _count;
	}

	~Priority()
	{
	}

};


//operator overload for comparison
bool operator>(const Priority &left, const Priority &right)
{
	return left.getCount() > right.getCount();
}

bool operator<(const Priority &left, const Priority &right)
{
	return left.getCount() < right.getCount();
}

bool operator==(const Priority &left, const Priority &right)
{
	return left.getCount() == right.getCount();
}