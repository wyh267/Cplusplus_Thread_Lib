
ARCH = arm

CROSS_DIR =
CROSS_COMPILE	= $(CROSS_DIR)

CC =  $(CROSS_COMPILE)g++
CCP= $(CROSS_COMPILE)g++
LD = $(CROSS_COMPILE)ld
STRIP=$(CROSS_COMPILE)strip
AR = $(CROSS_COMPILE)ar
AS = $(CROSS_COMPILE)as


SRCS+= \
	main.cpp \
	CThread.cpp \
	COperatingSystem.cpp \
	COperatingSystemFactory.cpp \
	CLinuxOperatingSystem.cpp  \
	TestThread.cpp  \
	CCountingSem.cpp \
	CLinuxCountingSem.cpp \
	CMutex.cpp \
	CLinuxMutex.cpp \
	CMsgQueue.cpp \
	CLinuxMsgQueue.cpp \
	TestThreadB.cpp
	


OBJS = $(SRCS:.cpp=.o)



TARGET=operation

$(TARGET):$(OBJS)
	@echo "Makeing $(TARGET)..."
	$(CC) $(OBJS) -o $(TARGET) $(LIB) -lpthread


%.o:%.cpp
	@echo "=======>>Makeing $(CC) -w -c -o $<"
	@$(CC) $(CFLAGS) -c $< -w -o $@


clean:
	rm -f *.o
	
