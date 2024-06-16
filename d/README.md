# kuliya for D

Algeria's college hierarchy dataset as a D package

# Prerequisites
- One of these compilers:
  - [DMD](https://dlang.org/download.html#dmd) official compiler (works fine with dub)
  - [GDC](https://gdcproject.org/downloads) GCC based compiler
  - [LDC](https://github.com/ldc-developers/ldc#installation) LLVM based compiler
- [DUB](https://dub.pm/getting-started/install/) package manager
  - Note: you might need install the x86_64 arch for Apple silicon machines:
  ```sh
  arch -x86_64 /usr/local/bin/brew install dub
  ```
- Any IDE out there, preferably [VSCode](https://code.visualstudio.com/download) with [code-d](https://marketplace.visualstudio.com/items?itemName=webfreak.code-d) extension

# Get Started

- Run test:
```sh
cd d && dub test
```

- Build data:
```sh
cd d/build && dub
```

# Contribute

Feel free to ask for help in [#kuliya](https://dzcode.slack.com/archives/C01C0155CKC) group chat
