# <img src="art/monkeos.png" alt="drawing" width="50"/> MonkeOS 
![repo size](https://img.shields.io/github/repo-size/riviox/MonkeOS)
![top language](https://img.shields.io/github/languages/top/riviox/MonkeOS)
## an attempt to create OS in C++ and ASM 
## (Make pr) (im dumb) (help)

![Alt text](art/ss.png)
![Alt text](art/69.png)

# Build:
## Install packages:
* Pacman (Arch Linux, Manjaro, itp.):
```
sudo pacman -S gcc g++ qemu
```
* APT (Debian, Ubuntu, itp.):
```
sudo apt install build-essential qemu-system-x86 gcc-multilib
```
* DNF (Fedora, CentOS, itp.):
```
sudo dnf install gcc gcc-c++ qemu-system-x86
```
## Clone repo:
```
git clone https://github.com/riviox/MonkeOS.git
cd MonkeOS
```
## Run `monke.sh`
```
chmod +x monke.sh
./monke.sh build
```
## Start OS in QEMU:
```
./monke.sh run
```

## To Do:
- [x] Debug
- [ ] Keyboard input
- [ ] Shell
- [ ] Commands
