/**
* \file TileRocket.h
*
* \author Cyndy	Ishida
*
*  Class that implements a rocket tile
*/






#pragma once


#include "Tile.h"
#include "TileVisitor.h"


/** A tile rocket 
*/
class CTileRocket :
	public CTile
{
public:

	/// default constructor (disabled)
	CTileRocket()= delete;

	/// copy constructor (disabled)
	CTileRocket(const CTileRocket &) = delete;

	CTileRocket(CCity * city);

	~CTileRocket();

	void LoadImage(std::unique_ptr<Gdiplus::Bitmap>& image, std::wstring name);




	void Draw(Gdiplus::Graphics * graphics);

	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node);

	void Update(double elapsed);

	/** changes the empty state to loaded*/
	void LoadState() { mState = Loaded; }


	/** setter for launch state */
	void LaunchState() { mState = Launching;  }


	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CTileVisitor *visitor) override { visitor->VisitRocket(this); }

	/// options the state the rocket can  be at.
	enum States { Empty, Loaded, Launching };
	
	/** getter for state of rocket
	  * \return mState 
	  */
	States State() { return mState; };

private: 
	/// state of the rocket
	States mState = Empty;

	/// image pointer for rocket
	std::unique_ptr<Gdiplus::Bitmap> mRocketShipImage;

	/// image pointer for launcher image
	std::unique_ptr<Gdiplus::Bitmap> mLauncherImage;

	/// distance of rocket mRocketY
	double mRocketY = 0;

};

