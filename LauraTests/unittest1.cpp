#include "stdafx.h"
#include "CppUnitTest.h"

#include "../include/laura.h"
#include "../source/math/mathsystem.cpp"
#include "../source/math/matrix3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace laura::math;

namespace LauraTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		MathSystem* ms = nullptr;
		Matrix3* m3 = nullptr;
		UnitTest1()
		{
			ms = new MathSystem;
			m3 = new Matrix3;
		}


		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			Assert::AreEqual(1, 1);
			//Assert::AreEqual(2, -3);
		}

		// Check if on Cosinus table on 0 there is 1.0

		TEST_METHOD(GetCosinusOn0)
		{
			//MathSystem ms;
			Assert::AreEqual(1.0f, ms->getCosinusTable(0));
		}

		// Check if on Cosinus table on 180 there is -1.0
		TEST_METHOD(GetCosinusOn180)
		{
			//MathSystem ms;
			Assert::AreEqual(-1.0f, ms->getCosinusTable(180));
		}

		// Check if on Sinus table on 0 there is 0.0
		TEST_METHOD(GetSinusOn0)
		{
			//MathSystem ms;
			Assert::AreEqual(0.0f, ms->getSinusTable(0));
		}

		// Check if on Sinus table on 180 there is 0.0
		TEST_METHOD(GetSinusOn180)
		{
			//MathSystem ms;
			Assert::AreEqual(0.0f, ms->getSinusTable(180));
		}

		// Check if on Sinus table on 90 there is 0.0
		TEST_METHOD(GetSinusOn90)
		{
			//MathSystem ms;
			Assert::AreEqual(0.0f, ms->getSinusTable(90));
		}

		TEST_METHOD(GetMatrix3On0)
		{
			//Matrix3 m3;
			Assert::AreEqual(0.0f, m3->getM3(0));
		}
	};
}