TARGET := iphone:clang:16.5:16.5


include $(THEOS)/makefiles/common.mk

TWEAK_NAME = GoblinSwordHack

GoblinSwordHack_FILES = Tweak.xm
GoblinSwordHack_CFLAGS = -fobjc-arc

include $(THEOS_MAKE_PATH)/tweak.mk
