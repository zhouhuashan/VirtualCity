

/**
* \file MenuVisitor.h
*
* \author Cyndy Ishida
*
* header of load menu visitor
*/


#pragma once

#include "TileVisitor.h"
#include "TileRocket.h"


/**
  * Class Menu Visitor
  *
  * derived from tile visitor
  */
class CMenuVisitor :
	public CTileVisitor
{
public:
	CMenuVisitor();
	virtual ~CMenuVisitor();

	/** getter 
	 * \returns mNumEmpty
	 */
	int getEmpty() const { return mNumEmpty; }
	
	/** getter
	* \returns mNumLoad
	*/
	int getLoader() const { return mNumLoad; }

	void VisitRocket(CTileRocket *rocket);

private:

	/// number of empty rockets
	int mNumEmpty = 0;

	/// number of loaded rockets
	int mNumLoad = 0;
};


