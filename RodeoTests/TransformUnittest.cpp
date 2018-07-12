#include "stdafx.h"
#include "CppUnitTest.h"
#include "../source/math/transform.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace rodeo::math;

namespace rodeotests
{
	TEST_CLASS(TransformUnittest)
	{
		typedef std::unique_ptr<Matrix4> up;
		
	public:
		TransformUnittest() {}

		//Testing Scale method
		TEST_METHOD(TestScaleMethod_Transform)
		{
			Transform t;

			up _m = up(new Matrix4);

			*_m = t.scale(4.0f, 2.0f, 5.0f);

			Assert::AreEqual(4.0f, _m->getM4(0));
			Assert::AreEqual(2.0f, _m->getM4(5));
			Assert::AreEqual(5.0f, _m->getM4(10));
		}

		//Testing Rotate method
		TEST_METHOD(TestRotateMethod_Transform)
		{
			Transform t;
			up _m = up(new Matrix4);
			*_m = t.rotate(45.0f, -50.0f, 30.0f, 10.0f);

			//Assert::AreEqual()
		}
	};
}