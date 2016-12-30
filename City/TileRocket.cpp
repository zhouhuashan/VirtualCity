#include "stdafx.h"
#include "TileRocket.h"


using namespace std;
using namespace Gdiplus;

/// image of background for launcher
const wstring LauncherBackgroundImage = L"rocketB.png";

/// image of the rocket itself
const wstring RocketShipImage = L"rocket.png";

/// rocket launcher foreground
const wstring  LauncherForegroundImage = L"rocketF.png";

/// How much we offset drawing the tile to the left of the center
const int OffsetLeft = 64;

/// How much we offset drawing the tile above the center
const int OffsetDown = 32;

///Constant pixels per second flgiht speed
const int SpeedY = 60;

/** Constructor
* \param city The city this is a member of
*/
CTileRocket::CTileRocket(CCity *city) : CTile(city)
{
	SetImage(LauncherBackgroundImage);
	LoadImage(mRocketShipImage, RocketShipImage);
	LoadImage(mLauncherImage, LauncherForegroundImage);
}

/**
*  Destructor
*/
CTileRocket::~CTileRocket()
{
	
}




/**
* Load an image into a bitmap
* \param image Image pointer to load
* \param name Filename to load from
*/
void CTileRocket::LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name)
{
	wstring filename = ImagesDirectory + name;
	image = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (image->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}





/** Draw this item
* \param graphics The graphics context to draw on */
void CTileRocket::Draw(Gdiplus::Graphics *graphics)
{
	CTile::Draw(graphics);


	if (mState == Loaded)
	{
		int wid = mRocketShipImage->GetWidth();
		int hit = mRocketShipImage->GetHeight();

		graphics->DrawImage(mRocketShipImage.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
			wid, hit);


		wid = mLauncherImage->GetWidth();
		hit = mLauncherImage->GetHeight();

		graphics->DrawImage(mLauncherImage.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
			wid, hit);

	}	
	else if (mState == Launching)
	{
	

		int wid = mRocketShipImage->GetWidth();
		int hit = mRocketShipImage->GetHeight();

		graphics->DrawImage(mRocketShipImage.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit - mRocketY),
			wid, hit);


		graphics->DrawImage(mLauncherImage.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
			wid, hit);

	}

	if (GetY() - mRocketY < 0)
	{
		mState = Empty;
		mRocketY = 0;
	}


}





/**  Save this item to an XML node
* \param node The node we are going to be a child of
* \returns Allocated node
*/
std::shared_ptr<xmlnode::CXmlNode> CTileRocket::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CTile::XmlSave(node);

	itemNode->SetAttribute(L"type", L"rocket");
	itemNode->SetAttribute(L"file", GetFile());

	return itemNode;
}




/**
* brief Load the attributes for an item node.
* \param node The Xml node we are loading the item from
*/
void CTileRocket::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	CTile::XmlLoad(node);
	SetImage(node->GetAttributeValue(L"file", L""));
}






/**
* Called before the image is drawn
* \param elapsed Time since last draw
*/


void CTileRocket::Update(double elapsed)
{
	CTile::Update(elapsed);


	if (mState == Launching)
	{
		// when the rocket is flying...
		// SpeedY is a constant pixels per second flight speed...
		mRocketY += SpeedY * elapsed;
	}
}