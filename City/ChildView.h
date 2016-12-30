/**
* \file ChildView.h
*
* \author Charles B. Owen
*
*  Class that implements the child window our program draws in.
*
* The window is a child of the main frame, which holds this
* window, the menu bar, and the status bar.
*/

#pragma once

#include "City.h"
#include "ClickHistory.h"

class CTile;

/**  The child window our program draws in. */
class CChildView : public CWnd
{
	// Construction
public:
	CChildView();

	// Attributes
public:

	// Operations
public:

	// Overrides
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

private:
	void AddBuilding(const std::wstring &file);
	void AddLandscape(const std::wstring &file);


	/// The city
	CCity   mCity;

	/// True until the first time we draw
	bool mFirstDraw = true;

	long long mLastTime;    ///< Last time we read the timer
	double mTimeFreq;       ///< Rate the timer updates

							/// Any item we are currently dragging
	std::shared_ptr<CTile> mGrabbedItem;

	std::unique_ptr<Gdiplus::Bitmap> mTrashcan; ///< Trashcan image to use
	int mTrashcanTop = 0;           ///< Top line of the trashcan in pixels
	int mTrashcanRight = 0;         ///< Right side of the trashcan in pixels

									/// History of mouse clicks
	CClickHistory mHistory;

	/// boolean that when true, tells onpaint to add the number of hits to a object
	bool mShowHistory = false;
public:
	afx_msg BOOL OnEraseBkgnd(CDC *pDC);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnFileOpen();
	afx_msg void OnFileSaveas();

	/** \cond */
	afx_msg void OnBuildingsFarmhouse();
	afx_msg void OnLandscapingGrass();
	afx_msg void OnLandscapingSpartystatue();
	afx_msg void OnBuildingsBlacksmithshop();
	afx_msg void OnLandscapingTallgrass();
	afx_msg void OnBuildingsBrownhouse();
	afx_msg void OnBuildingsYellowhouse();
	afx_msg void OnBuildingsF();
	afx_msg void OnBuildingsHospital();
	afx_msg void OnBuildingsMarket();
	afx_msg void OnBuildingsCondos();
	afx_msg void OnLandscapingTree();
	afx_msg void OnLandscapingTrees();
	afx_msg void OnLandscapingBigtrees();
	afx_msg void OnLandscapingRoad();
	afx_msg void OnBusinessesCoalmine();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnViewHistory();
	afx_msg void OnUpdateViewHistory(CCmdUI *pCmdUI);
	afx_msg void OnBuildingsCount();
	afx_msg void OnSpaceRocket();
	afx_msg void OnSpaceLoad();
	afx_msg void OnSpaceLaunch();
	afx_msg void OnUpdateSpaceLoad(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSpaceLaunch(CCmdUI *pCmdUI);
	/** \endcond */
};

