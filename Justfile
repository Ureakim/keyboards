BUILD_DIR := "./build"
CONTAINER_RUNTIME := shell('command -v podman >/dev/null 2>&1 && echo "podman" || echo "docker"')
CONTAINER_IMAGE := "local/qmk_cli"
CONTAINER_VOLUME := " -v ./build:/qmk_firmware/.build \
	-v ./kyria:/qmk_firmware/keyboards/splitkb/halcyon/kyria/keymaps/ureakim \
	-v ./users/halcyon/users/halcyon_modules:/qmk_firmware/users/halcyon_modules "
CONTAINER_CMD := CONTAINER_RUNTIME + " run --rm -it " + CONTAINER_VOLUME + CONTAINER_IMAGE

prepare: image submodules

submodules:
	git submodule update --init --recursive --remote

image:
	{{CONTAINER_RUNTIME}} rmi {{CONTAINER_IMAGE}}
	{{CONTAINER_RUNTIME}} build -t {{CONTAINER_IMAGE}} .

run: mkdir_build
	{{CONTAINER_CMD}}

kyria: mkdir_build
	{{CONTAINER_CMD}} qmk compile -kb splitkb/halcyon/kyria/rev4 -km ureakim -e HLC_ENCODER=1 -e TARGET=kyria_left
	{{CONTAINER_CMD}} qmk compile -kb splitkb/halcyon/kyria/rev4 -km ureakim -e HLC_CIRQUE_TRACKPAD=1 -e TARGET=kyria_right

clean:
	rm -rf {{BUILD_DIR}}

mkdir_build:
	mkdir -p {{BUILD_DIR}}
