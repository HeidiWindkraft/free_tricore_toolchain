

# Directory of the config.mak
ftct_config_dir := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

# Tools-dir
tools_dir ?= $(ftct_config_dir)/tools

# Build-dir
ftct_build_dir ?= $(ftct_config_dir)/build

# Test-suite build directory
ftct_testsuite_build_dir ?= $(ftct_build_dir)/testsuite

# QEMU is only needed for the test-suite, so there is no need to treat it as sub-module / sub-project.
ftct_qemu_build_dir    ?= $(ftct_testsuite_build_dir)/qemu
ftct_qemu_checkout_dir ?= $(ftct_qemu_build_dir)/checkout
ftct_qemu_git_url      := https://github.com/qemu/qemu.git
ftct_qemu_git_tag      := v4.1.0
