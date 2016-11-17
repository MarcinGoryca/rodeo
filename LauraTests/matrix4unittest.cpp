#include "stdafx.h"
#include "CppUnitTest.h"
#include "../source/math/matrix4.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace laura::math;

namespace LauraTests
{
	TEST_CLASS(Matrix4Test)
	{
	public:
		Matrix4Test()
			:_m4(nullptr)
		{

		}

		// Testing construction method
		TEST_METHOD(TestConstructorMatrix4)
		{
			Matrix4 m4(1.0f, 1.0f, 3.0f, 3.0f,
				-3.0f, 2.0f, 5.0f, 6.0f,
				7.0f, 4.5f, 2.2f, 8.5f,
				9.0f, 9.0f, 33.0f, 2234.04f);

			Assert::AreEqual(1.0f, m4.getM4(0));
			Assert::AreEqual(1.0f, m4.getM4(1));
			Assert::AreEqual(3.0f, m4.getM4(2));
			Assert::AreEqual(3.0f, m4.getM4(3));
			Assert::AreEqual(-3.0f, m4.getM4(4));
			Assert::AreEqual(2.0f, m4.getM4(5));
			Assert::AreEqual(5.0f, m4.getM4(6));
			Assert::AreEqual(6.0f, m4.getM4(7));
			Assert::AreEqual(7.0f, m4.getM4(8));
			Assert::AreEqual(4.5f, m4.getM4(9));
			Assert::AreEqual(2.2f, m4.getM4(10));
			Assert::AreEqual(8.5f, m4.getM4(11));
			Assert::AreEqual(9.0f, m4.getM4(12));
			Assert::AreEqual(9.0f, m4.getM4(13));
			Assert::AreEqual(33.0f, m4.getM4(14));
			Assert::AreEqual(2234.04f, m4.getM4(15));
		}

		// Testing constructor with array 
		TEST_METHOD(TestConstructionMatrix4WithArray)
		{
			float arr[16] = {
				-1.0f, 0.0f, 1.0f, 0.0f,
				1.0f, 0.0f, -1.0f, 0.0f,
				234512.0f, -334343.56f, 0.0f, 1.9823f,
				-1.0f, 1.0f, 0.0f, 0.4f
			};

			Matrix4 m4(arr);

			Assert::AreEqual(-1.0f, m4.getM4(0));
			Assert::AreEqual(0.0f, m4.getM4(1));
			Assert::AreEqual(1.0f, m4.getM4(2));
			Assert::AreEqual(0.0f, m4.getM4(3));
			Assert::AreEqual(1.0f, m4.getM4(4));
			Assert::AreEqual(0.0f, m4.getM4(5));
			Assert::AreEqual(-1.0f, m4.getM4(6));
			Assert::AreEqual(0.0f, m4.getM4(7));
			Assert::AreEqual(234512.0f, m4.getM4(8));
			Assert::AreEqual(-334343.56f, m4.getM4(9));
			Assert::AreEqual(0.0f, m4.getM4(10));
			Assert::AreEqual(1.9823f, m4.getM4(11));
			Assert::AreEqual(-1.0f, m4.getM4(12));
			Assert::AreEqual(1.0f, m4.getM4(13));
			Assert::AreEqual(0.0f, m4.getM4(14));
			Assert::AreEqual(0.4f, m4.getM4(15));
		}

		// Testing construction with Vector4 objects
		TEST_METHOD(TestConstructionMatrix4WithVector4)
		{
			Vector4 v1(-1.0f, 1.0f, 1.0f, 0.0f);
			Vector4 v2(-2.0f, 2.2f, 2.3f, 2.4f);
			Vector4 v3(-3.0f, 3.3f, 3.4f, 3.5f);
			Vector4 v4(-4.0f, 4.4f, 4.5f, 4.6f);

			Matrix4 m4(v1, v2, v3, v4);

			Assert::AreEqual(-1.0f, m4.getM4(0));
			Assert::AreEqual(-2.0f, m4.getM4(1));
			Assert::AreEqual(-3.0f, m4.getM4(2));
			Assert::AreEqual(-4.0f, m4.getM4(3));
			Assert::AreEqual(1.0f, m4.getM4(4));
			Assert::AreEqual(2.2f, m4.getM4(5));
			Assert::AreEqual(3.3f, m4.getM4(6));
			Assert::AreEqual(4.4f, m4.getM4(7));
			Assert::AreEqual(1.0f, m4.getM4(8));
			Assert::AreEqual(2.3f, m4.getM4(9));
			Assert::AreEqual(3.4f, m4.getM4(10));
			Assert::AreEqual(4.5f, m4.getM4(11));
			Assert::AreEqual(0.0f, m4.getM4(12));
			Assert::AreEqual(2.4f, m4.getM4(13));
			Assert::AreEqual(3.5f, m4.getM4(14));
			Assert::AreEqual(4.6f, m4.getM4(15));
		}

		// Testing Copying of a matrix
		TEST_METHOD(TestCopyConstructionMatrix4)
		{
			Vector4 v1(-1.0f, 1.0f, 1.0f, 0.0f);
			Vector4 v2(-2.0f, 2.2f, 2.3f, 2.4f);
			Vector4 v3(-3.0f, 3.3f, 3.4f, 3.5f);
			Vector4 v4(-4.0f, 4.4f, 4.5f, 4.6f);

			Matrix4 m4_1(v1, v2, v3, v4);

			Matrix4 m4_2(m4_1);

			Assert::AreEqual(m4_1.getM4(0), m4_2.getM4(0));
			Assert::AreEqual(m4_1.getM4(1), m4_2.getM4(1));
			Assert::AreEqual(m4_1.getM4(2), m4_2.getM4(2));
			Assert::AreEqual(m4_1.getM4(3), m4_2.getM4(3));
			Assert::AreEqual(m4_1.getM4(4), m4_2.getM4(4));
			Assert::AreEqual(m4_1.getM4(5), m4_2.getM4(5));
			Assert::AreEqual(m4_1.getM4(6), m4_2.getM4(6));
			Assert::AreEqual(m4_1.getM4(7), m4_2.getM4(7));
			Assert::AreEqual(m4_1.getM4(8), m4_2.getM4(8));
			Assert::AreEqual(m4_1.getM4(9), m4_2.getM4(9));
			Assert::AreEqual(m4_1.getM4(10), m4_2.getM4(10));
			Assert::AreEqual(m4_1.getM4(11), m4_2.getM4(11));
			Assert::AreEqual(m4_1.getM4(12), m4_2.getM4(12));
			Assert::AreEqual(m4_1.getM4(13), m4_2.getM4(13));
			Assert::AreEqual(m4_1.getM4(14), m4_2.getM4(14));
			Assert::AreEqual(m4_1.getM4(15), m4_2.getM4(15));
		}

		// Testing Construction Matrix4 with one Vector3
		TEST_METHOD(TestCosntructMatrix4WithOneVector3)
		{
			Vector3 v(4.0f, 5.0f, 6.0f);
			Matrix4 m1(v);

			Assert::AreEqual(1.0f, m1.getM4(0));
			Assert::AreEqual(0.0f, m1.getM4(1));
			Assert::AreEqual(0.0f, m1.getM4(2));
			Assert::AreEqual(0.0f, m1.getM4(3));
			Assert::AreEqual(0.0f, m1.getM4(4));
			Assert::AreEqual(1.0f, m1.getM4(5));
			Assert::AreEqual(0.0f, m1.getM4(6));
			Assert::AreEqual(0.0f, m1.getM4(7));
			Assert::AreEqual(0.0f, m1.getM4(8));
			Assert::AreEqual(0.0f, m1.getM4(9));
			Assert::AreEqual(1.0f, m1.getM4(10));
			Assert::AreEqual(0.0f, m1.getM4(11));
			Assert::AreEqual(4.0f, m1.getM4(12));
			Assert::AreEqual(5.0f, m1.getM4(13));
			Assert::AreEqual(6.0f, m1.getM4(14));
			Assert::AreEqual(1.0f, m1.getM4(15));
		}

		// Testing Loading Identity Matrix
		TEST_METHOD(TestLoadIdenityMatrix4)
		{
			Vector4 v1(-1.0f, 1.0f, 1.0f, 0.0f);
			Vector4 v2(-2.0f, 2.2f, 2.3f, 2.4f);
			Vector4 v3(-3.0f, 3.3f, 3.4f, 3.5f);
			Vector4 v4(-4.0f, 4.4f, 4.5f, 4.6f);
			Matrix4 m1(v1, v2, v3, v4);

			m1.loadIdentity();

			Assert::AreEqual(1.0f, m1.getM4(0));
			Assert::AreEqual(0.0f, m1.getM4(1));
			Assert::AreEqual(0.0f, m1.getM4(2));
			Assert::AreEqual(0.0f, m1.getM4(3));
			Assert::AreEqual(0.0f, m1.getM4(4));
			Assert::AreEqual(1.0f, m1.getM4(5));
			Assert::AreEqual(0.0f, m1.getM4(6));
			Assert::AreEqual(0.0f, m1.getM4(7));
			Assert::AreEqual(0.0f, m1.getM4(8));
			Assert::AreEqual(0.0f, m1.getM4(9));
			Assert::AreEqual(1.0f, m1.getM4(10));
			Assert::AreEqual(0.0f, m1.getM4(11));
			Assert::AreEqual(0.0f, m1.getM4(12));
			Assert::AreEqual(0.0f, m1.getM4(13));
			Assert::AreEqual(0.0f, m1.getM4(14));
			Assert::AreEqual(1.0f, m1.getM4(15));
		}

		// Testing Transpose Matrix method
		TEST_METHOD(TestTransposeMatrix4)
		{
			Vector4 v1(-1.0f, 1.0f, 1.0f, 0.0f);
			Vector4 v2(-2.0f, 2.2f, 2.3f, 2.4f);
			Vector4 v3(-3.0f, 3.3f, 3.4f, 3.5f);
			Vector4 v4(-4.0f, 4.4f, 4.5f, 4.6f);
			Matrix4 m1(v1, v2, v3, v4);

			m1.transpose();

			Assert::AreEqual(-1.0f, m1.getM4(0));
			Assert::AreEqual(1.0f, m1.getM4(1));
			Assert::AreEqual(1.0f, m1.getM4(2));
			Assert::AreEqual(0.0f, m1.getM4(3));
			Assert::AreEqual(-2.0f, m1.getM4(4));
			Assert::AreEqual(2.2f, m1.getM4(5));
			Assert::AreEqual(2.3f, m1.getM4(6));
			Assert::AreEqual(2.4f, m1.getM4(7));
			Assert::AreEqual(-3.0f, m1.getM4(8));
			Assert::AreEqual(3.3f, m1.getM4(9));
			Assert::AreEqual(3.4f, m1.getM4(10));
			Assert::AreEqual(3.5f, m1.getM4(11));
			Assert::AreEqual(-4.0f, m1.getM4(12));
			Assert::AreEqual(4.4f, m1.getM4(13));
			Assert::AreEqual(4.5f, m1.getM4(14));
			Assert::AreEqual(1.0f, m1.getM4(15));

		}

		// Testing multiplying a matrix by a scalar
		TEST_METHOD(TestMultiplyMatrix4ByScalar)
		{
			float scalar = 3.0f;

			Matrix4 m1;
			m1.loadIdentity();

			m1 = m1 * scalar;

			Assert::AreEqual(3.0f, m1.getM4(0));
			Assert::AreEqual(0.0f, m1.getM4(1));
			Assert::AreEqual(0.0f, m1.getM4(2));
			Assert::AreEqual(0.0f, m1.getM4(3));
			Assert::AreEqual(0.0f, m1.getM4(4));
			Assert::AreEqual(3.0f, m1.getM4(5));
			Assert::AreEqual(0.0f, m1.getM4(6));
			Assert::AreEqual(0.0f, m1.getM4(7));
			Assert::AreEqual(0.0f, m1.getM4(8));
			Assert::AreEqual(0.0f, m1.getM4(9));
			Assert::AreEqual(3.0f, m1.getM4(10));
			Assert::AreEqual(0.0f, m1.getM4(11));
			Assert::AreEqual(0.0f, m1.getM4(12));
			Assert::AreEqual(0.0f, m1.getM4(13));
			Assert::AreEqual(0.0f, m1.getM4(14));
			Assert::AreEqual(3.0f, m1.getM4(15));
		}

		// Testing multiplying a matrix by a matrix
		TEST_METHOD(TestMultiplyMatrix4ByMatrix4)
		{
			float arr[16] = {
				-1.0f, 1.0f, 2.0f, 3.0f,
				-3.0f, 2.0f, 2.0f, 1.0f,
				-7.0f, -1.0f, -5.0f, 1.0f,
				-4.0f, 1.0f, 1.0f, 3.0f
			};

			Vector4 v1(1.0f, -1.0f, 1.0f, -1.0f);
			Vector4 v2(-1.0f, 2.0f, 1.0f, -2.0f);
			Vector4 v3(0.0f, 1.0f, 2.0f, 3.0f);
			Vector4 v4(1.0f, 0.0f, 1.0f, 0.0f);

			Matrix4 m1(arr);
			Matrix4 m2(v1, v2, v3, v4);

			Matrix4 m3;

			m3 = m1 * m2;

			Assert::AreEqual(-3.0f, m3.getM4(0));
			Assert::AreEqual(-1.0f, m3.getM4(1));
			Assert::AreEqual(14.0f, m3.getM4(2));
			Assert::AreEqual(1.0f, m3.getM4(3));
			Assert::AreEqual(-4.0f, m3.getM4(4));
			Assert::AreEqual(7.0f, m3.getM4(5));
			Assert::AreEqual(9.0f, m3.getM4(6));
			Assert::AreEqual(-1.0f, m3.getM4(7));
			Assert::AreEqual(-12.0f, m3.getM4(8));
			Assert::AreEqual(-2.0f, m3.getM4(9));
			Assert::AreEqual(-8.0f, m3.getM4(10));
			Assert::AreEqual(-12.0f, m3.getM4(11));
			Assert::AreEqual(-7.0f, m3.getM4(12));
			Assert::AreEqual(1.0f, m3.getM4(13));
			Assert::AreEqual(12.0f, m3.getM4(14));
			Assert::AreEqual(-3.0f, m3.getM4(15));
		}

		// Testing asigning one matrix to another
		TEST_METHOD(TestAsigningMatrix4ToMatrix4)
		{
			Matrix4 m1;
			Matrix4 m2;

			m2.loadIdentity();

			m1 = m2;

			for (int i = 0; i < 16; ++i) {
				Assert::AreEqual(m1._m4[i], m2._m4[i]);
			}
		}

		// Testing equality of two matrices
		TEST_METHOD(TestEqualityOfTwoMatrices)
		{
			Matrix4 m1;
			Matrix4 m2;

			m1.loadIdentity();
			m2.loadIdentity();

			bool equal = false;

			if (m1 == m2)
			{
				equal = true;
			}

			Assert::IsTrue(equal);

			Vector3 v(1.0f, 1.0f, 1.0f);
			Matrix4 m3(v);

			//equal = false;
			if (m1 == m3)
			{
				equal = true;
			}
			else
			{
				equal = false;
			}

			// This Fails of course
			//Assert::IsTrue(equal, L"Test If Two Matrices Are Equal", LINE_INFO());
			Assert::IsFalse(equal);

		}

		// Testing that two matrices are not equal
		TEST_METHOD(TestTwoMatrix4AreNotEqual)
		{
			Matrix4 m1;
			Vector3 v(1.0f, 2.0f, 3.0f);
			Matrix4 m2(v);

			bool not_equal = false;

			if (m1 != m2)
			{
				not_equal = true;
			}

			Assert::IsTrue(not_equal);

			//not_equal = false;

			m1.loadIdentity();
			m2.loadIdentity();

			if (m1 != m2)
			{
				not_equal = true;
			}
			else {
				not_equal = false;
			}

			//This fails of course
			//Assert::IsTrue(not_equal, L"Test if Two Matrices Are Not Equal", LINE_INFO());

			Assert::IsFalse(not_equal);
		}

		// Testing Adding two matrices (operator+)
		TEST_METHOD(TestOperatorPlusMatrix4)
		{
			Matrix4 m1;

			Vector4 v1(1.0f, 1.0f, 1.0f, 1.0f);
			Vector4 v2(2.0f, 1.0f, 2.0f, 1.0f);
			Vector4 v3(-1.0f, -1.0f, 1.0f, 1.0f);
			Vector4 v4(0.0f, 1.0f, -3.0f, 1.0f);

			Matrix4 m2(v1, v2, v3, v4);
			m1.loadIdentity();

			Matrix4 m3 = m1 + m2;

			Assert::AreEqual(2.0f, m3.getM4(0));
			Assert::AreEqual(2.0f, m3.getM4(1));
			Assert::AreEqual(-1.0f, m3.getM4(2));
			Assert::AreEqual(0.0f, m3.getM4(3));
			Assert::AreEqual(1.0f, m3.getM4(4));
			Assert::AreEqual(2.0f, m3.getM4(5));
			Assert::AreEqual(-1.0f, m3.getM4(6));
			Assert::AreEqual(1.0f, m3.getM4(7));
			Assert::AreEqual(1.0f, m3.getM4(8));
			Assert::AreEqual(2.0f, m3.getM4(9));
			Assert::AreEqual(2.0f, m3.getM4(10));
			Assert::AreEqual(-3.0f, m3.getM4(11));
			Assert::AreEqual(1.0f, m3.getM4(12));
			Assert::AreEqual(1.0f, m3.getM4(13));
			Assert::AreEqual(1.0f, m3.getM4(14));
			Assert::AreEqual(2.0f, m3.getM4(15));

		}

		// Testing subtracting two matrices
		TEST_METHOD(TestOperatorMinusMatrix4)
		{
			Vector4 v1(1.0f, 1.0f, 1.0f, 1.0f);
			Vector4 v2(2.0f, 1.0f, 2.0f, 1.0f);
			Vector4 v3(-1.0f, -1.0f, 1.0f, 1.0f);
			Vector4 v4(0.0f, 1.0f, -3.0f, 1.0f);

			Matrix4 m1(v1, v2, v3, v4);

			Matrix4 m2;
			m2.loadIdentity();

			Matrix4 m3 = m1 - m2;

			Assert::AreEqual(0.0f, m3.getM4(0));
			Assert::AreEqual(2.0f, m3.getM4(1));
			Assert::AreEqual(-1.0f, m3.getM4(2));
			Assert::AreEqual(0.0f, m3.getM4(3));
			Assert::AreEqual(1.0f, m3.getM4(4));
			Assert::AreEqual(0.0f, m3.getM4(5));
			Assert::AreEqual(-1.0f, m3.getM4(6));
			Assert::AreEqual(1.0f, m3.getM4(7));
			Assert::AreEqual(1.0f, m3.getM4(8));
			Assert::AreEqual(2.0f, m3.getM4(9));
			Assert::AreEqual(0.0f, m3.getM4(10));
			Assert::AreEqual(-3.0f, m3.getM4(11));
			Assert::AreEqual(1.0f, m3.getM4(12));
			Assert::AreEqual(1.0f, m3.getM4(13));
			Assert::AreEqual(1.0f, m3.getM4(14));
			Assert::AreEqual(0.0f, m3.getM4(15));
		}

		// Testing Operator+= of Matrix4
		TEST_METHOD(TestOperatorPlusEqualMatrix4)
		{
			Matrix4 m1;

			Vector4 v1(1.0f, 1.0f, 1.0f, 1.0f);
			Vector4 v2(2.0f, 1.0f, 2.0f, 1.0f);
			Vector4 v3(-1.0f, -1.0f, 1.0f, 1.0f);
			Vector4 v4(0.0f, 1.0f, -3.0f, 1.0f);

			Matrix4 m2(v1, v2, v3, v4);
			m1.loadIdentity();

			m2 += m1;

			Assert::AreEqual(2.0f, m2.getM4(0));
			Assert::AreEqual(2.0f, m2.getM4(1));
			Assert::AreEqual(-1.0f, m2.getM4(2));
			Assert::AreEqual(0.0f, m2.getM4(3));
			Assert::AreEqual(1.0f, m2.getM4(4));
			Assert::AreEqual(2.0f, m2.getM4(5));
			Assert::AreEqual(-1.0f, m2.getM4(6));
			Assert::AreEqual(1.0f, m2.getM4(7));
			Assert::AreEqual(1.0f, m2.getM4(8));
			Assert::AreEqual(2.0f, m2.getM4(9));
			Assert::AreEqual(2.0f, m2.getM4(10));
			Assert::AreEqual(-3.0f, m2.getM4(11));
			Assert::AreEqual(1.0f, m2.getM4(12));
			Assert::AreEqual(1.0f, m2.getM4(13));
			Assert::AreEqual(1.0f, m2.getM4(14));
			Assert::AreEqual(2.0f, m2.getM4(15));
		}

		// Testing operator -= of Matrix4
		TEST_METHOD(TestOperatorMinusEqualMatrix4)
		{
			Vector4 v1(1.0f, 1.0f, 1.0f, 1.0f);
			Vector4 v2(2.0f, 1.0f, 2.0f, 1.0f);
			Vector4 v3(-1.0f, -1.0f, 1.0f, 1.0f);
			Vector4 v4(0.0f, 1.0f, -3.0f, 1.0f);

			Matrix4 m1(v1, v2, v3, v4);

			Matrix4 m2;
			m2.loadIdentity();

			m1 -= m2;

			Assert::AreEqual(0.0f, m1.getM4(0));
			Assert::AreEqual(2.0f, m1.getM4(1));
			Assert::AreEqual(-1.0f, m1.getM4(2));
			Assert::AreEqual(0.0f, m1.getM4(3));
			Assert::AreEqual(1.0f, m1.getM4(4));
			Assert::AreEqual(0.0f, m1.getM4(5));
			Assert::AreEqual(-1.0f, m1.getM4(6));
			Assert::AreEqual(1.0f, m1.getM4(7));
			Assert::AreEqual(1.0f, m1.getM4(8));
			Assert::AreEqual(2.0f, m1.getM4(9));
			Assert::AreEqual(0.0f, m1.getM4(10));
			Assert::AreEqual(-3.0f, m1.getM4(11));
			Assert::AreEqual(1.0f, m1.getM4(12));
			Assert::AreEqual(1.0f, m1.getM4(13));
			Assert::AreEqual(1.0f, m1.getM4(14));
			Assert::AreEqual(0.0f, m1.getM4(15));
		}

		// Testing operator *=
		TEST_METHOD(TestOperatorMultiplyEqualMatrix4ByScalar)
		{
			Matrix4 m1;
			float scalar = 4.0f;

			m1.setM4(0, -1.0f);
			m1.setM4(1, 1.0f);
			m1.setM4(2, 0.0f);
			m1.setM4(3, 1.0f);
			m1.setM4(4, 2.0f);
			m1.setM4(5, 2.0f);
			m1.setM4(6, 3.0f);
			m1.setM4(7, 5.0f);
			m1.setM4(8, 2.0f);
			m1.setM4(9, 0.0f);
			m1.setM4(10, -3.0f);
			m1.setM4(11, -2.0f);
			m1.setM4(12, 0.0f);
			m1.setM4(13, -5.0f);
			m1.setM4(14, 8.0f);
			m1.setM4(15, 1.0f);

			m1 *= scalar;

			Assert::AreEqual(-4.0f, m1.getM4(0));
			Assert::AreEqual(4.0f, m1.getM4(1));
			Assert::AreEqual(0.0f, m1.getM4(2));
			Assert::AreEqual(4.0f, m1.getM4(3));
			Assert::AreEqual(8.0f, m1.getM4(4));
			Assert::AreEqual(8.0f, m1.getM4(5));
			Assert::AreEqual(12.0f, m1.getM4(6));
			Assert::AreEqual(20.0f, m1.getM4(7));
			Assert::AreEqual(8.0f, m1.getM4(8));
			Assert::AreEqual(0.0f, m1.getM4(9));
			Assert::AreEqual(-12.0f, m1.getM4(10));
			Assert::AreEqual(-8.0f, m1.getM4(11));
			Assert::AreEqual(0.0f, m1.getM4(12));
			Assert::AreEqual(-20.0f, m1.getM4(13));
			Assert::AreEqual(32.0f, m1.getM4(14));
			Assert::AreEqual(4.0f, m1.getM4(15));
		}


		//TODO
		// Testing operator* of Vector4 with Matrix4
		// The result of this operation is a Vector4 object
		//TEST_METHOD(TestOperatorMultiplyVector4ByMatrix4)
		//{
		//	Vector4 v(2.0f, 1.0f, -1.0f, 1.0f);
		//	Matrix4 m;

		//	m.loadIdentity();

		//	// Should be the same vector

		//	Vector4 v2;

		//	v2 = v * m;
		//}

		// Assigning a value to the matrix
		TEST_METHOD(TestAssignmentOperatorMatrix4)
		{
			Matrix4 m;

			m = 16;

			// All elements of the matrix should be 16

			for (int i = 0; i < 16; ++i)
			{
				Assert::AreEqual(16.0f, m.getM4(i));
			}

		}

		// Testing Inversion of a Matrix
		TEST_METHOD(TestInversionMatrix4Method)
		{
			Matrix4 m;
			m.loadIdentity();

			m.inverse(m);

			Assert::AreEqual(-1.0f, m.getM4(0));
			Assert::AreEqual(-1.0f, m.getM4(5));
			Assert::AreEqual(-1.0f, m.getM4(10));
			Assert::AreEqual(-1.0f, m.getM4(15));

			m.inverse();

			Assert::AreEqual(1.0f, m.getM4(0));
			Assert::AreEqual(1.0f, m.getM4(5));
			Assert::AreEqual(1.0f, m.getM4(10));
			Assert::AreEqual(1.0f, m.getM4(15));
		}

		// TODO
		// Testing multiplication a matrix by matrix
		TEST_METHOD(TestOperatorMultiplyMatrix4ByMatrix4)
		{
			float arr[16] = {
				-1.0f, 1.0f, 2.0f, 3.0f,
				-3.0f, 2.0f, 2.0f, 1.0f,
				-7.0f, -1.0f, -5.0f, 1.0f,
				-4.0f, 1.0f, 1.0f, 3.0f
			};

			Vector4 v1(1.0f, -1.0f, 1.0f, -1.0f);
			Vector4 v2(-1.0f, 2.0f, 1.0f, -2.0f);
			Vector4 v3(0.0f, 1.0f, 2.0f, 3.0f);
			Vector4 v4(1.0f, 0.0f, 1.0f, 0.0f);

			Matrix4 m1(arr);
			Matrix4 m2(v1, v2, v3, v4);

			//Matrix4 m3;

			m1 *= m2;

			// TODO
			/*Assert::AreEqual(-3.0f, m1.getM4(0), L"test operator * Matrix4", LINE_INFO());
			Assert::AreEqual(-1.0f, m1.getM4(1), L"test operator * Matrix4", LINE_INFO());
			Assert::AreEqual(14.0f, m1.getM4(2), L"test operator * Matrix4", LINE_INFO());
			Assert::AreEqual(1.0f, m1.getM4(3), L"test operator * Matrix4", LINE_INFO());
			Assert::AreEqual(-4.0f, m1.getM4(4), L"test operator * Matrix4", LINE_INFO());
			Assert::AreEqual(8.0f, m1.getM4(5), L"test operator * Matrix4", LINE_INFO());
			Assert::AreEqual(9.0f, m1.getM4(6), L"test operator * Matrix4", LINE_INFO());
			Assert::AreEqual(-1.0f, m1.getM4(7), L"test operator * Matrix4", LINE_INFO());
			Assert::AreEqual(-12.0f, m1.getM4(8), L"test operator * Matrix4", LINE_INFO());
			Assert::AreEqual(-2.0f, m1.getM4(9), L"test operator * Matrix4", LINE_INFO());
			Assert::AreEqual(-8.0f, m1.getM4(10), L"test operator * Matrix4", LINE_INFO());
			Assert::AreEqual(-12.0f, m1.getM4(11), L"test operator * Matrix4", LINE_INFO());
			Assert::AreEqual(-7.0f, m1.getM4(12), L"test operator * Matrix4", LINE_INFO());
			Assert::AreEqual(1.0f, m1.getM4(13), L"test operator * Matrix4", LINE_INFO());
			Assert::AreEqual(12.0f, m1.getM4(14), L"test operator * Matrix4", LINE_INFO());
			Assert::AreEqual(-3.0f, m1.getM4(15), L"test operator * Matrix4", LINE_INFO());*/
		}

		// Testing identity loading (static case)
		TEST_METHOD(TestLoadStaticIdentityMatrix4)
		{
			Matrix4 m;
			m = Matrix4::_S_IDENTITY;

			Assert::AreEqual(1.0f, m.getM4(0));
			Assert::AreEqual(1.0f, m.getM4(5));
			Assert::AreEqual(1.0f, m.getM4(10));
			Assert::AreEqual(1.0f, m.getM4(15));
			Assert::AreEqual(0.0f, m.getM4(1));
			Assert::AreEqual(0.0f, m.getM4(2));
			Assert::AreEqual(0.0f, m.getM4(3));
			Assert::AreEqual(0.0f, m.getM4(4));
			Assert::AreEqual(0.0f, m.getM4(6));
			Assert::AreEqual(0.0f, m.getM4(7));
			Assert::AreEqual(0.0f, m.getM4(8));
			Assert::AreEqual(0.0f, m.getM4(9));
			Assert::AreEqual(0.0f, m.getM4(11));
			Assert::AreEqual(0.0f, m.getM4(12));
			Assert::AreEqual(0.0f, m.getM4(13));
			Assert::AreEqual(0.0f, m.getM4(14));
		}

		// Testing zeroying the matrix
		TEST_METHOD(TestZeroTheMatrix4)
		{
			Matrix4 m(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
				1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);

			m = Matrix4::_S_ZERO;

			Assert::AreEqual(0.0f, m.getM4(0));
			Assert::AreEqual(0.0f, m.getM4(1));
			Assert::AreEqual(0.0f, m.getM4(2));
			Assert::AreEqual(0.0f, m.getM4(3));
			Assert::AreEqual(0.0f, m.getM4(4));
			Assert::AreEqual(0.0f, m.getM4(5));
			Assert::AreEqual(0.0f, m.getM4(6));
			Assert::AreEqual(0.0f, m.getM4(7));
			Assert::AreEqual(0.0f, m.getM4(8));
			Assert::AreEqual(0.0f, m.getM4(9));
			Assert::AreEqual(0.0f, m.getM4(10));
			Assert::AreEqual(0.0f, m.getM4(11));
			Assert::AreEqual(0.0f, m.getM4(12));
			Assert::AreEqual(0.0f, m.getM4(13));
			Assert::AreEqual(0.0f, m.getM4(14));
			Assert::AreEqual(0.0f, m.getM4(15));
		}

		// Testing multiply method for Matrix4
		TEST_METHOD(TestMultiplyMethodMatrix4)
		{
			
			float arr[16] = {
				-1.0f, 1.0f, 2.0f, 3.0f,
				-3.0f, 2.0f, 2.0f, 1.0f,
				-7.0f, -1.0f, -5.0f, 1.0f,
				-4.0f, 1.0f, 1.0f, 3.0f
			};

			Vector4 v1(1.0f, -1.0f, 1.0f, -1.0f);
			Vector4 v2(-1.0f, 2.0f, 1.0f, -2.0f);
			Vector4 v3(0.0f, 1.0f, 2.0f, 3.0f);
			Vector4 v4(1.0f, 0.0f, 1.0f, 0.0f);

			Matrix4 m1(arr);
			Matrix4 m2(v1, v2, v3, v4);

			Matrix4 m3 = multiply(&m1, &m2);
			Assert::AreEqual(-3.0f, m3.getM4(0));
			Assert::AreEqual(-1.0f, m3.getM4(1));
			Assert::AreEqual(14.0f, m3.getM4(2));
			Assert::AreEqual(1.0f, m3.getM4(3));
			Assert::AreEqual(-4.0f, m3.getM4(4));
			Assert::AreEqual(7.0f, m3.getM4(5));
			Assert::AreEqual(9.0f, m3.getM4(6));
			Assert::AreEqual(-1.0f, m3.getM4(7));
			Assert::AreEqual(-12.0f, m3.getM4(8));
			Assert::AreEqual(-2.0f, m3.getM4(9));
			Assert::AreEqual(-8.0f, m3.getM4(10));
			Assert::AreEqual(-12.0f, m3.getM4(11));
			Assert::AreEqual(-7.0f, m3.getM4(12));
			Assert::AreEqual(1.0f, m3.getM4(13));
			Assert::AreEqual(12.0f, m3.getM4(14));
			Assert::AreEqual(-3.0f, m3.getM4(15));

		}

	private:
		std::unique_ptr<Matrix4> _m4;
	};
}