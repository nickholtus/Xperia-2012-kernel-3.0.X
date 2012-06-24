# vim:syntax=make:
# -*- Mode: Makefile -*-

# Board and system independant
MMSYSTEM=x
MMBOARD=x

# Keep this first to include our OMX headers and not ones from other
CPPFLAGS+= -I. -I./base/ -I../include -DRELEASE -D__RELEASE

include $(MM_MAKEFILES_DIR)/SharedConfig.mk

## Install all the headers
INSTALL_HEADER = \
	common.h \
	content_pipe_file.h \
	extension_struct.h \
	omx_comp_debug_levels.h \
	omx_reference_resource_manager.h \
	queue.h \
	tsemaphore.h \
	component_loader.h \
	content_pipe_inet.h \
	getline.h \
	omx_create_loaders.h \
	omxcore.h \
	st_static_component_loader.h \
	utils.h \
	component_loader.h \
	tsemaphore.h \
	queue.h \
	omxcore.h \
	utils.h \
	extension_struct.h \
	OMXComponentRMExt.h \
	omx_base_clock_port.h \
	omx_base_filter.h \
	omx_base_port.h \
	omx_base_source.h \
	omx_classmagic.h \
	omx_base_audio_port.h \
	omx_base_component.h \
	omx_base_image_port.h \
	omx_base_sink.h \
	omx_base_video_port.h

SOLIBNAMES+=omxil-bellagio

LIBOBJ_omxil-bellagio = \
	st_static_component_loader \
	omxcore \
	omx_create_loaders_linux \
	tsemaphore \
	queue \
	utils \
	common \
	content_pipe_inet \
	content_pipe_file \
	omx_reference_resource_manager

## Sources from directory: base 
VPATH += base
LIBOBJ_omxil-bellagio += \
        omx_base_component \
        omx_base_port \
        omx_base_filter \
        omx_base_sink \
        omx_base_source \
        omx_base_audio_port \
        omx_base_video_port \
        omx_base_image_port \
        omx_base_clock_port \
        OMXComponentRMExt

FLAGS_omxil-bellagio = -ldl

ifeq ($(MMCOMPILER),android)
  LIBOBJ_omxil-bellagio += getline 
else
  FLAGS_omxil-bellagio += -lpthread 
endif

INSTALL_SOLIB=omxil-bellagio

todo: solib

################################################################################
# executable: omxregister 

EXEOBJ = omxregister common
EXENAME = omxregister
INSTALL_BIN = omxregister
CPPFLAGS += -DOMXILCOMPONENTSPATH=\"/usr/local/lib/bellagio/\"
EXE_LDFLAGS += -ldl 

ifeq ($(MMCOMPILER),android)
  EXE_LDFLAGS += $(ANDROID_OUT_TARGET_PRODUCT_DIRECTORY)/obj/STATIC_LIBRARIES/liblog_intermediates/liblog.a
endif

todo: exe

include $(MM_MAKEFILES_DIR)/SharedRules.mk
