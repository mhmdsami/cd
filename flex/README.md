# flex

### Installation
- Download the tarball from the [flex](https://github.com/westes/flex/releases/tag/v2.6.4) site
- Extract the tar and move into the directory
- Run the `configure` script
```sh
./configure
```
- Build and install
```sh
make
make install
```

> [!TIP]
> If you have [brew](https://brew.sh/) on your machine, you could just do
> ```sh
> brew install flex
> ```

### Usage
```sh
flex example.lex
gcc lex.yy.c -lfl
./a.out
```
