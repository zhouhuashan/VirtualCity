/**
* \file ClickHistory.h
*
* \author Charles Owen
*
* Class that keeps track of the history of clicks on city tiles
*/

#pragma once
#include "Click.h"

/**
* Class that keeps track of the history of clicks on city tiles
*/
class CClickHistory
{
public:
	CClickHistory();
	virtual ~CClickHistory();

	void Add(std::shared_ptr<CTile> tile, time_t time);
	bool Remove(std::shared_ptr<CTile> tile);
	void Clear();

protected:
	/**
	* Nested class that actually stores the click history items
	*/
	class Click : public CClick
	{
	public:
		Click(std::shared_ptr<CTile> tile, time_t time);
		virtual ~Click();

		/**
		* Get the tile we clicked on
		* \returns CTile object pointer
		*/
		std::shared_ptr<CTile> GetTile() { return mTile; }

		/**
		* Get the time this click occurred
		* \returns Time as a long long value (seconds since 1970)
		*/
		time_t GetTime() { return mTime; }

		/// Pointer to next click in linked list
		std::shared_ptr<Click> mNext;

		/// Pointer to a tile
		std::shared_ptr<CTile> mTile;

		/// Click time
		time_t mTime = 0;
	};

	/// Pointer to head of linked list of clicks
	std::shared_ptr<Click> mHead;

public:

	/**
	  * iterator that iterates over the collection of history
	*/
	class Iter
	{
	public:

			/** Constructor
			  * \param history
			  * \param pos a pointer 
			*/
		Iter(CClickHistory *history, std::shared_ptr<Click> pos) : mHistory(history), mCurrentItem(pos) {}

		/** Test for the end of the iterator
		  * \param &other iterator
		  * \return true or false Boolean 
		  */
		bool operator != (const Iter &other) const
		{
			return  mCurrentItem != other.mCurrentItem;
		}


		/** Get value at current position
		* \returns mCurrentItem at the index in the collection
		*/
		std::shared_ptr<Click> operator *() { return mCurrentItem; }



		/** Increment the iterator
		* \returns reference to this iterator
		*/
		const Iter& operator++()
		{
			if (mCurrentItem != nullptr)
			{
				mCurrentItem = mCurrentItem->mNext;
			}
			return *this;
		}


	private:
		CClickHistory *mHistory;  ///< history we want to iterate through
		std::shared_ptr<Click> mCurrentItem; ///< pointer to the index of the list 

	};


	/** function that begins
	  * \returns iterator
	  */
	Iter begin() { return Iter(this, mHead); }
	
	/** function that ends
	  * \returns iterator
	  */
	Iter end() { return Iter(this, nullptr); }

};

