#pragma once

#include <map>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class ATarget;

class ASpell
{
	protected:
	string _name;
	string _effects;

	public:

	ASpell();
	ASpell(const ASpell &o);
	ASpell & operator=(const ASpell &o);

	ASpell(const string name, const string effects);

	virtual ~ASpell();
	virtual ASpell *clone() const = 0;

	const string & getName() const;
	const string & getEffects() const;

	void launch(const ATarget &target) const;

};

#include "ATarget.hpp"
