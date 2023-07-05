#pragma once

#include <string>
#include <iostream>

#include "ASpell.hpp"


using std::string;

class SpellBook
{
	private:
	std::map<string, ASpell *> _book;

	SpellBook(const SpellBook &o);
	SpellBook & operator=(const SpellBook &o);

	public:
	SpellBook() {}

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

	ASpell * createSpell(const string &spell)
	{
		if (_book.find(spell) == _book.end())
			return NULL;
		return _book[spell]->clone();
	}
};
