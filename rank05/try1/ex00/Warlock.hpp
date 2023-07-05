/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 08:37:42 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 08:56:45 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_H
# define WARLOCK_H

#include <iostream>
#include <string>

class Warlock
{
	private:
	Warlock();
	Warlock(const Warlock &other);
	Warlock &operator=(const Warlock &other);
	std::string _name;
	std::string _title;

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
};

#endif
