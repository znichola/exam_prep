/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 08:37:42 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 11:16:13 by znichola         ###   ########.fr       */
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

class Warlock
{
	private:
	Warlock();
	Warlock(const Warlock &other);
	Warlock &operator=(const Warlock &other);

	std::string _name;
	std::string _title;
	std::map<std::string, ASpell*> _spells;

	public:
	~Warlock();
	Warlock(const std::string &name, const std::string &title);

	// getters
	const std::string &getName() const;
	const std::string &getTitle() const;

	// setters
	void setTitle(const std::string &title);

	//funcs
	void introduce() const;

	//spells
	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &spell);
	void launchSpell(const std::string &spell, const ATarget &target) const;
};

#endif
