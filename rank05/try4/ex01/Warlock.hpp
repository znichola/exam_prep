#pragma once

#include <string>
#include <iostream>
#include <map>

using std::string;
using std::cout;
using std::endl;

#include "ASpell.hpp"
#include "ATarget.hpp"
class Warlock
{
	private:
	string _name;
	string _title;

	std::map<string, ASpell *> _book;

	Warlock();
	Warlock(const Warlock &o);
	Warlock & operator=(const Warlock &o);

	public:
	Warlock(const string &name, const string &title) : _name(name), _title(title)
	{ cout << _name << ": This looks like another boring day." << endl; }

	~Warlock()
	{ cout << _name << ": My job here is done!" << endl; }

	const string & getName() const { return _name; }
	const string & getTitle() const { return _title; }

	void setTitle(const string &title) { _title = title; }

	void introduce() const
	{ cout << _name << ": I am " << _name << ", " << _title << "!" << endl; }

	void learnSpell(const ASpell *spell)
	{
		_book[spell->getName()] = spell->clone();
	}

	void forgetSpell(const string &name)
	{
		if (_book.find(name) == _book.end())
			return ;
		delete _book[name];
		_book.erase(name);
	}

	void launchSpell(const string &name, const ATarget &target)
	{
		if (_book.find(name) == _book.end())
			return ;
		_book[name]->launch(target);
	}

};
