INCLUDES = -I. -I$(KDIR)/include
KBUILD_CFLAGS += -g

all: kernel_modules

obj-m	:= test_rbtree.o

KDIR	:= /lib/modules/$(shell uname -r)/build
PWD	:= $(shell pwd)

CFLAGS_test_rbtree.o = -I$(src)

%.ko: %.o
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) $@

kernel_modules:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

modules_install: all
	install -m 644 dsys.ko /lib/modules/`uname -r`/kernel/drivers/dsys.ko
	/sbin/depmod -a

install: modules_install

clean:
	$(RM) *.o *~ *.ko *.mod.c .*.o.cmd .*.ko.cmd *.symvers *.order
	$(RM) -r .tmp_versions
