###############################################################################
#        ▁▁▁▁▁▁▁▁  ▁▁▁▁▁▁▁▁  ▁▁▁▁ ▁▁▁  ▁▁▁▁▁▁▁▁                               #
#       ╱        ╲╱        ╲╱    ╱   ╲╱        ╲    language: makefile        #
#      ╱         ╱         ╱         ╱         ╱    author:   @tutur          #
#     ╱         ╱         ╱        ▁╱       ▁▁╱     created: 2020-05-01       #
#     ╲▁▁╱▁▁╱▁▁╱╲▁▁▁╱▁▁▁▁╱╲▁▁▁▁╱▁▁▁╱╲▁▁▁▁▁▁▁▁╱      updated: 2020-05-01       #
#                                                                             #
###############################################################################


# -- V E R S I O N  C H E C K -------------------------------------------------

# minimal version required
MINIMAL_VERSION := 3.0

# compare version
ifneq ($(MINIMAL_VERSION), $(firstword $(sort $(MAKE_VERSION) $(MINIMAL_VERSION))))
 $(error $(shell echo "error: Please use \033[1;32mGNU Make 4.2\033[0m or later"))
endif


# -- S E T T I N G S ----------------------------------------------------------

# set default target
.DEFAULT_GOAL := all

# use one shell for all commands
.ONESHELL:

# delete intermediate files on error
.DELETE_ON_ERROR:

# silent mode
.SILENT:

# set shell program
override SHELL := $(shell which zsh)

# set shell flags
.SHELLFLAGS := -d -f -c -e -o pipefail -u

# set make flags
override MAKEFLAGS += --warn-undefined-variables --no-builtin-rules




# -- O S   D E T E C T I O N ---------------------------------------------------

# Detect operating system
override OS := $(shell uname -s)

# exit if OS is not supported
ifeq ($(OS), Darwin)
 override PLATFORM := macosx
 override THREAD := $(shell sysctl -n hw.ncpu)
else ifeq ($(OS), Linux)
 override PLATFORM := linux
 override THREAD := $(shell nproc)
else
 $(error $(shell echo "Unsupported OS: \033[1;32m$(OS)\033[0m"))
endif


# -- D I R E C T O R I E S ----------------------------------------------------

# source directory
override SRCDIR := src

# include directory
override INCDIR := inc

# build directory
override BLDDIR := _bld

# object directory
override OBJDIR := $(BLDDIR)/_obj

# dependency directory
override DEPDIR := $(BLDDIR)/_dep

# json directory
override JSNDIR := $(BLDDIR)/_json



# -- S O U R C E S ------------------------------------------------------------

# list all source files
override FILES_NAME := main socket msg terminal numerics server connection channel sockaddr lexer parser cmd cmd_factory invite join kick list mode nick part pass ping privmsg quit topic user

ifeq ($(FILES_NAME),)
 $(error $(shell echo "No \033[1;32msource\033[0m files found"))
endif

# add source file extension
override SOURCES := $(addsuffix .cpp, $(FILES_NAME))

# get all source directories
override SRC_SUBDIR := $(shell find $(SRCDIR) -type d)

# compose source path
override SRC_PATH := $(shell \
	for dir in $(SRC_SUBDIR); do \
		for file in $(SOURCES); do \
			if [ -f $$dir/$$file ]; then \
				echo $$dir/$$file; \
			fi; \
		done; \
	done;)


override SRC := $(SRC_PATH)


override OBJ := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o,    $(SRC))
override DEP := $(patsubst $(OBJDIR)/%.o,   $(DEPDIR)/%.d,    $(OBJ))
override JSN := $(patsubst $(SRCDIR)/%.cpp, $(JSNDIR)/%.json, $(SRC))

override HIR := $(sort $(dir $(SRC)))
override OBJHIR := $(HIR:$(SRCDIR)/%=$(OBJDIR)/%)
override DEPHIR := $(HIR:$(SRCDIR)/%=$(DEPDIR)/%)
override JSNHIR := $(HIR:$(SRCDIR)/%=$(JSNDIR)/%)




# -- P R O G R A M  U T I L I T I E S -----------------------------------------

# make directory if not exists
MKDIR := mkdir -p

# remove recursively force
RM := rm -rf

# -- C O M P I L E R  S E T T I N G S -----------------------------------------

CXX := $(shell which c++)

STD := -std=c++98

OPT := -O0

CXXFLAGS :=	-Wall -Wextra -Werror -Wpedantic -Wno-unused -Wno-unused-variable -Wno-unused-parameter

LDFLAGS  :=

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

CMPFLAGS = -MJ $(JSNDIR)/$*.json

INCLUDES := $(addprefix -I, $(shell find $(INCDIR) -type d))

DEFINES  ?=


# -- T A R G E T S ------------------------------------------------------------

# project name
PROJECT = ircserv

# main executable
NAME = $(PROJECT)

# compile commands for clangd
COMPILE_COMMANDS = compile_commands.json



# -- F O R M A T T I N G ------------------------------------------------------

# formatting (erase line, move cursor up, set color)
override COLOR := "\x1b[1F\x1b[0J\x1b[3;31m"

# reset formatting
override RESET := "\x1b[0m"


# -- P H O N Y  T A R G E T S -------------------------------------------------

# phony targets
.PHONY: all clean fclean re ascii obj directory leaks




# -- M A I N  T A R G E T S ---------------------------------------------------

all: ascii $(NAME) $(COMPILE_COMMANDS)
	@echo $(COLOR)'[v]'$(RESET) "All targets are up to date !";


$(NAME): obj
	@echo $(COLOR)'[v]'$(RESET) "Linking $@";
	@$(CXX) $(OBJ) $(LDFLAGS) -o $@;



# -- C O M P I L A T I O N ----------------------------------------------------

# call self with threads
obj:
	@$(MAKE) -s -j$(THREAD) $(OBJ)

-include $(DEP)

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp Makefile | directory
	@echo $(COLOR)Compilation$(RESET) $(notdir $<);
	@$(CXX) $(DEFINES) $(STD) $(OPT) $(CXXFLAGS) $(CMPFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@



# -- C O M P I L E  C O M M A N D S -------------------------------------------

$(COMPILE_COMMANDS): obj
	@echo $(COLOR)Compile-Commands$(RESET) $@;
	@echo "[\n"$$(cat $(JSN) | sed '$$s/,\s*$$//')"\n]" | jq > $@


# -- D I R E C T O R I E S  C R E A T I O N -----------------------------------

directory:
	@$(MKDIR) $(OBJHIR) $(DEPHIR) $(JSNHIR)


# -- C L E A N I N G ----------------------------------------------------------

clean:
	@echo $(COLOR)'[x]'$(RESET) "Cleaned";
	@$(RM) $(BLDDIR) $(PROJECT).dSYM

fclean: clean
	@echo $(COLOR)'[x]'$(RESET) "Full cleaned";
	@$(RM) $(NAME) $(COMPILE_COMMANDS) .cache


# -- R E C O M P I L E --------------------------------------------------------

re: fclean all


# -- D E B U G  T A R G E T S -------------------------------------------------

leaks: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)


# -- A S C I I  A R T ---------------------------------------------------------

ascii:
	@echo \
		$(COLOR) \
		"   ▁▁▁▁▁▁▁▁  ▁▁▁▁▁▁▁▁  ▁▁▁▁ ▁▁▁  ▁▁▁▁▁▁▁▁	\n" \
		"  ╱        ╲╱        ╲╱    ╱   ╲╱        ╲	\n" \
		" ╱         ╱         ╱         ╱         ╱	\n" \
		"╱         ╱         ╱        ▁╱       ▁▁╱	\n" \
		"╲▁▁╱▁▁╱▁▁╱╲▁▁▁╱▁▁▁▁╱╲▁▁▁▁╱▁▁▁╱╲▁▁▁▁▁▁▁▁╱	\n\n" \
		$(RESET);








