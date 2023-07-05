#pragma once

#include <string>
#include <map>

using std::string;

#include "ATarget.hpp"

class TargetGenerator
{
	private:
	std::map<string, ATarget *> _book;

	TargetGenerator(const TargetGenerator &o);
	TargetGenerator & operator=(const TargetGenerator &o);

	public:
	TargetGenerator() {}
	~TargetGenerator() {}

	void learnTargetType(ATarget * target)
	{
		_book[target->getType()] = target->clone();
	}

	void forgetTargetType(const string &name)
	{
		if (_book.find(name) == _book.end())
			return ;
		delete _book[name];
		_book.erase(name);
	}

	ATarget * createTarget(const string &name)
	{
		if (_book.find(name) == _book.end())
			return NULL;
		return _book[name]->clone();
	}
};
