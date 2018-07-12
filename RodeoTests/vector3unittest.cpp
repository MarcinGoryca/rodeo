#include "stdafx.h"
#include "CppUnitTest.h"
#include "../source/math/vector3.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace rodeo::math;

namespace rodeotests
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

        // Testing DOT PRODUCT
        TEST_METHOD(TestDotProductVector3)
        {
            _v3 = up(new Vector3(1.0f, 2.0f, 4.0f));
            Vector3 x(2.0f, 3.0f, 2.0f);

            float a = _v3->dot(x);

            Assert::AreEqual(16.0f, a);
        }

        // Testing Negate Method
        TEST_METHOD(TestNegateMethodVector3)
        {
            _v3 = up(new Vector3(2.0f, 3.0f, 4.0f));
            _v3->negate();

            Assert::AreEqual(-2.0f, _v3->getX());
            Assert::AreEqual(-3.0f, _v3->getY());
            Assert::AreEqual(-4.0f, _v3->getZ());

            Vector3 a(*_v3);

            a.negate();

            Assert::AreEqual(2.0f, a.getX());
            Assert::AreEqual(3.0f, a.getY());
            Assert::AreEqual(4.0f, a.getZ());
        }

        // Testing Cross Product 
        TEST_METHOD(TestCrossProductVector3)
        {
            _v3 = up(new Vector3(2.0f, 1.0f, 4.0f));
            up x = up(new Vector3(4.0f, 2.0f, -2.0f));
            Vector3 y;
            y = y.cross(*_v3, *x);

            // x = -10
            // y =  20
            // z = 0
            Assert::AreEqual(-10.0f, y.getX());
            Assert::AreEqual(20.0f, y.getY());
            Assert::AreEqual(0.0f, y.getZ());
        }

        // Testing operator+
        TEST_METHOD(TestOperatorPlusVector3)
        {
            _v3 = up(new Vector3(3.0f, 2.0f, 5.0f));
            up a = up(new Vector3(2.0f, -2.0f, -6.0f));

            Vector3 b = *_v3 + *a;
            Assert::AreEqual(5.0f, b.getX());
            Assert::AreEqual(0.0f, b.getY());
            Assert::AreEqual(-1.0f, b.getZ());
        }

        // Testing operator-
        TEST_METHOD(TestOperatorMinusVector3)
        {
            _v3 = up(new Vector3(3.0f, 2.0f, 5.0f));
            up a = up(new Vector3(2.0f, -2.0f, -6.0f));

            Vector3 b = *_v3 - *a;
            Assert::AreEqual(1.0f, b.getX());
            Assert::AreEqual(4.0f, b.getY());
            Assert::AreEqual(11.0f, b.getZ());
        }

        //Testing operator+ for scalar
        TEST_METHOD(TestOperatorPlusScalarVector3)
        {
            _v3 = up(new Vector3(3.0f, 2.0f, -4.0f));

            *_v3 = *_v3 + 4.0f;

            Assert::AreEqual(7.0f, _v3->getX());
            Assert::AreEqual(6.0f, _v3->getY());
            Assert::AreEqual(0.0f, _v3->getZ());
        }

        //Testing operator- for scalar
        TEST_METHOD(TestOperatorMinusScalarVector3)
        {
            _v3 = up(new Vector3(3.0f, -2.0f, 0.0f));
            float scalar = -4.0f;

            *_v3 = *_v3 - scalar;

            Assert::AreEqual(7.0f, _v3->getX());
            Assert::AreEqual(2.0f, _v3->getY());
            Assert::AreEqual(4.0f, _v3->getZ());
        }

        //Testing operator* for scalar
        TEST_METHOD(TestOperatorMultiplyScalarVector3)
        {
            _v3 = up(new Vector3(3.0f, 2.0f, -1.0f));

            float scalar = 8.0f;

            *_v3 = *_v3 * scalar;

            Assert::AreEqual(24.0f, _v3->getX());
            Assert::AreEqual(16.0f, _v3->getY());
            Assert::AreEqual(-8.0f, _v3->getZ());

        }

        //Testing operator* for Vector3
        TEST_METHOD(TestOperatorMultiplyVector3_Vector3)
        {
            _v3 = up(new Vector3(3.0f, -2.0f, 3.0f));
            up v3_2 = up(new Vector3(3.0f, 2.0f, 1.0f));

            *_v3 = *_v3 * *v3_2;

            Assert::AreEqual(9.0f, _v3->getX());
            Assert::AreEqual(-4.0f, _v3->getY());
            Assert::AreEqual(3.0f, _v3->getZ());

            up v3_3 = up(new Vector3(1.223f, 7.1342f, 0.5612f));

            *_v3 = *_v3 * *v3_3;

            Assert::AreEqual(11.007f, _v3->getX());
            Assert::AreEqual(-28.5368f, _v3->getY());
            Assert::AreEqual(1.6836f, _v3->getZ());

        }

        //Testing operator/ for scalar
        TEST_METHOD(TestOperatorDivideScalarVector3)
        {
            _v3 = up(new Vector3(2.0f, 1.22f, 3.0f));
            float scalar = 0.432f;

            *_v3 = *_v3 / scalar;

            Assert::AreEqual(4.629f, _v3->getX(),0.1f);
            Assert::AreEqual(2.824f, _v3->getY(), 0.1f);
            Assert::AreEqual(6.94f, _v3->getZ(), 0.1f);
        }

        //Testing operator+= Vector3
        TEST_METHOD(TestOperatorPlusEqualVector3_Vector3)
        {
            _v3 = up(new Vector3(4.0f, -6.0f, 2.5f));
            up v = up(new Vector3(-4.0f, 6.0f, 2.5f));

            *_v3 += *v;

            Assert::AreEqual(0.0f, _v3->getX());
            Assert::AreEqual(0.0f, _v3->getY());
            Assert::AreEqual(5.0f, _v3->getZ());
        }

        //Testing Operator-= Vector3
        TEST_METHOD(TestOperatorMinusEqualVector3_Vector3)
        {
            _v3 = up(new Vector3(4.0f, 1.0f, 4.0f));
            up v = up(new Vector3(7.0f, 4.0f, 1.2f));

            *_v3 -= *v;

            Assert::AreEqual(-3.0f, _v3->getX());
            Assert::AreEqual(-3.0f, _v3->getY());
            Assert::AreEqual(2.8f, _v3->getZ());
        }

        //Testing Operator*= Vector3
        TEST_METHOD(TestOperatorMultiplyEqualVector3_Vector3)
        {
            _v3 = up(new Vector3(2.0f, 7.3f, 0.4f));
            up v = up(new Vector3(1.1f, 8.4f, 9.3f));

            *_v3 *= *v;

            Assert::AreEqual(2.2f, _v3->getX());
            Assert::AreEqual(61.32f, _v3->getY());
            Assert::AreEqual(3.72f, _v3->getZ());
        }

        //Testing Operator/= Vector3
        TEST_METHOD(TestOperatorDivideEqualVector3_Vector3)
        {
            _v3 = up(new Vector3(5.0f, 4.0f, 3.0f));
            up v = up(new Vector3(3.2f, 1.0f, 2.5f));

            *_v3 /= *v;

            Assert::AreEqual(1.5625f, _v3->getX());
            Assert::AreEqual(4.0f, _v3->getY());
            Assert::AreEqual(1.2f, _v3->getZ());
        }

        //Testing Operator= Vector3
        TEST_METHOD(TestOperatorAsignVector3_Vector3)
        {
            _v3 = up(new Vector3(3.0f, 2.0f, 3.0f));

            up v = up(new Vector3(5.0f, 1.0f, 1.4f));

            *_v3 = *v;

            Assert::AreEqual(5.0f, _v3->getX());
            Assert::AreEqual(1.0f, _v3->getY());
            Assert::AreEqual(1.4f, _v3->getZ());
        }

        //Testing Operator== Vector3
        TEST_METHOD(TestOperatorEqualsVector3_Vector3)
        {
            _v3 = up(new Vector3(3.0f, 1.0f, 1.0f));
            up v = up(new Vector3(3.0f, 1.0f, 1.0f));

            bool areEqual = false;

            if (*_v3 == *v)
            {
                areEqual = true;
            }

            Assert::IsTrue(areEqual);
        }

        //Testing Operator != Vector3
        TEST_METHOD(TestOperatorNotEqualsVector3_Vector3)
        {
            _v3 = up(new Vector3(5.0f, 1.0f, 4.0f));
            up v = up(new Vector3(3.0f, -4.0f, 3.0f));

            bool areNotEqual = false;

            if (*_v3 != *v)
            {
                areNotEqual = true;
            }

            Assert::IsTrue(areNotEqual);
        }

        //Testing reset() method Vector3
        TEST_METHOD(TestResetMethodVector3)
        {
            _v3 = up(new Vector3(4.0f, -4.321f, -5.03f));

            Assert::AreEqual(4.0f, _v3->getX());
            Assert::AreEqual(-4.321f, _v3->getY());
            Assert::AreEqual(-5.03f, _v3->getZ());

            _v3->reset();

            Assert::AreEqual(0.0f, _v3->getX());
            Assert::AreEqual(0.0f, _v3->getY());
            Assert::AreEqual(0.0f, _v3->getZ());

            Vector3 v(5.0f, 3.0f, 2.0f);

            Assert::AreEqual(5.0f, v.getX());
            Assert::AreEqual(3.0f, v.getY());
            Assert::AreEqual(2.0f, v.getZ());

            v.reset();

            Assert::AreEqual(0.0f, v.getX());
            Assert::AreEqual(0.0f, v.getY());
            Assert::AreEqual(0.0f, v.getZ());
        }

        //Testing Cross Product Vector3
        TEST_METHOD(TestCrossVector3)
        {
            /*_v3 = up(new Vector3(3.0f, 2.0f, 1.5f));
            up v = up(new Vector3(4.0f, 3.0f, 2.5f));*/
            _v3 = up(new Vector3(2.0f, 1.0f, 4.0f));
            up x = up(new Vector3(4.0f, 2.0f, -2.0f));
            Vector3 result;

            Vector3::cross(result, *_v3, *x);

            /*
            result._x = v1._y * v2._z - v2._y * v1._z;
            result._y = v1._x * v2._z - v2._x * v1._z;
            result._z = v1._x * v2._y - v2._x * v1._y;
            */

            /*Assert::AreEqual(0.5f, result.getX());
            Assert::AreEqual(1.5f, result.getY());
            Assert::AreEqual(1.0f, result.getZ());*/
            Assert::AreEqual(-10.0f, result.getX());
            Assert::AreEqual(20.0f, result.getY());
            Assert::AreEqual(0.0f, result.getZ());
        }

        //Testing Dot Product Vector3
        TEST_METHOD(TestDotMethodVector3)
        {
            _v3 = up(new Vector3(3.0f, 4.0f, 1.0f));
            up v = up(new Vector3(4.0f, 3.0f, 2.0f));

            float dot = Vector3::dot(*_v3, *v);

            /*
            dot_product = v1._x * v2._x + v1._y * v2._y + v1._z * v2._z;
            */

            Assert::AreEqual(26.0f, dot);
        }

        //Testign Normalize Method
        TEST_METHOD(TestNormalizeMethodVector3)
        {
            _v3 = up(new Vector3(3.2f, 4.21f, 6.321f));

            _v3->normalize();

            /*
            
            float length = ::sqrt(this->_x * this->_x + this->_y * this->_y + this->_z * this->_z);
				if (length > 0.0f)
				{
					this->_x = this->_x / length;
					this->_y = this->_y / length;
					this->_z = this->_z / length;
                    }
            */

            Assert::AreEqual(0.39f, _v3->getX(), 0.1f);
            Assert::AreEqual(0.51f, _v3->getY(), 0.1f);
            Assert::AreEqual(0.76f, _v3->getZ(), 0.1f);
        }

        //Testing Vector3 cross helper method
        TEST_METHOD(TestCrossHelperMethod_Vector3)
        {
            _v3 = up(new Vector3(2.0f, 1.0f, 4.0f));
            up x = up(new Vector3(4.0f, 2.0f, -2.0f));
            Vector3 y;
            y = cross(*_v3, *x);

            // x = -10
            // y =  20
            // z = 0
            Assert::AreEqual(-10.0f, y.getX());
            Assert::AreEqual(20.0f, y.getY());
            Assert::AreEqual(0.0f, y.getZ());
            /*_v3 = up(new Vector3(3.0f, 2.0f, 1.5f));
            up v = up(new Vector3(4.0f, 3.0f, 2.5f));

            Vector3 result;

            result = cross(*_v3, *v);
            Assert::AreEqual(0.5f, result.getX());
            Assert::AreEqual(1.5f, result.getY());
            Assert::AreEqual(1.0f, result.getZ());*/
        }

        //Testing Vector3 add helper method
        TEST_METHOD(TestAddHelperMethod_Vector3)
        {
            _v3 = up(new Vector3(3.0f, -1.0f, 3.0f));
            up v = up(new Vector3(3.0f, 1.0f, 0.0f));
            Vector3 r;
            r = add(r, *_v3, *v);

            Assert::AreEqual(6.0f, r.getX());
            Assert::AreEqual(0.0f, r.getY());
            Assert::AreEqual(3.0f, r.getZ());
        }

        //Testing Vector3 DivideByScalar Helper Method
        TEST_METHOD(TestDivideByScalar_Vector3)
        {
            _v3 = up(new Vector3(-4.0f, 2.0f, 18.0f));

            *_v3 = divideByScalar(*_v3, 2.0f);

            Assert::AreEqual(-2.0f, _v3->getX());
            Assert::AreEqual(1.0f, _v3->getY());
            Assert::AreEqual(9.0f, _v3->getZ());
        }

        //Testing Vector3 Linear Interpolation LERP
        TEST_METHOD(TestInterpolateHelperMethod_Vector3)
        {
            _v3 = up(new Vector3(4.0f, 2.0f, 3.0f));
            _v = up(new Vector3(3.0f, 1.0f, 5.0f));
            _x = up(new Vector3);

            *_x = interpolate(*_v3, *_v);

            Assert::AreEqual(3.5f, _x->getX());
            Assert::AreEqual(1.5f, _x->getY());
            Assert::AreEqual(4.0f, _x->getZ());
        }

        //Testing ComputeNormals Helper Method
        TEST_METHOD(TestComputeNormals_Vector3)
        {
            _v3 = up(new Vector3(1.0f, 2.0f, 3.0f));
            _v = up(new Vector3(3.0f, 2.0f, 1.0f));
            _x = up(new Vector3(2.0f, 1.0f, 3.0f));

            Vector3 a;
            a = computeNormals(*_v3, *_v, *_x, a);

            //e1 = v2 - v1
            //e2 = v3 - v1
            //o = cross(e1, e2)
            //o.normalize

            //2, 0, -2
            //1, -1, 0
            //-2, -2, -2 / 3.46
            //-0.577
            Assert::AreEqual(-0.57f, a.getX(), 0.1f);
            Assert::AreEqual(-0.57f, a.getY(), 0.1f);
            Assert::AreEqual(-0.57f, a.getZ(), 0.1f);
        }

        //Testing VertexNormal Helper Method 
        TEST_METHOD(TestVertexNormalMethod_Vector3)
        {
            _v3 = up(new Vector3(-5.0f, 2.0f, 3.0f));

            Vector3 a = vertexNormal(*_v3);

            Assert::AreEqual(-0.8116f, a.getX(), 0.1f);
            Assert::AreEqual(0.3246f, a.getY(), 0.1f);
            Assert::AreEqual(0.4870f, a.getZ(), 0.1f);
        }

        //Testing Norm Helper Method Vector3
        TEST_METHOD(TestNormHelperMethod_Vector3)
        {
            _v3 = up(new Vector3(4.0f, -2.0f, 3.0f));
            norm(*_v3);

            Assert::AreEqual(0.7427f, _v3->getX(), 0.01f);
            Assert::AreEqual(-0.37139f, _v3->getY(), 0.01f);
            Assert::AreEqual(0.5570f, _v3->getZ(), 0.01f);
        }

        //Testing Normalize Helper Method Vector3
        TEST_METHOD(TestNormalizeHelperMethod_Vector3)
        {
            _v3 = up(new Vector3(4.0f, -2.0f, 3.0f));
            normalize(*_v3);

            Assert::AreEqual(0.7427f, _v3->getX(), 0.01f);
            Assert::AreEqual(-0.37139f, _v3->getY(), 0.01f);
            Assert::AreEqual(0.5570f, _v3->getZ(), 0.01f);
        }

        //Testing Distance Helper Method Vector3
        TEST_METHOD(TestDistanceHelperMethod_Vector3)
        {
            _v3 = up(new Vector3(3.0f, 2.0f, 5.0f));
            _v = up(new Vector3(2.0f, 1.0f, 3.0f));

            float dist = distance(*_v3, *_v);
            Assert::AreEqual(2.4494f, dist, 0.01f);
        }

        //Testing Subtract Helper Method Vector3
        TEST_METHOD(TestSubtractHelperMethod_Vector3)
        {
            _v3 = up(new Vector3(3.0f, 4.0f, 1.0f));
            _v = up(new Vector3(-3.0f, 1.0f, 3.0f));
            Vector3 a = subtract(a, *_v3, *_v);

            Assert::AreEqual(6.0f, a.getX());
            Assert::AreEqual(3.0f, a.getY());
            Assert::AreEqual(-2.0f, a.getZ());
        }
    private:
        up _v3;
        up _v;
        up _x;
    };
}