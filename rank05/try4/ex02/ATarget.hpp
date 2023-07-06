#pragma once

#include <string>

using std::string;

class ASpell;

class ATarget
{
	private:
	string _type;

	public:
	ATarget() {}
	ATarget(const ATarget &o) : _type(o._type) {}
	ATarget & operator=(const ATarget &o) { _type = o._type; return *this; }

	ATarget(const string &type) : _type(type) {}

	const string & getType() const { return _type; }

	virtual ~ATarget() {}
	virtual ATarget * clone() const = 0;

	void getHitBySpell(const ASpell &spell) const;
};

#include "ASpell.hpp"
