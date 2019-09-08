
.PHONY: all test testsuite qemu FORCE

include config.mak

all:
	@echo "Target 'all' is currently empty. It is meant to build the whole free tricore toolchain in the future."


# ## ## ## ##
# TestSuite
# ## ## ## ##

ifeq ($(ftct_testsuite_build_dir),)
$(error "ERROR: ftct_testsuite_build_dir is not set.")
endif

# ## ## ## ##
# Qemu
# ## ## ## ##

ifeq ($(ftct_qemu_build_dir),)
$(error "ERROR: ftct_qemu_build_dir is not set.")
endif
ifeq ($(ftct_qemu_checkout_dir),)
$(error "ERROR: ftct_qemu_checkout_dir is not set.")
endif

testsuite: qemu

qemu: $(ftct_qemu_bin)


$(ftct_qemu_build_dir)/makenode_checkout.txt: FORCE
	@echo
	@echo "[ INFO: Updating " $@ "]"
	@echo "    INFO: ftct_qemu_build_dir   :" $(ftct_qemu_build_dir)
	@echo "    INFO: ftct_qemu_checkout_dir:" $(ftct_qemu_checkout_dir)
	@echo "    INFO: ftct_qemu_git_url     :" $(ftct_qemu_git_url)
	@echo "    INFO: ftct_qemu_git_tag     :" $(ftct_qemu_git_tag)
	@echo "    INFO: ftct_qemu_bin         :" $(ftct_qemu_bin)
	mkdir -p $(dir $@)
	$(tools_dir)/checkout_git_makenode.bash $@ $(ftct_qemu_checkout_dir) $(ftct_qemu_git_url) $(ftct_qemu_git_tag) recursive

ftct_qemu_linux_packagelist = build-essential zlib1g-dev pkg-config libglib2.0-dev binutils-dev libboost-all-dev \
	autoconf libtool libssl-dev libpixman-1-dev libpython-dev python-pip python-capstone virtualenv

$(ftct_qemu_bin): $(ftct_qemu_build_dir)/makenode_checkout.txt
	@echo
	@echo "[ INFO: Building QEMU for TriCore ]"
	@echo "INFO: This may require: " apt-get install $(ftct_qemu_linux_packagelist)
	mkdir -p $(dir $@)
	( [ -e $@ ] && rm $@; echo 1 > /dev/null )
	( \
		cd $(ftct_qemu_checkout_dir); \
		./configure --target-list=tricore-softmmu; \
		make \
	)
	cp $(ftct_qemu_checkout_dir)/tricore-softmmu/qemu-system-tricore $(dir $@) -v
