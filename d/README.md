# kuliya for D

Algeria's college hierarchy dataset as a D package

# Installation

You can use `kuliya` package with one of these 2 options:

1. Build it locally as it shown in [Get Started](#get-started) section then copy `kuliya.d` and `data.d` to your project.
2. Use dub package manager in your DUB project by following these steps:
    - Add `kuliya` dependency to your `dub.json`:
    ```json
    {
        "name": "sandbox",
        "dependencies": {
            "kuliya:d": "~>1.0.0"
        }
    }
    ```
    - Run `dub build` to fetch and build the package.
    - Use the package in your project.

You can check the usage [here](#usage).

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

# Usage

```d
import std.stdio;
import kuliya;

void main()
{
    auto res = getNodeByPath("umkb/fst/dee/sec");
    if (res is null)
    {
        writeln("Node not found");
    }
    else
    {
        writeln(res.name);
    }
}
```

# Contribute

Feel free to ask for help in [#kuliya](https://dzcode.slack.com/archives/C01C0155CKC) group chat
