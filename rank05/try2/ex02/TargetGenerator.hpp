#pragma once

#include <string>
#include <iostream>

#include "ATarget.hpp"


using std::string;

class TargetGenerator
{
	private:
	std::map<string, ATarget *> _book;

	TargetGenerator(const TargetGenerator &o);
	TargetGenerator & operator=(const TargetGenerator &o);

	public:
	TargetGenerator() {}

	void learnTargetType(ATarget * target)
	{
		if (target)
			_book[target->getType()] = target->clone();
	}

	void forgetTargetType(const string &target)
	{
		if (_book.find(target) == _book.end())
			return ;
		delete _book[target];
		_book.erase(target);
	}

	ATarget * createTarget(const string &target)
	{
		if (_book.find(target) == _book.end())
			return NULL;
		return _book[target]->clone();
	}
};
