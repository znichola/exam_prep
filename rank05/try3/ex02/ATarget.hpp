#pragma once

#include <string>
#include <iostream>

using std::string;

class ASpell;

class ATarget
{
	protected:
	string _type;

	public:
	ATarget() {};
	ATarget(const ATarget &o) : _type(o._type) {}
	ATarget(const string &type) : _type(type) {}

	ATarget & operator=(const ATarget &o) { _type = o._type; return *this; }

	const string getType() const { return _type; }

	virtual ~ATarget() {};
	virtual ATarget * clone() const = 0;

	void getHitBySpell(const ASpell &spell) const;

};

#include "ASpell.hpp"
