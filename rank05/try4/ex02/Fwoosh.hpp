#pragma once

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	public:
	Fwoosh() : ASpell("Fwoosh", "Fwooshed") {}
	~Fwoosh() {}

	ASpell *clone() const { return new Fwoosh(); }
};
