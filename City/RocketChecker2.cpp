/**
* \file RocketChecker.cpp
*
* \author Cyndy Ishida
*
* implementation of launch rocket visitor
*/






#include "stdafx.h"
#include "RocketChecker2.h"

/** Constructor*/
CRocketChecker2::CRocketChecker2()
{
}


/** Destructor*/
CRocketChecker2::~CRocketChecker2()
{
}

/**
  * \param rocket the rocket thats being visited
  */
void CRocketChecker2::VisitRocket(CTileRocket *rocket)
{
	rocket->LaunchState();
}