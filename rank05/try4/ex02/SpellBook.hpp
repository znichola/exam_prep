#pragma once

#include <string>
#include <map>

using std::string;

#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook
{
	private:
	std::map<string, ASpell *> _book;

	SpellBook(const SpellBook &o);
	SpellBook & operator=(const SpellBook &o);

	public:
	SpellBook() {};
	~SpellBook() {};

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

	ASpell * createSpell(const string &name)
	{
		if (_book.find(name) == _book.end())
			return NULL;
		return _book[name]->clone();
	}
};
