/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 08:59:56 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 11:08:14 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <string>

class ATarget;
class ASpell;
class Dummy;
class Fwoosh;
class Warlock;

class ASpell
{
	protected:
	std::string _name;
	std::string _effects;

	public:
	ASpell();
	ASpell(const std::string &name, const std::string &effects);
	virtual ~ASpell();
	ASpell(const ASpell &other);
	ASpell &operator=(const ASpell &other);
	//getters
	const std::string &getName() const;
	const std::string &getEffects() const;

	//funs
	void launch(const ATarget &target) const;

	//pure method
	virtual ASpell *clone() const = 0;
};

#endif
