/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 08:59:45 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 12:01:41 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"
#include "ASpell.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "Warlock.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const ASpell &other) :
	_name(other._name),
	_effects(other._effects)
	{}
ASpell::~ASpell() {}

ASpell::ASpell(const std::string &name, const std::string &effects) :
	_name(name),
	_effects(effects)
	{}

ASpell &ASpell::operator=(const ASpell &other)
{
	_name = other._name;
	_effects = other._effects;
	return *this;
}

const std::string &ASpell::getName() const { return _name; }
const std::string &ASpell::getEffects() const { return _effects; }

void ASpell::launch(const ATarget &target) const { target.getHitBySpell(*this); }
