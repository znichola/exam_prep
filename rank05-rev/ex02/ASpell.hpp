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

	ASpell() {}

	ASpell(const ASpell &o) : _name(o._name), _effects(o._effects) {}

	ASpell & operator=(const ASpell &o) { _name = o._name; _effects = o._effects; return *this; }

	ASpell(const string name, const string effects) : _name(name), _effects(effects) {}

	virtual ~ASpell() {}

	virtual ASpell *clone() const = 0;

	const string & getName() const { return _name; }
	const string & getEffects() const { return _effects; }

	void launch(const ATarget &target) const;

};

#include "ATarget.hpp"
