/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 08:37:49 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 11:45:25 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"
#include "ASpell.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "Warlock.hpp"

Warlock::Warlock() {};
Warlock::Warlock(const Warlock &other) { (void)other; }
Warlock &Warlock::operator=(const Warlock &other) { (void)other; return *this; }

Warlock::Warlock(const std::string &name, const std::string &title) :
	_name(name),
	_title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" <<  std::endl;
}

const std::string &Warlock::getName() const { return _name; }
const std::string &Warlock::getTitle() const { return _title; }

void Warlock::setTitle(const std::string &title) { _title = title; };

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << " !" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
		_spells[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(const std::string &spell)
{
	if (_spells.find(spell) == _spells.end())
		return;
	delete _spells.find(spell)->second;
	_spells.erase(_spells.find(spell));
}

void Warlock::launchSpell(const std::string &spell, const ATarget &target) const
{
	if (_spells.find(spell) == _spells.end())
	{
		std::cout << "spell not found\n";
		return;
	}
	_spells.find(spell)->second->launch(target);
}
