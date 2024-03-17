#!/bin/bash

# ANSI color escape codes
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

clean() {
    echo -e "${YELLOW}Cleaning...${NC}"
    make -C src clean
}

build() {
    echo -e "${YELLOW}Building MonkeOS...${NC}"
    make -C src
}

pack() {
    echo -e "${YELLOW}Packing MonkeOS...${NC}"
    build
    if [ -f "src/monkeos.iso" ]; then
        tar -czvf monkeos.tar.bz2 -C src monkeos.iso
        echo -e "${GREEN}Packed MonkeOS into monkeos.tar.bz2${NC}"
    else
        echo -e "${RED}Error: monkeos.iso not found in src directory.${NC}"
        exit 1
    fi
    echo -e "${YELLOW}Clean before next build? (y/n)${NC}"
    read -r answer
    if [[ $answer =~ ^[Yy]$ ]]; then
        clean
    fi
}

run() {
    echo -e "${YELLOW}Running QEMU...${NC}"
    make -C src run
    echo -e "${YELLOW}Clean before next run? (y/n)${NC}"
    read -r answer
    if [[ $answer =~ ^[Yy]$ ]]; then
        clean
    fi
}

case "$1" in
    "clean")
        clean
        ;;
    "build")
        build
        ;;
    "pack")
        pack
        ;;
    "run")
        build && run
        ;;
    *)
        echo -e "${RED}Usage: $0 {clean|build|run|pack}${NC}"
        exit 1
        ;;
esac

exit 0
