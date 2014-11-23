#pragma once

namespace NobelLib
{
	template<typename Type>
	class List
	{
	private:
		Type* objList;
		List* nextList;
		int iList;
		static int totAlloc;
	public:
		List(Type& ptrType)
		{
			objList = new Type(ptrType);
			nextList = nullptr;
			iList = totAlloc;
			totAlloc++;
		}
		void addItem(Type& ptrType)
		{
			if (objList != NULL)
				nextList = new List(ptrType);
			else
			{
				objList = new Type;
				objList = ptrType;
				nextList = NULL;
			}
		}
		List& findIndex(int Index)
		{
			if (iList != Index)
				nextList->findIndex(Index);
			else
				return *this;
		}

		Type& operator[] (int Index)
		{
			return *findIndex(Index).objList;
		}
	};

	template<typename Type>
	int List<Type>::totAlloc = 0;
}