#pragma once

#include <map>
#include <string>
#include <iostream>

#include "ASpell.hpp"
#include "ATarget.hpp"

#include "SpellBook.hpp"

using std::string;
using std::cout;
using std::endl;

class Warlock
{
	private:
	string _name;
	string _title;
	SpellBook _book;

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
		_book.learnSpell(spell);
	}

	void forgetSpell(const string &spell)
	{
		_book.forgetSpell(spell);
	}

	void launchSpell(const string &spell, const ATarget &target)
	{
		ASpell *s = _book.createSpell(spell);
		if (!s)
			return;
		s->launch(target);
		delete s;
	}
};
