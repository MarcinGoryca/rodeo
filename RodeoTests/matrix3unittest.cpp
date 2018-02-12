#include "stdafx.h"
#include "CppUnitTest.h"
#include "../source/math/matrix3.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace rodeo::math;

namespace rodeoTests
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

		// Check Matrix3 Transpose method
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

		// Check Matrix3 Identity method
		TEST_METHOD(CheckMatrix3Identity)
		{
			Matrix3 m3; // she has 0.0f's :)

			m3.identity();    // now she sould have identity

			Assert::AreEqual(1.0f, m3.getM3(0));
			Assert::AreEqual(1.0f, m3.getM3(4));
			Assert::AreEqual(1.0f, m3.getM3(8));
		}

		// Check multiplyByScalar method of Matrix3
		TEST_METHOD(CheckMultiplyByScalarMatrix3)
		{
			Matrix3 m3;  // 0.0f's
			const float a = 1.0f;

			m3.multiplyByScalar(a);

			for (int i = 0; i < 9; ++i)
			{
				Assert::AreEqual(0.0f, m3.getM3(i));
			}

			const float arr[9] =
			{
				1.0f, 2.0f, 3.0f,
				4.0f, 5.0f, 6.0f,
				7.0f, 8.0f, 9.0f
			};

			Matrix3 m3_2(arr);

			m3_2.multiplyByScalar(3.0f);

			Assert::AreEqual(3.0f, m3_2.getM3(0));
			
			//This test fails
			//Assert::AreNotEqual(6.0f, m3_2.getM3(1), L"Not Equal", LINE_INFO());

			Assert::AreEqual(9.0f, m3_2.getM3(2));
		}

		// Checking setM3(int,float) method of Matrix3
		TEST_METHOD(TestSetM3Matrix3)
		{
			_m3->setM3(2, 3.0f);
			_m3->setM3(8, -10.0f);

			Assert::AreEqual(3.0f, _m3->getM3(2));
			Assert::AreEqual(-10.0f, _m3->getM3(8));
		}

		// Checking determinant(const Matrix3& matrix)
		TEST_METHOD(TestDeterminantMatrix3)
		{
			Vector3 v1(1.0f, 4.0f, 7.0f);
			Vector3 v2(2.0f, 5.0f, 8.0f);
			Vector3 v3(3.0f, 6.0f, 9.0f);
			Matrix3 m3(v1, v2, v3);

			float det = determinant(m3);

			//Assert::AreEqual(0.0f, det, L"Determinant", LINE_INFO());

			const float arr[9] =
			{
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f, 9.0f
			};

			Matrix3 m3_2(arr);

			det = determinant(m3_2);

			Assert::AreEqual(0.0f, det, L"DETERMINANT", LINE_INFO());
		}

		// Test multiply method of Matrix3
		TEST_METHOD(TestMultiplyMatrix3)
		{
			float arr[9] =
			{
				1.0f, 1.0f, 1.0f,
				0.0f, 0.0f, 0.0f,
				3.0f, 1.0f, 4.0f
			};

			Vector3 v1(2.0f, 2.0f, 2.0f);
			Vector3 v2(-1.0f, 1.0f, 1.0f);
			Vector3 v3(-1.0f, -1.0f, 0.0f);

			Matrix3 m3(arr);
			Matrix3 m3_2(v1, v2, v3);

			Matrix3 m3_3 = multiply(m3, m3_2);

			Assert::AreEqual(6.0f, m3_3.getM3(0), L"Multiplying", LINE_INFO());
			Assert::AreEqual(1.0f, m3_3.getM3(1), L"Multiplying", LINE_INFO());
			Assert::AreEqual(-2.0f, m3_3.getM3(2), L"Multiplying", LINE_INFO());
			Assert::AreEqual(0.0f, m3_3.getM3(3), L"Multiplying", LINE_INFO());
			Assert::AreEqual(0.0f, m3_3.getM3(4), L"Multiplying", LINE_INFO());
			Assert::AreEqual(0.0f, m3_3.getM3(5), L"Multiplying", LINE_INFO());
			Assert::AreEqual(16.0f, m3_3.getM3(6), L"Multiplying", LINE_INFO());
			Assert::AreEqual(2.0f, m3_3.getM3(7), L"Multiplying", LINE_INFO());
			Assert::AreEqual(-4.0f, m3_3.getM3(8), L"Multiplying", LINE_INFO());
		}

		// Testing MultiplyByVector method 
		TEST_METHOD(TestMultiplyByVectorMatrix3)
		{
			Vector3 v1(1.0f, 1.0f, 2.0f);
			Vector3 v2(1.0f, 1.0f, 2.0f);
			Vector3 v3(1.0f, 2.0f, 3.0f);
			Vector3 v4(2.0f, 3.0f, 3.5f);

			Matrix3 m3(v1, v2, v3);

			Vector3 v5 = multiplyByVector(m3, v4);

			Assert::AreEqual(8.5f, v5.getX());
			Assert::AreEqual(12.0f, v5.getY());
			Assert::AreEqual(20.5f, v5.getZ());
		}
	private:
		std::unique_ptr<Matrix3> _m3;
	};
}
