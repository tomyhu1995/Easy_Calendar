CC = gcc

CFLAGS += -Wall
CFLAGS += -g

EXE_NAME = Sample_calender

INC =
INC += -I../
INC += -I/usr/local/include

LIB =
LIB += -L/usr/local/lib

SRC = 
SRC += ../time_convert
SRC += ../event

SRC_FILES = ${addsuffix .c, ${SRC}}
OBJ_FILES = ${addsuffix .o, ${SRC}}

MAIN = main.c

LDFLAG = 
LDFLAG += -lev

all: ${EXE_NAME}

${EXE_NAME}: ${OBJ_FILES}
	${CC} ${CFLAGS} ${INC} ${MAIN} ${OBJ_FILES} -o $@ ${LDFLAG}
${OBJ_FILES} : %.o : %.c
	${CC} ${CFLAGS} -c ${INC} $< -o $@ ${LDFLAG}
clean:
	rm -rf ${OBJ_FILES} ${EXE_NAME}