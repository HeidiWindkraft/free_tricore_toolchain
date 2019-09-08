
.PHONY: all test testsuite qemu

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


$(ftct_qemu_build_dir)/makenode_checkout.txt:
	mkdir -p $(dir $@)
	$(tools_dir)/checkout_git_makenode.bash $@ $(ftct_qemu_checkout_dir) $(ftct_qemu_git_url) $(ftct_qemu_git_tag) recursive

$(ftct_qemu_build_dir)/makenode_done.txt: $(ftct_qemu_build_dir)/makenode_checkout.txt
	mkdir -p $(dir $@)
	pushd $(ftct_qemu_checkout_dir)
	# TODO ./configure
	# TODO make
	popd
	# TODO copy
	date date --iso-8601=ns > $@
