#!/bin/bash

clean() {
    echo "Cleaning..."
    make -C src clean
}

build() {
    echo "Building MonkeOS..."
    make -C src
}

pack() {
    echo "Packing MonkeOS..."
    build
    if [ -f "src/monkeos.iso" ]; then
        tar -czvf monkeos.tar.bz2 -C src monkeos.iso
        echo "Packed MonkeOS into monkeos.tar.bz2"
    else
        echo "Error: monkeos.iso not found in src directory."
        exit 1
    fi
}

run() {
    echo "Running QEMU..."
    make -C src run
    echo "Clean before next run? (y/n)"
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
        echo "Usage: $0 {clean|build|run|pack}"
        exit 1
        ;;
esac

exit 0
