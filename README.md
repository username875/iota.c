<h1 align="center">
  <br>
  <a href="https://docs.iota.org/docs/client-libraries/0.1/getting-started/c-quickstart"><img src="iota-c.png"></a>
</h1>

<h2 align="center">The official C client library for interacting with the Tangle</h2>

<p align="center">
    <a href="https://docs.iota.org/docs/client-libraries/0.1/getting-started/c-quickstart" style="text-decoration:none;">
    <img src="https://img.shields.io/badge/Documentation%20portal-blue.svg?style=for-the-badge"
         alt="Developer documentation portal">
      </p>
<p align="center">
  <a href="https://discord.iota.org/" style="text-decoration:none;"><img src="https://img.shields.io/badge/Discord-9cf.svg?logo=discord" alt="Discord"></a>
    <a href="https://iota.stackexchange.com/" style="text-decoration:none;"><img src="https://img.shields.io/badge/StackExchange-9cf.svg?logo=stackexchange" alt="StackExchange"></a>
    <a href="https://github.com/iotaledger/iota.c/blob/master/LICENSE" style="text-decoration:none;"><img src="https://img.shields.io/github/license/iotaledger/iota.c.svg" alt="Apache 2.0 license"></a>
    <a href="https://docs.iota.org/docs/node-software/0.1/iri/references/api-reference" style="text-decoration:none;"><img src="https://img.shields.io/badge/Node%20API%20coverage-16/18%20commands-green.svg" alt="Supported IRI API endpoints"></a>
</p>
      
<p align="center">
  <a href="#about">About</a> ◈
  <a href="#prerequisites">Prerequisites</a> ◈
  <a href="#installation">Installation</a> ◈
  <a href="#getting-started">Getting started</a> ◈
  <a href="#api-reference">API reference</a> ◈
  <a href="#examples">Examples</a> ◈
  <a href="#supporting-the-project">Supporting the project</a> ◈
  <a href="#joining-the-discussion">Joining the discussion</a> 
</p>

---

## About

WIP for Chrysalis

This is the **official** C client library, which allows you to do the following:
* Create transactions
* Read transactions
* Sign transactions
* Generate addresses

This is beta software, so there may be performance and stability issues.
Please report any issues in our [issue tracker](https://github.com/iotaledger/iota.c/issues/new/choose).

## Prerequisites

* pkg-config
* libcurl4-openssl-dev 
* GCC or Clang
* [CMake](https://cmake.org/) 3.15 and above
* [ninja-build](https://ninja-build.org/) (optional)

Ubuntu

```shell
sudo apt install build-essential libcurl4-openssl-dev pkg-config
```

## Building IOTA C Client Library

Compiling and testing library with Clang11 and Ninja

```shell
git clone https://github.com/iotaledger/iota.c.git
cd iota.c
mkdir build && cd build
cmake -G Ninja -DCMAKE_C_COMPILER=clang-11 -DCMAKE_CXX_COMPILER=clang++-11 -DIOTA_TESTS:BOOL=TRUE -DCMAKE_INSTALL_PREFIX=$PWD ..
ninja && ninja test
```

Compiling and testing library with Make and GCC

```shell
git clone https://github.com/iotaledger/iota.c.git
cd iota.c
mkdir build && cd build
cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DIOTA_TESTS:BOOL=TRUE -DCMAKE_INSTALL_PREFIX=$PWD ..
make -j8 && make test
```

The default build type is Debug mode with debug symbols, for Release mode you can add `-DCMAKE_BUILD_TYPE=Release` during the CMake configuration stage.

## Getting Started

TODO

## Visual Studio Code Integration

This template includes launch configurations for debugging test cases with Visual Studio Code located in the .vscode/ directory.
See [.vscode/README.md](./.vscode/README.md) for more information.
If you're not using VS Code, you can safely delete or ignore the directory.

## Supporting the project

If the IOTA C client library has been useful to you and you feel like contributing, consider posting a [bug report](https://github.com/iotaledger/iota.c/issues/new-issue), feature request or a [pull request](https://github.com/iotaledger/iota.c/pulls/). 
 
We have some [basic contribution guidelines](.github/CONTRIBUTING.md) to keep our code base stable and consistent.

## Joining the discussion

If you want to get involved in the community, need help with getting set up, have any issues related with the library or just want to discuss blockchain, distributed ledgers, and IoT with other people, feel free to join our [Discord](https://discord.iota.org/).
