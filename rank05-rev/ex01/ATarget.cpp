#include "ATarget.hpp"

ATarget::ATarget() {}
ATarget::ATarget(const ATarget &o) : _type(o._type) {}
ATarget & ATarget::operator=(const ATarget &o) { _type = o._type; return *this; }

ATarget::ATarget(const string &type) : _type(type) {}

const string & ATarget::getType() const { return _type; }

ATarget::~ATarget() {}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	cout << _type << " has been " << spell.getEffects() << "!" << endl;
}
