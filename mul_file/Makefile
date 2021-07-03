SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)

PROG := edit
CC := gcc -std=c99
CFLAGS := -Wall -O2
LDFLAGS :=
LIBS := -lm

$(PROG) : $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)

#############################################
# 自动生成依赖文件
ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif

%.d: %.c
	@echo "make depend: $@"
	@set -e; rm -f $@; \
	$(CC) $(CFLAGS) -MM $< | sed -E 's,($*).o[: ]*,\1.o $@: ,g' > $@
#############################################

.PHONY : clean
clean :
	rm -f $(PROG) $(OBJS) $(DEPS)