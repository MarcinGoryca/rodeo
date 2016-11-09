///*
// |  -----------------------------------------------
// |    LAURA GAME ENGINE
// |    [ OutputController.h ] [ laura\controllers ]
// |    Copyright(c) Marcin Goryca
// |    marcin.goryca@gmail.com
// |    http://marcingoryca.pl
// |  -----------------------------------------------
// */
//
//#ifndef LAURA_CORE_OUTPUTCONTROLLER_H
//#define LAURA_CORE_OUTPUTCONTROLLER_H
//
//#ifndef LAURA_IO_LOG_H_
//#include "io/log.h"
//#endif
//
//#ifndef LAURA_CONTROLLERS_MASTERCONTROLLER_H_
//#include "controllers/mastercontroller.h"
//#endif
//
//namespace laura
//{
//	namespace controllers
//	{
//		class OutputController : public MasterController
//		{
//		public:
//
//			OutputController()
//				:MasterController()
//			{
//				init();
//			}
//
//			~OutputController()
//			{
//				clear();
//			}
//
//			/*
//			 * --------------------------------------------
//			 *    Gets Log
//			 *    Returns Log log
//			 * --------------------------------------------
//			 */
//
//			std::unique_ptr<io::Log*> getLog() const
//			{
//				return _log;
//			}
//
//		private:
//			void init();
//			void clear();
//
//			//io::Log* _log;
//			std::unique_ptr<io::Log*> _log;
//		};
//	}
//}
//#endif