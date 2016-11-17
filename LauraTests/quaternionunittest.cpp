#include "stdafx.h"
#include "CppUnitTest.h"
#include "../source/math/quaternion.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace laura::math;

namespace LauraTests
{
	TEST_CLASS(QuaternionUnitTest)
	{
	public:
		QuaternionUnitTest()
			:_quat(nullptr)
		{}

		// Testing default construction of a quaternion
		TEST_METHOD(TestQuaternionDefaultConstructor)
		{
			_quat = std::unique_ptr<Quaternion>(new Quaternion);

			Assert::AreEqual(0.0f, _quat->getX());
			Assert::AreEqual(0.0f, _quat->getY());
			Assert::AreEqual(0.0f, _quat->getZ());
			Assert::AreEqual(1.0f, _quat->getW());
		}

		// Testing creating quaternion by a vector
		TEST_METHOD(TestQuaternionConstructionByVector4)
		{

			Vector4 v(1.0f, 1.0f, 3.0f, 2.0f);
			Quaternion q(v);
			
			Assert::AreEqual(1.0f, q.getX());
			Assert::AreEqual(1.0f, q.getY());
			Assert::AreEqual(3.0f, q.getZ());
			Assert::AreEqual(2.0f, q.getW());
		}

		// Testing creation a quaternion by vector and a number
		TEST_METHOD(TestQuaternionConstructionByVectorByNumber)
		{
			float number = 1.0f;
			Vector3 v(1.0f, 2.0f, 3.0f);
			_quat = std::unique_ptr<Quaternion>(new Quaternion(v, number));
		
			Assert::AreEqual(1.0f, _quat->getX());
			Assert::AreEqual(2.0f, _quat->getY());
			Assert::AreEqual(3.0f, _quat->getZ());
			Assert::AreEqual(1.0f, _quat->getW());
		}
	private:
		std::unique_ptr<Quaternion> _quat;
	};
}