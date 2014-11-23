#include "Array.h"

using namespace NobelLib;

		template<class Type>
		void Array<Type>::Delete()
		{
			if (Exist())
			{
				delete[] array_Type;
				array_Elements = 0;
			}
		}

		template<class Type>
		bool Array<Type>::Exist()
		{
			if (Started == true)
				return true;
			else
				return false;
		}

		template<class Type>
		Array<Type>::Array()
		{
			array_Elements = 0;
			array_Type = nullptr;
			Started = true;
		}

		template<class Type>
		Array<Type>::Array(int Index)
		{
			New(Index);
		}

		template<class Type>
		Array<Type>::Array(const Array<Type> &Other)
		{
			Copy(Other);
		}

		template<class Type>
		void Array<Type>::delArray()
		{
			if (Exist())
			{
				Delete();
				Started = false;
			}
		}

		template<class Type>
		void Array<Type>::Clear()
		{
			if (Exist())
			{
				Delete();
			}

		}

		template<class Type>
		void Array<Type>::expArray(int NewIndex)
		{
			if (Exist() && NewIndex>array_Elements);
			// if not already allocated
			if (sa_Count == 0) {
				// just allocate
				newArray(NewIndex);
				return;
			}
			else// if already allocated
			{
				if (Exist());
				// allocate new array with more space
				Type* secondArray = new Type[NewIndex + 1]; //(+1 for cache-prefetch opt)
				// copy old objects
				for (int Old = 0; iOld<array_Elements; Old++)
				{
					secondArray[Old] = array_Type[Old];
				}
				// free old array
				delete[] array_Type;
				// remember the new array
				array_Elements = NewIndex;
				array_Type = secondArray;
			}
		}

		template<class Type>
		void Array<Type>::New(int Index)
		{
			if (!Exist())
			{
				array_Elements = Index;
				array_Type = new Type[array_Elements + 1];
			}
		}

		template<class Type>
		void Array<Type>::Copy(const Array<Type> &MyArray)
		{
			if (this->Exist())

				this->Clear();
			if (MyArray.array_Elements <= 0)
				return;


			New(MyArray.array_Elements);

			for (int i = 0; i<MyArray.array_Elements; i++)
			{
				this->array_Type[i] = MyArray[i];
			}
		}

		template<class Type>
		Type& Array<Type>::operator[] (int Index)
		{
			if (Index >= 0 && Index < array_Elements)
				return array_Type[Index];
		}

		template<class Type>
		const Type& Array<Type>::operator[] (int Index)const
		{
			if (Index >= 0 && Index < array_Elements)
				return array_Type[Index];
		}

		template<class Type>
		void Array<Type>::operator= (Type* equal)
		{
			this->Copy(equal);
		}

		template<class Type>
		void Array<Type>::setArray(Type Element, int Position)
		{
			if (Exist())
				array_Type[Position] = Element;
		}