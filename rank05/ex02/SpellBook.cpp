/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:19:07 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 12:23:25 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"
#include "ASpell.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "SpellBook.hpp"

SpellBook::SpellBook() {};
SpellBook::SpellBook(const SpellBook &other) { (void)other; }
SpellBook &SpellBook::operator=(const SpellBook &other) { (void)other; return *this; }

SpellBook::~SpellBook() {}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		_spells[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(const std::string &spell)
{
	if (_spells.find(spell) == _spells.end())
		return;
	delete _spells.find(spell)->second;
	_spells.erase(_spells.find(spell));
}

ASpell * SpellBook::createSpell(const std::string &spell) const
{
	if (_spells.find(spell) == _spells.end())
		return NULL;
	return _spells.find(spell)->second->clone();
}
