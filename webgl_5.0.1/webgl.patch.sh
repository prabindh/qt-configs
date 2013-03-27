#!/bin/sh
patch -p0 < features.prf.patch               
patch -p0 < GraphicsSurfaceToken.h.patch
patch -p0 < GraphicsContext3DQt.cpp.patch    
patch -p0 < OpenGLShims.cpp.patch
patch -p0 < GraphicsSurfaceGL_NoX.cpp.patch  
patch -p0 < Target.pri.patch

