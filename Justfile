CONTAINER_RUNTIME := shell('command -v podman >/dev/null 2>&1 && echo "podman" || echo "docker"')
CONTAINER_IMAGE := "local/qmk_cli"
CONTAINER_VOLUME := " -v ./build:/qmk_firmware/.build -v ./kyria:/qmk_firmware/keyboards/splitkb/halcyon/kyria/keymaps/ureakim "
CONTAINER_CMD := CONTAINER_RUNTIME + " run --rm -it " + CONTAINER_VOLUME + CONTAINER_IMAGE

image:
	{{CONTAINER_IMAGE}} rmi {{CONTAINER_IMAGE}}
	{{CONTAINER_RUNTIME}} build -t {{CONTAINER_IMAGE}} .

run:
	{{CONTAINER_CMD}}

kyria:
	{{CONTAINER_CMD}} qmk compile -kb splitkb/halcyon/kyria/rev4 -km ureakim
