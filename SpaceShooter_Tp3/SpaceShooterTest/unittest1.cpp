#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\SpaceShooter_Tp3\List.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SpaceShooterTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a = 0;
			List<int> list;
			list.PushBack(0);
			list.PushBack(0);
			list.PushBack(0);
			list.PushBack(0);
			list.PushBack(0);
			list.PushBack(0);
			for (List<int>::Iterator i = list.Start(); i != list.End()++; ++i)
			{
				
				Assert::AreEqual((*i), 0);
				a++;
			}
			Assert::AreEqual(6, a);
		
		}

	};
}