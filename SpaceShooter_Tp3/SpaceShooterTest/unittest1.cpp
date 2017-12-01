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
			list.PushBack(1);
			list.PushBack(2);
			list.PushBack(3);
			list.PushBack(4);
			list.PushBack(5);
			for (List<int>::Iterator i = List<int>::Iterator(list.Start()); i != list.End(); ++i)
			{
				
				Assert::AreEqual(*i, a);
				a++;
			}
			// TODO: Ici, votre code de test
		}

	};
}