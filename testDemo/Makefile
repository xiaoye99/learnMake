# 参考模板
# .c .h 放在顶层, 中间生成的文件放在 OBJDIR, DEPDIR里面

OBJDIR := objs
DEPDIR := deps

SRCS := $(wildcard *.c)
OBJS := $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
DEPS := $(addprefix $(DEPDIR)/,$(SRCS:.c=.d))

PROG := prog
CC := gcc
CFLAG := -g
LIBS := -lpthread

$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

$(OBJDIR)/%.o: %.c
	$(CC) -o $@ -c $<

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif

$(DEPDIR)/%.d:%.c | $(DEPDIR) $(OBJDIR)
	@echo "build deps: $@"
	@set -e; rm -f $@; \
	$(CC) -MM $< | sed -E 's,($*).o[: ]*,$(OBJDIR)/\1.o $@: ,g' > $@

$(DEPDIR):
	mkdir -p $(DEPDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(PROG) $(OBJS) $(DEPS)