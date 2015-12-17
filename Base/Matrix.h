#pragma once

#include "..\Definitions.h"
#include "Array.h"

namespace NobelLib
{
	template <typename Type>
	class Matrix
	{
	private:
		Type** mtx_mObject;		//a  b  c  d
		int mtx_iHeight;		//b bb cb db
		int mtx_iWidth;			//c bc cc dc
		LLINT mtx_iSize;		//d bd cd dd

		bool mtx_bStart;
	public:
		Matrix(int width, int height)
		{
			New(width, height);
		}

		void New(int width, int height)
		{
			if (width >= 0 && height >= 0)
			{
				mtx_iWidth = width; mtx_iHeight = height;

				mtx_iSize = sizeof(Type) * width * height;

				mtx_mObject = (Type**)malloc(mtx_iSize / height);
				for (int i = 0; i < width; i++)
				{
					mtx_mObject[i] = (Type*)malloc(mtx_iSize / width);
					for (int x = 0; x < width; x++)
					{
						mtx_mObject[i][x] = Type();
					}
				}
				mtx_bStart = true;
			}
		}

		void Delete()
		{
			for (int i = 0; i < mtx_iWidth; i++)
				delete[] mtx_mObject[i];
			delete[] mtx_mObject;
			mtx_iHeight = NULL;
			mtx_iWidth = NULL;
			mtx_isize = NULL;
			mtx_bStart = false
		}

		bool Exist()
		{
			return mtx_bStart;
		}

		void Clear()
		{
			if (Exist())
			{
				int width = mtx_iWidth; int height = mtx_iHeight;
				Delete();
				New(width, height);
			}
		}
		Matrix<Type> Copy(Matrix<Type> &copying)
		{
			if (Exist())
				Delete();
			New(copying.mtx_iWidth, copying.mtx_iHeight);
			
			for (int i = 0; i < mtx_iHeight, i++)
			{
				for (int x = 0; x < mtx_iWidth; x++)
					mtx_mObject[i][x] = copying[i][x];
			}
			return this;
		}
		Type& getElement(int row = 0, int column = 0)
		{
			return this->mtx_mObject[row][column];
		}

		Matrix<Type>& operator=(Matrix<Type> addMe)
		{
			return Copy(addMe);
		}
		Array<Type>& operator[](int row)
		{
			if(row >= 0)
				return Array<Type>::Convert(this->mtx_mObject[row]);
			else 
				return NULL; //MANAGE ERROR
		}
	};

}