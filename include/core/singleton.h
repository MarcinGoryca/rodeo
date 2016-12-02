/*
 | --------------------------------------------------------------------------------------------------
 |     Laura Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2016 Marcin Goryca
 |
 |     Permission is hereby granted, free of charge,
 |     to any person obtaining a copy of this software
 |     and associated documentation files (the "Software"),
 |     to deal in the Software without restriction,
 |     including without limitation the rights to use,
 |     copy, modify, merge, publish, distribute, sublicense,
 |     and/or sell copies of the Software,
 |     and to permit persons to whom the Software is furnished to do so,
 |     subject to the following conditions:
 |
 |     The above copyright notice and this permission notice
 |     shall be included in all copies or substantial portions of the Software.
 |
 |     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 |     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 |     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 |     IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 |     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 |     ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 |     IN THE SOFTWARE.
 |---------------------------------------------------------------------------------------------------
 */
/*
 |   !IMPORTANT NOTES!
 |   Source code by Scott Bilas, 
 |   "Game Programming Gems 1"
 |
 |   HOW TO USE:
 |   1. Public Inherit Singleton <MyClass> in MyClass
 |   2. Remember to create object of class MyClass
 |   3. Call MyClass::GetInstance()
 |   Example:
 |        class Enemy : public Singleton <Enemy>
 |        {
 |        public:
 |             Enemy* GetName(const char* name);
 |        };
 |        void ShowMeEnemyName()
 |        {
 |             Enemy* terrorist = Enemy::GetInstance().GetName("OsamaBinLaden");
 |             Enemy* monster = Enemy::GetInstance().GetName("Dragon");
 |        }
 |-----------------------------------------
 */

#ifndef LAURA_CORE_SINGLETON_H_
#define LAURA_CORE_SINGLETON_H_

namespace laura
{
    namespace core
    {
        template <typename T>class Singleton
        {
            static T* pSingleton;

        public:
            Singleton()
            {
                int offset = (int)(T*)1 - (int)(Singleton <T>*)(T*)1;
                pSingleton = (T*)((int)this + offset);
            }
            ~Singleton()
            {
                pSingleton = 0;
            }
            static T& getInstance()
            {
                return (*pSingleton);
            }
            static T* getInstanceByPtr()
            {
                return (pSingleton);
            }
        };

        template <typename T> T* Singleton <T>::pSingleton = 0;
    }
}
#endif