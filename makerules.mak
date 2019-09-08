
.PHONY: all test testsuite qemu FORCE

include config.mak

all:
	@echo "Target 'all' is currently empty. It is meant to build the whole free tricore toolchain in the future."


# ## ## ## ##
# TestSuite
# ## ## ## ##

ifeq ($(ftct_testsuite_build_dir),)
$(error "ERROR: ftct_testsuite_build_dir) is not set.")
endif

ifeq ($(ftct_qemu_build_dir),)
$(error "ERROR: ftct_qemu_build_dir) is not set.")
endif
ifeq ($(ftct_qemu_checkout_dir),)
$(error "ERROR: ftct_qemu_checkout_dir) is not set.")
endif

testsuite: qemu

qemu: $(ftct_qemu_build_dir)/makenode_done.txt


$(ftct_qemu_build_dir)/makenode_checkout.txt: FORCE
	@echo "[ INFO: Updating " $@ "]"
	mkdir -p $(dir $@)
	$(tools_dir)/checkout_git_makenode.bash $@ $(ftct_qemu_checkout_dir) $(ftct_qemu_git_url) $(ftct_qemu_git_tag) recursive

$(ftct_qemu_build_dir)/makenode_done.txt: $(ftct_qemu_build_dir)/makenode_checkout.txt
	@echo "[ INFO: Building QEMU for TriCore ]"
	@echo "INFO: This may require: " apt-get install build-essential zlib1g-dev pkg-config libglib2.0-dev binutils-dev libboost-all-dev
	@echo "                        " autoconf libtool libssl-dev libpixman-1-dev libpython-dev python-pip python-capstone virtualenv
	mkdir -p $(dir $@)
	( \
		cd $(ftct_qemu_checkout_dir); \
		./configure --target-list=tricore-softmmu; \
		make \
	)
	mkdir -p $(ftct_qemu_build_dir)/bin
	cp $(ftct_qemu_checkout_dir)/tricore-softmmu/qemu-system-tricore $(ftct_qemu_build_dir)/bin/ -v
	date --iso-8601=ns > $@
