/*
 |  -----------------------------------
 |     mona GAME ENGINE
 |     [ Singleton.h ] [ mona\core ]
 |     Copyright(c) Marcin Goryca
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |  -----------------------------------
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

#ifndef MONA_CORE_SINGLETON_H_
#define MONA_CORE_SINGLETON_H_

namespace mona
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