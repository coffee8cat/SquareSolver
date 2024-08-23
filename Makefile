CC = g++

HEADERS_DIR = headers

CFLAGS =  -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal \
         -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs \
		 -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions \
		 -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 \
		 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor \
		 -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing \
		 -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

SOURCES_DIR = $(src)
SOURCES = $(wildcard *.cpp)

BUILD_DIR = build
EXECUTABLE = sqsolver.exe

all: $(SOURCES) $(BUILD_DIR)
	$(CC) $(SOURCES) -o $(BUILD_DIR)/$(EXECUTABLE) -I$(HEADERS_DIR) $(CFLAGS)

clean:
	rm $(BUILD)

create:
	mkdir build


