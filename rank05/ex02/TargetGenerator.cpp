/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:13:03 by znichola          #+#    #+#             */
/*   Updated: 2023/07/05 13:16:54 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"
#include "BrickWall.hpp"
#include "Dummy.hpp"

TargetGenerator::TargetGenerator() {};
TargetGenerator::TargetGenerator(const TargetGenerator &other) { (void)other; }
TargetGenerator &TargetGenerator::operator=(const TargetGenerator &other) { (void)other; return *this; }

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
		_targets[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(const std::string &target)
{
	if (_targets.find(target) == _targets.end())
		return;
	delete _targets.find(target)->second;
	_targets.erase(_targets.find(target));
}

ATarget * TargetGenerator::createTarget(const std::string &target) const
{
	if (_targets.find(target) == _targets.end())
		return NULL;
	return _targets.find(target)->second->clone();
}
