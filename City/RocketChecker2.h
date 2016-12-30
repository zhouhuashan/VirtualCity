/**
* \file BuildingCounter.h
*
* \author Cyndy Ishida
*
* header file Launch Rocket Checker
*/




#pragma once
#include "TileVisitor.h"
#include "TileRocket.h"

/** Class rocket checker 
 * derived from tile visitor*/
class CRocketChecker2 :
	public CTileVisitor
{
public:
	CRocketChecker2();
	virtual ~CRocketChecker2();
	void VisitRocket(CTileRocket * rocket);
};

