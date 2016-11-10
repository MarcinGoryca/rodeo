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

			Assert::AreEqual(1.0f, m4._m4[0]);
			Assert::AreEqual(1.0f, m4._m4[1]);
			Assert::AreEqual(3.0f, m4._m4[2]);
		}

	private:
		std::unique_ptr<Matrix4> _m4;
	};
}