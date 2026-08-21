BUILD_DIR := "./build"
CONTAINER_RUNTIME := shell('command -v podman >/dev/null 2>&1 && echo "podman" || echo "docker"')
CONTAINER_IMAGE := "local/qmk_cli"
CONTAINER_VOLUME := " -v ./build:/mnt/build:z \
	-v ./kyria:/qmk_firmware/keyboards/splitkb/halcyon/kyria/keymaps/ureakim:z \
	-v ./users/halcyon/users/halcyon_modules:/qmk_firmware/users/halcyon_modules:z "
CONTAINER_CMD := CONTAINER_RUNTIME + " run --rm -it " + CONTAINER_VOLUME + CONTAINER_IMAGE

prepare: image submodules

submodules:
	git submodule update --init --recursive --remote

image:
	{{CONTAINER_RUNTIME}} rmi -f {{CONTAINER_IMAGE}}
	{{CONTAINER_RUNTIME}} build -t {{CONTAINER_IMAGE}} .

run:
	{{CONTAINER_CMD}}

kyria:
	rm -rf {{BUILD_DIR}}/kyria/*
	mkdir -p {{BUILD_DIR}}/kyria/

	{{CONTAINER_CMD}} sh -c 'qmk compile -kb splitkb/halcyon/kyria/rev4 -km ureakim -e HLC_ENCODER=1 -e TARGET=kyria_left && cp ./.build/kyria_left.uf2 /mnt/build/kyria'
	{{CONTAINER_CMD}} sh -c 'qmk compile -kb splitkb/halcyon/kyria/rev4 -km ureakim -e HLC_CIRQUE_TRACKPAD=1 -e TARGET=kyria_right && cp ./.build/kyria_right.uf2 /mnt/build/kyria'
