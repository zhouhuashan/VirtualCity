/**
* \file RocketChecker.cpp
*
* \author Cyndy Ishida
*
* implementation of load rocket visitor
*/





#include "stdafx.h"
#include "RocketChecker.h"


/** constructor */
CRocketChecker::CRocketChecker()
{
}

/** destructor */
CRocketChecker::~CRocketChecker()
{
}


/** visitor pattern implementor
  * \param rocket a pointer to a rocket*/
void CRocketChecker::VisitRocket(CTileRocket *rocket)
{
	rocket->LoadState();
}