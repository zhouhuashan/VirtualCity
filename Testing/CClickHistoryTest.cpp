#include "stdafx.h"
#include "CppUnitTest.h"
#include "ClickHistory.h"
#include "City.h"
#include "TileRoad.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	/** Testing stub class, creates a vector from
	* the list. This is done so we can test this
	* before we create the iterator. DO NOT USE
	* THIS CODE to solve the iterator task */
	class CClickHistoryStub : public CClickHistory
	{
	public:
		std::vector<std::shared_ptr<CClick>> GetClicks()
		{
			std::vector<std::shared_ptr<CClick>> list;
			auto ptr = mHead;
			while (ptr != nullptr)
			{
				list.push_back(ptr);
				ptr = ptr->mNext;
			}

			return list;
		}
	};

	TEST_CLASS(CClickHistoryTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCClickHistoryAdd)
		{
			CCity city;
			CClickHistoryStub history;

			// Ensure the list is initially empty
			auto list = history.GetClicks();
			Assert::AreEqual(0, (int)list.size());

			// Test with one item in the list
			auto time1 = time(nullptr) + 15;
			auto tile1 = AddToCity(&city);
			history.Add(tile1, time1);

			list = history.GetClicks();
			Assert::AreEqual(1, (int)list.size());
			Assert::IsTrue(time1 == list[0]->GetTime());
			Assert::IsTrue(tile1 == list[0]->GetTile());

			// Test with two items in the list
			auto time2 = time1 + 5;
			auto tile2 = AddToCity(&city);
			history.Add(tile2, time2);

			list = history.GetClicks();
			Assert::AreEqual(2, (int)list.size());
			Assert::IsTrue(time2 == list[0]->GetTime());
			Assert::IsTrue(tile2 == list[0]->GetTile());
			Assert::IsTrue(time1 == list[1]->GetTime());
			Assert::IsTrue(tile1 == list[1]->GetTile());

			// Test with a remove
			auto time3 = time2 + 177;
			history.Add(tile1, time3);

			list = history.GetClicks();
			Assert::AreEqual(2, (int)list.size());
			Assert::IsTrue(time3 == list[0]->GetTime());
			Assert::IsTrue(tile1 == list[0]->GetTile());
			Assert::IsTrue(time2 == list[1]->GetTime());
			Assert::IsTrue(tile2 == list[1]->GetTile());
		}

		TEST_METHOD(TestCClickHistoryRemove)
		{
			CCity city;
			CClickHistoryStub history;

			// Create some tiles
			auto time1 = time(nullptr) + 15;
			auto tile1 = AddToCity(&city);
			auto time2 = time1 + 5;
			auto tile2 = AddToCity(&city);
			auto time3 = time2 + 17;
			auto time4 = time3 + 83;
			auto tile3 = AddToCity(&city);
			auto tile4 = AddToCity(&city);

			// Remove when the list is empty should return false
			Assert::IsFalse(history.Remove(tile1));

			// Try removing when only one thing in the list
			history.Add(tile1, time1);
			Assert::IsTrue(history.Remove(tile1));
			Assert::AreEqual(0, (int)history.GetClicks().size());

			// Add three to list
			history.Add(tile1, time1);
			history.Add(tile2, time2);
			history.Add(tile3, time3);

			// Order in the list: 3, 2, 1

			// Remove if not found should return false
			Assert::IsFalse(history.Remove(tile4));

			// Try removing the list head
			Assert::IsTrue(history.Remove(tile3));
			auto list = history.GetClicks();
			Assert::AreEqual(2, (int)list.size());
			Assert::IsTrue(tile2 == list[0]->GetTile());
			Assert::IsTrue(tile1 == list[1]->GetTile());

			// Try removing the list tail
			history.Add(tile3, time3);
			// Order in the list: 3, 2, 1

			Assert::IsTrue(history.Remove(tile1));
			list = history.GetClicks();
			Assert::AreEqual(2, (int)list.size());
			Assert::IsTrue(tile3 == list[0]->GetTile());
			Assert::IsTrue(tile2 == list[1]->GetTile());

			// Try removing in the middle
			history.Add(tile1, time4);
			// Order in the list: 1, 3, 2
			Assert::IsTrue(history.Remove(tile3));
			list = history.GetClicks();
			Assert::IsTrue(tile1 == list[0]->GetTile());
			Assert::IsTrue(tile2 == list[1]->GetTile());
		}



		/** tests to see if iterator class in click history works
		*/
		TEST_METHOD(TestCClickHistoryIterator)
		{
			CCity city;
			CClickHistory history;

			//
			// Ensure the iterator indicates initially empty
			//
			auto iter = history.begin();
			auto end = history.end();
			Assert::IsFalse(iter != end);

			//
			// Test with one item in the list
			//
			auto time1 = time(nullptr) + 15;
			auto tile1 = AddToCity(&city);
			history.Add(tile1, time1);

			iter = history.begin();
			end = history.end();
			Assert::IsTrue(iter != end);
			Assert::IsTrue((*iter)->GetTile() == tile1);

			++iter;
			Assert::IsFalse(iter != end);

			//
			// Test with two items in the list
			//
			auto time2 = time1 + 83;
			auto tile2 = AddToCity(&city);
			history.Add(tile2, time2);

			iter = history.begin();
			end = history.end();
			Assert::IsTrue(iter != end);
			Assert::IsTrue((*iter)->GetTile() == tile2);

			++iter;
			Assert::IsTrue(iter != end);
			Assert::IsTrue((*iter)->GetTile() == tile1);

			++iter;
			Assert::IsFalse(iter != end);

			//
			// Test with three items in the list
			//
			auto time3 = time2 + 99;
			auto tile3 = AddToCity(&city);
			history.Add(tile3, time3);

			iter = history.begin();
			end = history.end();
			Assert::IsTrue(iter != end);
			Assert::IsTrue((*iter)->GetTile() == tile3);

			++iter;
			Assert::IsTrue(iter != end);
			Assert::IsTrue((*iter)->GetTile() == tile2);

			++iter;
			Assert::IsTrue(iter != end);
			Assert::IsTrue((*iter)->GetTile() == tile1);

			++iter;
			Assert::IsFalse(iter != end);
		}



		/** Convenience function that creates a single tile and adds it to the city.
		* \param city City to add to
		* \returns Newly created CTile object */
		std::shared_ptr<CTile> AddToCity(CCity *city)
		{
			auto tile = make_shared<CTileRoad>(city);
			city->Add(tile);
			return tile;
		}

	};





}