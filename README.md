# zturn - Lightweight STUN/TURN server

[![License: GPL v2 or later](https://img.shields.io/badge/License-GPL_v2_or_later-blue.svg)](https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html)
[![Build](https://github.com/paullouisageneau/zturn/actions/workflows/build.yml/badge.svg)](https://github.com/paullouisageneau/zturn/actions/workflows/build.yml)
[![Docker](https://img.shields.io/docker/v/paullouisageneau/zturn/latest?color=2497ed&label=Docker)](https://hub.docker.com/repository/docker/paullouisageneau/zturn)
[![Gitter](https://badges.gitter.im/libjuice/zturn.svg)](https://gitter.im/libjuice/zturn?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
[![Discord](https://img.shields.io/discord/903257095539925006?logo=discord)](https://discord.gg/jXAP8jp3Nn)

zturn is a lightweight STUN/TURN server ([RFC8489](https://www.rfc-editor.org/rfc/rfc8489.html) and [RFC8656](https://www.rfc-editor.org/rfc/rfc8656.html)) written in C without dependencies, based on [libjuice](https://github.com/paullouisageneau/libjuice).

zturn is licensed under GPLv2 or later, see [LICENSE](https://github.com/paullouisageneau/zturn/blob/master/LICENSE).

![Oompa-Loompas rolling zturn, from Charlie and the Chocolate Factory](https://github.com/paullouisageneau/zturn/blob/master/image.png?raw=true)

> "Mercy! Save us!" yelled Mrs Beauregarde. "[...] zturn, you’re **turn**ing zturn, zturn!" [...]
>
> "Squeeze her," said Mr Wonka. "We've got to squeeze the **juice** out of her immediately."
>
> -- Charlie and the Chocolate Factory, Roald Dahl

## Dependencies

No external dependencies!

## Running with Docker

An image is available on [Docker Hub](https://hub.docker.com/repository/docker/paullouisageneau/zturn), running the TURN server with default options is as simple as:
```bash
docker run --network=host paullouisageneau/zturn --credentials=USER:PASSWORD
```
Available options can be listed with the `--help` flag:
```bash
docker run paullouisageneau/zturn --help
```

## Installing on Arch Linux

zturn is available as a [package on AUR](https://aur.archlinux.org/packages/zturn/):
```bash
paru -S zturn
sudo systemctl enable --now zturn
```
The configuration file is `/etc/zturn/zturn.conf`

## Building

### Clone repository and submodules

```bash
git clone https://github.com/paullouisageneau/zturn.git
cd zturn
git submodule update --init --recursive
```

### Build with CMake

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cd build
make -j2
```
```bash
./zturn --credentials=USER:PASSWORD
```
You can list available options with the `--help` (or `-h`) flag. You can also load a configuration file:
```bash
./zturn -f ../example.conf
```

### Build with Docker

```bash
docker build -t zturn .
```
```bash
docker run --network=host zturn --credentials=USER:PASSWORD
```
You can list available options with the `--help` flag. You can also load a configuration file:
```bash
docker run \
	--network=host \
	--mount type=bind,source=$(pwd)/example.conf,target=/etc/zturn.conf,readonly \
	paullouisageneau/zturn --file=/etc/zturn.conf
```

