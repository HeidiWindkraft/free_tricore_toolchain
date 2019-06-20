# ftct - Free TriCore Toolchain

ftct is a compiler toolchain for Infineon TriCore chips.

ftct is meant to be free in the sense that it is under GNU GPL.
ftct is also meant to be free in the sense that it isn't commercial software.

ftct is not meant to be a competitor to commercial compilers.
Note, that TriCore processors are meant to be used in safety-critical automotive control units.
Because there's no intention to certify this tool-chain for use in safety-critical systems,
this tool-chain cannot be used to produce safety-critical automotive control units.
For example, there's GCC for ARM or Power Architecture,
but nevertheless certified commercial compilers are often used to produce safety-critical systems.

The purpose of this tool-chain is
- to have an extendable compiler for this chip which also allows to write free example tools to analyse software
- to do intensive, continuous testing
  - for which the expensive licenses of certified compilers are not suitable
  - and for which the windows binaries and their license checks are too slow
- to allow using languages which use LLVM as backend on TriCore ([sic](https://github.com/HeidiWindkraft/sic)?).

## Structure

Here's the plan:
This repository contains the library "ftct" for handling the TriCore processor architecture.
Library "ftct" is under GPL.
GNU binutils are usedd fdor assembling linking and handling ELF files.
The LLVM infrastructure is used to generate assembler code from C or other languages.
Library "ftct" is used by the GNU binutils port for TriCore which is added as sub-module of this repository.
Library "ftct" is used by the LLVM port for TriCore which is added as sub-module of this repository.

Note, that this also makes the LLVM port GNU GPL software, however, this shouldn't be an issue,
because TriCore-ports of LLVM until now never went upstream anyway and LLVM's license is more permissive than GNU GPL.
Furthermore, this software is intended to be free.

## Getting started
TODO

### ftcexpr

Go to directory `ftcexpr` and execute `make`.
Then execute `./ftcexpr "40 + 2" "@s16lo(0xefff_efff)" "@s16hi(0xefff_efff)"` and have a look at the result.
It should evaluate the integer expressions as you'd expect them to be evaluated in assembler code.
If `make` demands for flex and bison either install them or touch the `*.gen.*` files.


## Research and similar projects

Here are basically the first hits of a web search...

Code of these sources shall only be re-used, if it is free and GPL compatible.
If code is copied from these sources, it shall be clearly marked.

### TriCore 1 User's Manual V1.3.8 Volume 2

This document contains information about the instruction set of TriCore machines.
It can be found here: https://www.infineon.com/dgdl/tc_v131_instructionset_v138.pdf?fileId=db3a304412b407950112b409b6dd0352

### TriCore QEMU

The TriCore QEMU port contains useful information about the TriCore processor.
It especially contains information about instructions of the Aurix TC2xx series.
It can be found here: https://github.com/qemu/qemu/tree/master/target/tricore

### 2009 TriCore-LLVM paper

There's a paper from 2009 which describes a TriCore port for LLVM.
It can be found in several places:
- https://opus4.kobv.de/opus4-fau/files/1108/tricore_llvm.pdf
- https://pdfs.semanticscholar.org/fbfe/d669b0908ed8b71a24c54a6355fdc36e2a7d.pdf

### 2015 TriCore-LLVM

There is a TriCore port for LLVM which apparently started in 2015.
Its status is currently unclear to me. The last commits apparently happened in 2017.
It can be found here:
- https://github.com/TriDis/llvm-tricore
- https://github.com/kumailxp/tricore_llvm

### 2018/2005 GNU binutils for TriCore

There's https://github.com/Cheb57/binutils-tricore .
Apparently it contains code which was once provided by "HighTec EDV-Systeme GmbH", but which seems to be no longer publicly available.
I first thought those are only binaries, but there is zipped source code in it.

I'm not sure whether any of the things I saw there are legal and I'm not really sure how to handle this.
I'm not a lawyer.
Let's better avoid this code.
Nevertheless, it could be useful for early testing or for testing interoperability and conformance.
