#!/bin/bash

clean() {
    echo "Cleaning..."
    make -C src clean
}

build() {
    echo "Building MonkeOS..."
    make -C src
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
    "run")
        build && run
        ;;
    *)
        echo "Usage: $0 {clean|build|run}"
        exit 1
        ;;
esac

exit 0
