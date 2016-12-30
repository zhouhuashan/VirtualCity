#include "stdafx.h"
#include "ClickHistory.h"

using namespace std;

/** Constructor */
CClickHistory::CClickHistory()
{
}

/** Destructory */
CClickHistory::~CClickHistory()
{
}

/**
* Add a new tile click to the history.
*
* Only the most recent click is retained
* \param tile Tile to add
* \param time Time of the click
*/
void CClickHistory::Add(std::shared_ptr<CTile> tile, time_t time)
{
	// Only allow tile to be in the list one time
	Remove(tile);

	auto click = make_shared<Click>(tile, time);
	click->mNext = mHead;
	mHead = click;
}

/**
* Remove a tile from the history
* \param tile Tile to remove
* \returns true if Tile existed and was removed
*/
bool CClickHistory::Remove(std::shared_ptr<CTile> tile)
{
	std::shared_ptr<Click> prev;    // Item before current item
	auto curr = mHead;              // Current item

	while (curr != nullptr)
	{
		if (curr->GetTile() == tile)
		{
			// We have found the tile we need to remove
			if (prev == nullptr)
			{
				// We are removing from the head of the list
				mHead = curr->mNext;
			}
			else
			{
				// We are removing from inside the list
				prev->mNext = curr->mNext;
			}

			curr->mNext = nullptr;
			return true;    // Successful
		}

		prev = curr;
		curr = curr->mNext;
	}

	return false;
}

/**
* Clear the click history
*/
void CClickHistory::Clear()
{
	mHead = nullptr;
}

/**
* Constructor
* @param tile Tile we are adding history on
* @param time Time we clicked on the tile
*/
CClickHistory::Click::Click(std::shared_ptr<CTile> tile, time_t time) : mTile(tile), mTime(time)
{
}

/** Destructor */
CClickHistory::Click::~Click()
{
}