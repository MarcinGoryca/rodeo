///**
//======================================================================================================================
//	{VectorTools.cpp}
//	Rodeo Game Engine source file
//	Copyright(c) 2010-2011 Marcin Goryca
//	http://rodeo.mgdev.pl
//======================================================================================================================
//*/
//#include "math\vectorstools.h"
//
//namespace enginemath
//{
//float findTheta(Vector2 a, Vector2 b)
//{
//	float theta = 0.0f;
//	float product = 0.0f;
//	float productALength = a.length();
//	float productBLength = b.length();
//	float productsLength = productALength * productBLength;
//	float dotProduct = a.dot(b);
//
//	if((productsLength != 0.0f) && (dotProduct != 0.0f))
//	{
//		product = dotProduct / productsLength;
//	}
//	if(product != 0.0f)
//	{
//		theta = ::acos(product);
//	}
//
//	theta = radiansToDegrees(theta);
//
//	return theta;
//}
////=============================================================================================================================
//}