EXE=$(shell basename $(CURDIR))

HIP_PATH?=$(wildcard /opt/rocm/hip)
BLIS_PATH?=~/blis

ifeq (,$(HIP_PATH))
    HIP_PATH=
endif

CXX=$(HIP_PATH)/bin/hipcc

TOOLS=../tools ~/blis/include/zen

SRC=$(wildcard $(TOOLS)/*.c) $(wildcard ./*.c)
OBJ=$(patsubst %.c, %.o, $(SRC))

CFLAGS= -g -c -Ofast

INC= -I$(TOOLS)
LDFLAGS= -g -L$(HIP_PATH)/include/lib -lhip_hcc -L$(BLIS_PATH)/zen/lib -lblis

.PHONY: clean, all, run
RM= rm -rf

all:$(EXE)

show:
	echo $(OBJ)

$(EXE):$(OBJ)
	$(CXX) $(LDFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ) $(EXE)

run:
	./$(EXE)
