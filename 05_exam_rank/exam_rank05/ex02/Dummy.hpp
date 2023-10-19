#pragma once
#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "ATarget.hpp"

class ATarget;

class Dummy : public ATarget
{
	public:
	Dummy();
	virtual ~Dummy();
	virtual ATarget* clone() const;
};

#endif
