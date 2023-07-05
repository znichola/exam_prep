/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:09:22 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 18:49:52 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include <map>
#include <string>
#include <iostream>

#include "ATarget.hpp"

class TargetGenerator
{
	private:
	TargetGenerator(const TargetGenerator &other);
	TargetGenerator &operator=(const TargetGenerator &other);

	std::map<std::string, ATarget*> _targets;

	public:
	~TargetGenerator();
	TargetGenerator();

	//targets
	void learnTargetType(ATarget *target);
	void forgetTargetType(const std::string &target);
	ATarget *createTarget(const std::string &target) const;
};

#endif
