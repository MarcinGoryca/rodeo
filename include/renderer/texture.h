///*
//----------------------------------------------
//	Laura Game Engine
//	Copyright(c) Marcin Goryca
//	marcin.goryca@gmail.com
//	http://marcingoryca.pl
//----------------------------------------------
//*/
//#ifndef LAURA_RENDERER_TEXTURE_H_
//#define LAURA_RENDERER_TEXTURE_H_
//
//#ifndef LAURA_IO_FILEDDS_H_
//#include "io\filedds.h"
//#endif
//
//#ifndef LAURA_IO_FILETGA_H_
//#include "io\filetga.h"
//#endif
//
//namespace laura
//{
//	namespace renderer
//	{
//		class Texture
//		{
//		public:
//			Texture() {}
//
//			~Texture()
//			{
//				reset();
//			}
//
//			virtual bool load(Image* image, const char* filename, core::ui& tid);
//			//virtual void load(Image* image, std::string filename, ui numberOfTextures);
//			virtual void release(Image* image);
//			virtual void bind(Image* image, core::ui& tid);
//
//			// This will clean up all generated textures 
//			bool reset();
//
//		private:
//			// Used for counting number of generated textures 
//			static int _s_texture_count;
//			unsigned int _texture_id;
//
//			virtual void build(Image* image, core::ui& tid);
//		};
//	}
//}
//#endif