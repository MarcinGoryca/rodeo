#include "stdafx.h"
#include "CppUnitTest.h"
#include "../source/math/matrix3.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace laura::math;

namespace LauraTests
{		
	TEST_CLASS(Matrix3Test)
	{
	public:
		Matrix3Test()
		{
			_m3 = std::unique_ptr<Matrix3>(new Matrix3);
		}

		// Check if element 0 has value 0.0
		TEST_METHOD(GetMatrix3on0)
		{
			// TODO: Your test code here
			Assert::AreEqual(0.0f, _m3->getM3(0));
		}

		// Check if all matrix elements have value of 0.0
		TEST_METHOD(GetMatrix3AllElements)
		{
			for (int i = 0; i < 9; ++i)
			{
				Assert::AreEqual(0.0f, _m3->getM3(i));
			}
		}

		// Check if matrix has specified elements
		// Using array as parameter
		TEST_METHOD(GetMatrix3SpecifiedElementsByArray)
		{
			float arr[9] =
			{
				0.0f,
				-1.0f,
				2.0f,
				3.0f,
				0.0f,
				1.0f,
				0.5f,
				-4.4f,
				0.0f
			};
			Matrix3 m3(arr);

			Assert::AreEqual(0.0f, m3.getM3(0));
			Assert::AreEqual(-1.0f, m3.getM3(1));
			Assert::AreEqual(2.0f, m3.getM3(2));
			Assert::AreEqual(3.0f, m3.getM3(3));
			Assert::AreEqual(0.0f, m3.getM3(4));
			Assert::AreEqual(1.0f, m3.getM3(5));
			Assert::AreEqual(0.5f, m3.getM3(6));
			Assert::AreEqual(-4.4f, m3.getM3(7));
			Assert::AreEqual(0.0f, m3.getM3(8));
		}

		// Check if Matrix has specified elements
		// Using three Vector3 objects
		TEST_METHOD(GetMatrix3SpecifiedElementsByVector3)
		{
			Vector3 v1(0.0f, 1.0f, 2.0f);
			Vector3 v2(-1.0f, 0.0f, 3.0f);
			Vector3 v3(6.0f, 0.4f, -8.4f);

			Matrix3 m3(v1, v2, v3);


			Assert::AreEqual(0.0f, m3.getM3(0), L"0", LINE_INFO());
			Assert::AreEqual(-1.0f, m3.getM3(1), L"0", LINE_INFO());
			Assert::AreEqual(6.0f, m3.getM3(2), L"0", LINE_INFO());
			Assert::AreEqual(1.0f, m3.getM3(3), L"0", LINE_INFO());
			Assert::AreEqual(0.0f, m3.getM3(4), L"0", LINE_INFO());
			Assert::AreEqual(0.4f, m3.getM3(5), L"0", LINE_INFO());
			Assert::AreEqual(2.0f, m3.getM3(6), L"0", LINE_INFO());
			Assert::AreEqual(3.0f, m3.getM3(7), L"0", LINE_INFO());
			Assert::AreEqual(-8.4f, m3.getM3(8), L"0", LINE_INFO());
		}

		// Check Matrix3 Transpose
		TEST_METHOD(GetMatrix3Transpose)
		{
			Vector3 v1(0.0f, 1.0f, 2.0f);
			Vector3 v2(3.0f, 4.0f, 5.0f);
			Vector3 v3(6.0f, 7.0f, 8.0f);

			Matrix3 m3(v1, v2, v3);

			m3.transpose();

			Assert::AreEqual(0.0f, m3.getM3(0));
			Assert::AreEqual(1.0f, m3.getM3(1));
			Assert::AreEqual(2.0f, m3.getM3(2));
			Assert::AreEqual(3.0f, m3.getM3(3));
			Assert::AreEqual(4.0f, m3.getM3(4));
			Assert::AreEqual(5.0f, m3.getM3(5));
			Assert::AreEqual(6.0f, m3.getM3(6));
			Assert::AreEqual(7.0f, m3.getM3(7));
			Assert::AreEqual(8.0f, m3.getM3(8));
		}

	private:
		std::unique_ptr<Matrix3> _m3;

	};
}
