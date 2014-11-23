#pragma once
namespace NobelLib
{
	template < typename Type >
	class Array
	{
	private:
	Type* array_Type;
	int array_Elements;
	bool Started;

	void Delete()
	{
		  if(Exist())
		  {
		  delete[] array_Type;
		  array_Elements = 0;
		  Started = false;
		  }
	}
	bool Exist()
	{
		if(Started==true)
			return true;
		else
			return false;
	}

	public:
		Array() 
		{
		  array_Elements=0;
		  array_Type=nullptr;
		  Started=true;
		}

		Array (int Index)
		{ 
			New(Index);
		}

		Array(const Array<Type> &Other)
		{
			Copy(Other);
			Started = true;
		}

		void delArray() 
		{
		  if(Exist())
		  {
		  Delete();
		  }
		}
		void Clear()
		{
			if(Exist())
			{
				Delete();
			}

		}


		void expArray(int NewIndex)
		{
			if(Exist() && NewIndex>array_Elements)
				if (this->array_Elements==0)
				{
					New(NewIndex);
					return;
				} 
				else
				{
				Type* secondArray = new Type[NewIndex+1];
				for (int Old=0; Old<array_Elements; Old++)
				{
					secondArray[Old] = array_Type[Old];
				}
			delete[] array_Type;
			array_Elements = NewIndex;
			array_Type = secondArray;
		  }
		}
		void New(int Index)
		{
			if(!Exist())
			{
				array_Elements=Index;
				array_Type = new Type[array_Elements+1]; 
				Started = true;
			}
		}
		

		void Copy(const Array<Type> &MyArray)
		{
		  if(this->Exist())

		  this->Clear();
		  if (MyArray.array_Elements <=0)
			return;

		  
		  New(MyArray.array_Elements);
		  
		  for (int i=0; i<MyArray.array_Elements; i++) 
		  {
			this->array_Type[i] = MyArray[i];
		  }
		}


		Type& operator[] (int Index)
		{
			if(Index >= 0 && Index < array_Elements)
			return array_Type[Index];
		}

		const Type& operator[] (int Index)const
		{
			if(Index >= 0 && Index < array_Elements)
			return array_Type[Index];
		}

		void operator= (Type* equal)
		{
			this->Copy(equal);
		}

		int SizeArray()
		{
			return array_Elements;
		}
	};
}