/**
* \file BuildingCounter.h
*
* \author Cyndy Ishida
*
* header file Load Rocket Checker
*/


#pragma once
#include "TileVisitor.h"
#include "TileRocket.h"



/** class for rocket checker
  * derived from tile visitor 
  */
class CRocketChecker :
	public CTileVisitor
{
public:
	CRocketChecker();
	virtual ~CRocketChecker();

	void VisitRocket(CTileRocket *rocket);
};

