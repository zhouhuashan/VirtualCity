/**
* \file BuildingCounter.h
*
* \author Cyndy Ishida
*
* header file of base class 
*/


#pragma once
#include "TileVisitor.h"


/** Class building counter 
 * derived from tile visitor
 */
class CBuildingCounter :
	public CTileVisitor
{
public:
	CBuildingCounter();
	virtual ~CBuildingCounter();

	void VisitBuilding(CTileBuilding * building);


	/** Get the number of buildings
	* \returns Number of buildings */
	int GetNumBuildings() const { return mNumBuildings; }

private:
	/// Buildings counter
	int mNumBuildings = 0;
};

