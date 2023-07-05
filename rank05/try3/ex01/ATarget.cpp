#include "ATarget.hpp"

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << _type << " have been " << spell.getEffects() << "!" << std::endl;
}
