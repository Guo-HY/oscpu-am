NAME := chiplabtest
SRCS := $(shell find -L ./tests/ -name '*.[cS]')

# needed by chiplab func tests
ASFLAGS += -D__loongarch32

# override system include path
ASFLAGS += -I$(CURDIR)/include

include $(AM_HOME)/Makefile.app
