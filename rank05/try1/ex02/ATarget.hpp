/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:22:07 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 11:11:34 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <string>

class ATarget;
class ASpell;
class Dummy;
class Fwoosh;
class Warlock;

class ATarget
{
	protected:
	std::string _type;

	public:
	ATarget();
	ATarget(const std::string &type);
	virtual ~ATarget();
	ATarget(const ATarget &other);
	ATarget &operator=(const ATarget &other);

	//getters
	const std::string &getType() const;

	//pure method
	virtual ATarget *clone() const = 0;

	void getHitBySpell(const ASpell &spell) const;
};

#endif
