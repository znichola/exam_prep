#pragma once

#include <map>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class ASpell;

class ATarget
{
	protected:
	string _type;

	public:
	ATarget();
	ATarget(const ATarget &o);
	ATarget & operator=(const ATarget &o);

	ATarget(const string &type);

	const string &getType() const;

	virtual ~ATarget();
	virtual ATarget *clone() const = 0;

	void getHitBySpell(const ASpell &spell) const;
};

#include "ASpell.hpp"
