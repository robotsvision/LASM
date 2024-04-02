# This is makefile for LASM compiler + Llibs

# Compiler --------------------->
CC = gcc

# Flags --------------------->
LASM_CFLAGS = -Wall -MMD -std=c17 -Iinclude

# OS --------------------->
OS := $(shell node scripts/os.js)

# Add flags based on OS --------------------->
LASM_CFLAGS += $(shell node scripts/os-flags.js $(OS))

# And based on CPU arch --------------------->
LASM_CFLAGS += $(shell node scripts/arch-flags.js)

# LASM_OUT --------------------->
LASM_OUT := $(shell node scripts/out.js $(OS))

# Llibs path --------------------->

LLIBS_PATH = external/llibs

# Llibs build ------------------------------------------>

LLIBS_CFLAGS = -Wall -MMD -std=c17 -Iinclude -I$(LLIBS_PATH)/cross/include

# Use Lingua framework ------------------------------------------>
LLIBS_CFLAGS += -D USE_LINGUA

LLIBS_NATIVE_PATH := $(shell node $(LLIBS_PATH)/scripts/native.js $(OS))

# Different files --------------------->
LLIBS_SRC_FILES := $(shell node scripts/find.js $(LLIBS_PATH)/$(LLIBS_NATIVE_PATH) .c)\
	$(shell node scripts/find.js $(LLIBS_PATH)/cross/ .c)
LLIBS_OBJ_FILES := $(LLIBS_SRC_FILES:.c=.o)
LLIBS_DEP_FILES := $(LLIBS_OBJ_FILES:.o=.d)

# Lena build ------------------------------------------>

# Llibs framework --------------------->
LASM_CFLAGS += -I$(LLIBS_PATH)/cross/include

# Different files --------------------->
LASM_SRC_FILES := $(shell node scripts/find.js src .c)
LASM_OBJ_FILES := $(LASM_SRC_FILES:.c=.o)
LASM_DEP_FILES := $(LASM_OBJ_FILES:.o=.d)

# Default Target --------------------->
all: $(LASM_OUT)

# Linking Llibs and Lena together --------------------->
$(LASM_OUT): $(LASM_OBJ_FILES) $(LLIBS_OBJ_FILES)
	$(CC) $(LASM_CFLAGS) -o $@ $^

# Compiling Lena object files --------------------->
$(LASM_SRC_FILES:.c=.o): %.o: %.c
	$(CC) $(LASM_CFLAGS) -c $< -o $@

# Compiling Llibs object files --------------------->
$(LLIBS_SRC_FILES:.c=.o): %.o: %.c
	$(CC) $(LLIBS_CFLAGS) -c $< -o $@

# Include generated dependencies --------------------->
-include $(LASM_DEP_FILES) $(LLIBS_DEP_FILES)

# Clean --------------------->
clean:
	rm -f $(LASM_OUT) $(LASM_OBJ_FILES) $(LASM_DEP_FILES) $(LLIBS_DEP_FILES)