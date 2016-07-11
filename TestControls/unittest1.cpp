#include "stdafx.h"
#include "CppUnitTest.h"
#include "../NumericBox/NumericBox.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
// numeric box test class
namespace TestControls
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		

		TEST_METHOD(TestNumericBoxMin)
		{
			NumericBox *nB = new NumericBox(5, 2, 3);
			Assert::AreEqual(nB->getMin(), 2);
			delete nB;
		}

		TEST_METHOD(TestNumericBoxMax)
		{
			NumericBox *nB = new NumericBox(5, 2, 3);
			Assert::AreEqual(nB->getMax(), 3);
			delete nB;
		}

		TEST_METHOD(TestNumericBoxWidth)
		{
			NumericBox *nB = new NumericBox(5, 2, 3);
			Assert::AreEqual(nB->getWidth(), 5);
			delete nB;
		}

		TEST_METHOD(TestNumericBoxIncCount)
		{
			NumericBox *nB = new NumericBox(5, 2, 3);			
			nB->incCount();
			Assert::AreEqual(nB->getCount(), 1);
			delete nB;
		}

		TEST_METHOD(TestNumericBoxDecCount)
		{
			NumericBox *nB = new NumericBox(5, 2, 3);
			nB->incCount();
			nB->incCount();
			nB->incCount();
			nB->decCount();
			Assert::AreEqual(nB->getCount(), 2);
			delete nB;
		}
	};
}