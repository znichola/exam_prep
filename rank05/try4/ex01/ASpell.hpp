#pragma once

#include <string>

using std::string;

class ATarget;

class ASpell
{
	private:
	string _name;
	string _effects;


	public:
	ASpell() {}
	ASpell(const ASpell &o) : _name(o._name), _effects(o._effects) {}
	ASpell & operator=(const ASpell &o) { _name = o._name; _effects = o._effects; return *this; }

	ASpell(const string &name, const string &effects) : _name(name), _effects(effects) {}

	const string & getName() const { return _name; }
	const string & getEffects() const { return _effects; }

	virtual ~ASpell() {}
	virtual ASpell * clone() const = 0;

	void launch(const ATarget &target) const;
};


#include "ATarget.hpp"
