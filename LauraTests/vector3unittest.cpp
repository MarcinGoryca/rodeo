#include "stdafx.h"
#include "CppUnitTest.h"
#include "../source/math/vector3.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace laura::math;

namespace LauraTests
{
    TEST_CLASS(Vector3UnitTest)
    {
    public:
        typedef std::unique_ptr<Vector3> up;
        Vector3UnitTest()
            :_v3(nullptr)
        {}

        // Testing default constructor
        TEST_METHOD(TestConstructorVector3)
        {
            _v3 = up(new Vector3);

            Assert::AreEqual(0.0f, _v3->getX());
            Assert::AreEqual(0.0f, _v3->getY());
            Assert::AreEqual(0.0f, _v3->getZ());
        }

        // Testing constructor with parameters
        TEST_METHOD(TestConstructorWithParamsVector3)
        {
            _v3 = up(new Vector3(-3.0f, 2.765f, 0.03f));

            Assert::AreEqual(0.03f, _v3->getZ());
            Assert::AreEqual(2.765f, _v3->getY());
            Assert::AreEqual(-3.0f, _v3->getX());
        }

        // Testing copy constructor
        TEST_METHOD(TestCopyConstructorVector3)
        {
            _v3 = up(new Vector3(1.0f, 2.0f, 3.0f));
            up v1 = up(new Vector3(*_v3));

            Assert::AreEqual(1.0f, v1->getX());
            Assert::AreEqual(2.0f, v1->getY());
            Assert::AreEqual(3.0f, v1->getZ());
        }

        // Testing Zero Vector
        TEST_METHOD(TestZeroVector3)
        {
            Assert::AreEqual(0.0f, Vector3::S_VECTOR3_ZERO_.getX());
            Assert::AreEqual(0.0f, Vector3::S_VECTOR3_ZERO_.getY());
            Assert::AreEqual(0.0f, Vector3::S_VECTOR3_ZERO_.getZ());
        }

        // Testing Length of a Vector
        TEST_METHOD(TestLengthVector3)
        {
            _v3 = up(new Vector3(3.0f, 2.0f, 1.2f));

            float l = _v3->length();

            Assert::AreEqual(3.8f, l);

        }


    private:
        std::unique_ptr<Vector3> _v3;
    };
}