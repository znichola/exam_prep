#pragma once

#include <map>
#include <string>
#include <iostream>

#include "ASpell.hpp"
#include "ATarget.hpp"

using std::string;
using std::cout;
using std::endl;

class Warlock
{
	private:
	string _name;
	string _title;
	std::map<string, ASpell *> _book;

	Warlock() {}
	Warlock(const Warlock &o);
	Warlock & operator=(const Warlock &o);

	public:
	~Warlock()
	{ cout << _name << ": My job here is done!" << endl; }

	Warlock(const string name, const string title) : _name(name), _title(title)
	{ cout << _name << ": This looks like another boring day." << endl; }

	const string &getName() const { return _name; }
	const string &getTitle() const { return _title; }

	void setTitle(const string title) { _title = title; }

	void introduce() const
	{ cout << _name << ": I am " << _name << ", " << _title << "!" << endl; }

	void learnSpell(ASpell * spell)
	{
		if (spell)
			_book[spell->getName()] = spell->clone();
	}

	void forgetSpell(const string &spell)
	{
		if (_book.find(spell) == _book.end())
			return ;
		delete _book[spell];
		_book.erase(spell);
	}

	void launchSpell(const string &spell, const ATarget &target)
	{
		if (_book.find(spell) == _book.end())
			return ;
		_book[spell]->launch(target);
	}
};
