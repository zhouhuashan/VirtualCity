/**
* \file TileVisitor.h
*
* \author Cyndy Ishida
*
* Tile visitor base class.
*/


#pragma once

// Forward references to all tile types
class CTileBuilding;
class CTileCoalmine;
class CTileLandscape;
class CTileRoad;
class CTileRocket;

/** Tile visitor base class */
class CTileVisitor
{
public:
	CTileVisitor();
	virtual ~CTileVisitor();

	/** Visit a CTileBuilding object
	* \param building Building we are visiting */
	virtual void VisitBuilding(CTileBuilding *building) {}

	/** Visit a CTileCoalmine object
	* \param coalmine Coal mine we are visiting */
	virtual void VisitCoalmine(CTileCoalmine *coalmine) {}

	/** Visit a CTileLandscape object
	* \param landscape Landscape tile we are visiting */
	virtual void VisitLandscape(CTileLandscape *landscape) {}

	/** Visit a CTileRoad object
	* \param road Road we are visiting */
	virtual void VisitRoad(CTileRoad *road) {}


	/** Visit a CTileRocket object
	* \param rocket we are visiting */
	virtual void VisitRocket(CTileRocket *rocket) {}
};