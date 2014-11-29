#pragma once

#include <stdexcept>

namespace NobelLib
{
	template<typename Type>
	class List
	{
	private:
		Type* objList = nullptr;
		List* nextList = nullptr;
		bool usedList = false;
		int iList;
		static int totAlloc;
	public:
		List()
		{
			objList = nullptr;
			nextList = nullptr;
			usedList = false;
		}
		List(Type& ptrType)
		{
			addItem(ptrType);
		}
		void addItem(Type& ptrType)
		{
			if (usedList&&nextList != nullptr)
				nextList->addItem(ptrType);
			else if (!usedList)
			{
				objList = new Type(ptrType);
				usedList = true;
				iList = totAlloc;
				totAlloc++;
			}
			else if (nextList == nullptr)
			{
				nextList = new List(ptrType);
			}
		}
		List findIndex(int Index)
		{
			if (iList == Index)
				return *this->objList;
			else
				return nextList->findIndex(Index);
		}

		Type& operator[] (int Index)
		{
			return *findIndex(Index).objList;
		}
		int getLength() { return totAlloc; }
	};

	template<typename Type>
	int List<Type>::totAlloc = 0;
}