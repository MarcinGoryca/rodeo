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

	private:
		std::unique_ptr<Matrix4> _m4;
	};
}