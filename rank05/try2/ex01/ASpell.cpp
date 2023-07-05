#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const ASpell &o) : _name(o._name), _effects(o._effects) {}

ASpell & ASpell::operator=(const ASpell &o) { _name = o._name; _effects = o._effects; return *this; }

ASpell::ASpell(const string name, const string effects) : _name(name), _effects(effects) {}

ASpell::~ASpell() {}

const string & ASpell::getName() const { return _name; }
const string & ASpell::getEffects() const { return _effects; }

void ASpell::launch(const ATarget &target) const { target.getHitBySpell(*this); }
