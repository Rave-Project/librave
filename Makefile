BUILDER := ndk-build

default:
	@echo "Start build with "
	$(BUILDER) NDK_PROJECT_PATH="$(CURDIR)"