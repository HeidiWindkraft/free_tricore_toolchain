

# Directory of the config.mak
ftct_config_dir := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

# Tools-dir
tools_dir ?= $(ftct_config_dir)/tools

# Build-dir
FTCT_BUILD_DIR ?= $(ftct_config_dir)/build
ftct_build_dir = $(FTCT_BUILD_DIR)

# Test-suite build directory
FTCT_TESTSUITE_BUILD_DIR ?= $(ftct_build_dir)/testsuite
ftct_testsuite_build_dir = $(FTCT_TESTSUITE_BUILD_DIR)


# QEMU is only needed for the test-suite, so there is no need to treat it as sub-module / sub-project.
FTCT_QEMU_BUILD_DIR    ?= $(ftct_build_dir)/qemu

ftct_qemu_first_default_checkout_dir  := $(ftct_config_dir)/../qemu
ftct_qemu_second_default_checkout_dir := $(ftct_qemu_build_dir)/checkout
ifeq ($(FTCT_QEMU_CHECKOUT_DIR),)
	ifneq ($(wildcard $(ftct_qemu_first_default_checkout_dir)),)
		FTCT_QEMU_CHECKOUT_DIR ?= $(ftct_qemu_first_default_checkout_dir)
	endif
endif
FTCT_QEMU_CHECKOUT_DIR ?= $(ftct_qemu_second_default_checkout_dir)

ftct_qemu_build_dir    = $(FTCT_QEMU_BUILD_DIR)
ftct_qemu_checkout_dir = $(FTCT_QEMU_CHECKOUT_DIR)
ftct_qemu_git_url      := https://github.com/qemu/qemu.git
ftct_qemu_git_tag      := v4.1.0
ftct_qemu_bin          = $(ftct_qemu_build_dir)/bin/qemu-system-tricore
