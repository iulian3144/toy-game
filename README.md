## Building the project

### Dependencies

* [`CMake`]() >= 3.10
* [`GNU Make`](https://www.gnu.org/software/make/) or [`Ninja`][ninja]
* A `C` compiler (development is done with `GCC`)

### Clone the repo
```
git clone --recursive <repo_url>
```

### Build
```sh
# also pass `-G Ninja` if you want to use ninja instead of make
cmake -S . -B build
make -C build # or `ninja -C build`
```

## TODO

* Use ECS pattern for managing game objects (-> flecs)
* command line arguments
    * print version (`-v, --version`)
    * set log level (`--loglevel <debug | info | warning | error>`, default: `warning`)
* fix audio - currently not working

## Nice to have

* Lua API
* Resource packer/unpacker

## Credits

[<img src="https://raw.githubusercontent.com/raysan5/raylib/master/logo/raylib_96x96.png" alt="raylib" height="96">](https://github.com/raysan5/raylib)
[<img src="https://raw.githubusercontent.com/SanderMertens/flecs/master/docs/img/logo.png" alt="flecs" height="96">](https://github.com/SanderMertens/flecs)

[ninja]: https://ninja-build.org
