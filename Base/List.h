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
		int iList=0;
		static int iFound;
	public:
		List()
		{
			objList = nullptr;
			nextList = nullptr;
			usedList = false;
		}
		List(int index)
		{
			objList = nullptr;
			nextList = nullptr;
			usedList = false;
			iList = index;
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
				if (nextList==nullptr)
					nextList = new List(this->iList+1);

			}
			else if (nextList == nullptr)
			{
				nextList = new List(ptrType);
			}
		}
		List* findIndex(int Index)
		{
			if (this->iList == Index)
				return this;
			else
				return nextList->findIndex(Index);
		}
		Array<Type>* toArray()
		{
			Array<Type> arrayRet(totAlloc);
			for (int i = 0; i < totAlloc; i++)
			{
				arrayRet[i] = findIndex(i)->objList;
			}
		}
		List<Type> Clear()
		{
			int i = 0;
			for (i; i < getLength(0); i++)
			{
				findIndex(i)->objList->~Type();
				findIndex(i)->usedList = false;
			}
			for (i; i > -1; i--)
			{
				findIndex(i)->nextList = nullptr;
			}
			return *this;
		}
		Type& operator[] (int Index)
		{
			return *findIndex(Index)->objList;
		}
		int getLength(int index) 
		{
			if (this->objList != nullptr)
			{
				index++;
				nextList->getLength(index);
			}
			else
			{
				iFound = index;
				return iFound;
			}
			return iFound;
		}
	};
	template < typename Type >
	int List<Type>::iFound = 0;
}