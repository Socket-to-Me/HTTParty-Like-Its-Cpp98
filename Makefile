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
override FILES_NAME := main socket server sockaddr connection cmd join cmd_factory lexer parser

FILES_NAME += rpl_welcome_001 rpl_yourhost_002 rpl_created_003 rpl_myinfo_004 rpl_isupport_005 rpl_bounce_010 rpl_statscommands_212 rpl_endofstats_219 rpl_statsuptime_242 rpl_umodeis_221 rpl_luserclient_251 rpl_luserop_252 rpl_luserunknown_253 rpl_luserchannels_254 rpl_luserme_255 rpl_adminme_256 rpl_adminloc1_257 rpl_adminloc2_258 rpl_adminemail_259 rpl_tryagain_263 rpl_localusers_265 rpl_globalusers_266 rpl_whoiscertfp_276 rpl_none_300 rpl_away_301 rpl_userhost_302 rpl_unaway_305 rpl_nowaway_306 rpl_whoreply_352 rpl_whoisregnick_307 rpl_whoisuser_311 rpl_whoisserver_312 rpl_whoisoperator_313 rpl_whowasuser_314 rpl_whoisidle_317 rpl_endofwhois_318 rpl_whoischannels_319 rpl_whoisspecial_320 rpl_liststart_321 rpl_list_322 rpl_listend_323 rpl_channelmodeis_324 rpl_creationtime_329 rpl_whoisaccount_330 rpl_notopic_331 rpl_topic_332 rpl_topicwhotime_333 rpl_invitelist_336 rpl_endofinvitelist_337 rpl_whoisactually_338 rpl_inviting_341 rpl_invexlist_346 rpl_endofinvexlist_347 rpl_exceptlist_348 rpl_endofexceptlist_349 rpl_version_351 rpl_namreply_353 rpl_endofnames_366 rpl_links_364 rpl_endoflinks_365 rpl_banlist_367 rpl_endofbanlist_368 rpl_endofwhowas_369 rpl_info_371 rpl_endofinfo_374 rpl_motdstart_375 rpl_motd_372 rpl_endofmotd_376 rpl_whoishost_378 rpl_whoismodes_379 rpl_youreoper_381 rpl_rehashing_382 rpl_time_391 err_unknownerror_400 err_nosuchnick_401 err_nosuchserver_402 err_nosuchchannel_403 err_cannotsendtochan_404 err_toomanychannels_405 err_wasnosuchnick_406 err_noorigin_409 err_norecipient_411 err_notexttosend_412 err_inputtoolong_417 err_unknowncommand_421 err_nomotd_422 err_nonicknamegiven_431 err_erroneusnickname_432 err_nicknameinuse_433 err_nickcollision_436 err_usernotinchannel_441 err_notonchannel_442 err_useronchannel_443 err_notregistered_451 err_needmoreparams_461 err_alreadyregistered_462 err_passwdmismatch_464 err_yourebannedcreep_465 err_channelisfull_471 err_unknownmode_472 err_inviteonlychan_473 err_bannedfromchan_474 err_badchannelkey_475 err_badchanmask_476 err_noprivileges_481 err_chanoprivsneeded_482 err_cantkillserver_483 err_nooperhost_491 err_umodeunknownflag_501 err_usersdontmatch_502 err_helpnotfound_524 err_invalidkey_525 rpl_starttls_670 rpl_whoissecure_671 err_starttls_691 err_invalidmodeparam_696 rpl_helpstart_704 rpl_helptxt_705 rpl_endofhelp_706 err_noprivs_723 rpl_loggedin_900 rpl_loggedout_901 err_nicklocked_902 rpl_saslsuccess_903 err_saslfail_904 err_sasltoolong_905 err_saslaborted_906 err_saslalready_907

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
PROJECT = webserv

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








