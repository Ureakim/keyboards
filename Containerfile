FROM docker.io/qmkfm/qmk_cli:latest

WORKDIR /qmk_firmware

RUN qmk setup -y
