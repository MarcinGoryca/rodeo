#include "stdafx.h"
#include "CppUnitTest.h"
#include "../source/math/vector2.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace laura::math;

namespace LauraTests
{
	TEST_CLASS(Vector2UnitTest)
	{
	public:

		typedef std::unique_ptr<Vector2> up;
		Vector2UnitTest()
			:_vec2(nullptr)
		{}

		// Testing Default Constructor
		TEST_METHOD(TestConstructorVector2)
		{
			_vec2 = up(new Vector2);
			Assert::AreEqual(0.0f, _vec2->getX());
			Assert::AreEqual(0.0f, _vec2->getY());
		}

		// Testing Constructor with two parameters
		TEST_METHOD(TestConstructorTwoParamsVector2)
		{
			_vec2 = up(new Vector2(-1.34f, 0.456f));
			Assert::AreEqual(-1.34f, _vec2->getX());
			Assert::AreEqual(0.456f, _vec2->getY());
		}

		// Testing Copy Constructor
		TEST_METHOD(TestCopyConstructorVector2)
		{
			_vec2 = up(new Vector2(-1.0f, 3.0f));
			up vec2 = up(new Vector2(*_vec2));

			Assert::AreEqual(-1.0f, vec2->getX());
			Assert::AreEqual(3.0f, vec2->getY());
		}

	private:
		std::unique_ptr<Vector2> _vec2;
	};
}