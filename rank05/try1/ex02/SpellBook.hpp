/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:08:43 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 12:21:16 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>

class ATarget;
class ASpell;
class Dummy;
class Fwoosh;
class Warlock;

class SpellBook
{
	private:
	SpellBook(const SpellBook &other);
	SpellBook &operator=(const SpellBook &other);

	std::map<std::string, ASpell*> _spells;

	public:
	~SpellBook();
	SpellBook();

	//spells
	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &spell);
	ASpell *createSpell(const std::string &spell) const;
};

#endif
