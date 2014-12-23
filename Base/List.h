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
		static int iFound;

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
				if (nextList==nullptr)
					nextList = new List();

			}
			else if (nextList == nullptr)
			{
				nextList = new List(ptrType);
			}
		}

		List* findByObject(Type Object)
		{
			if (*(this->objList) == Object)
				return this;
			else
			{
				return nextList->findByObject(Object);
			}
		}
		List* findByIndex(int needle, int count=0)
		{
			if (needle == count)
				return this;
			else
			{
				count++;
				return nextList->findByIndex(needle, count);
			}
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
				findByIndex(i)->objList->~Type();
				findByIndex(i)->usedList = false;
			}
			for (i; i > -1; i--)
			{
				findByIndex(i)->nextList = nullptr;
			}
			return *this;
		}

		void deleteItem(Type Compare)
		{
			for (int i = 0; i < getLength(); i++)
				if (*(this->findByIndex(i)->objList) == Compare)
				{
					List* link = findByIndex(i)->nextList;
					delete findByIndex(i);
					findByIndex(i-1)->nextList = link;
				}
		}

		Type* operator[] (int Index)
		{
			return findByIndex(Index)->objList;
		}

		int getLength() { return getLength(0); }

	};

	template < typename Type >
	int List<Type>::iFound = 0;
}