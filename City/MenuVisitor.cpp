/**
* \file MenuVisitor.cpp
*
* \author Cyndy Ishida
*
* implementation of load menu visitor
*/



#include "stdafx.h"
#include "MenuVisitor.h"
#include "TileRocket.h"

/**Constructor*/
CMenuVisitor::CMenuVisitor()
{
}

/** Destructor*/
CMenuVisitor::~CMenuVisitor()
{
}


/** function that visits rocket
  * \param rocket
  */
void CMenuVisitor::VisitRocket(CTileRocket *rocket)
{
	if (rocket->State() == CTileRocket::States::Empty)
	{
		mNumEmpty++;
	}
	else if (rocket->State() == CTileRocket::States::Loaded)
	{
		mNumLoad++;
	}
}
