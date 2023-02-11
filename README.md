## Building the project

### Dependencies

* [`CMake`]() >= 3.10
* [`GNU Make`](https://www.gnu.org/software/make/) or [`Ninja`][ninja]
* A `C` compiler (tested with `GCC`)

1. Clone the repo:
    ```
    git clone --recursive <repo_url>
    ```

2. Run the following commands:
    ```sh
    cmake -S . -B build
    make -C build
    ```
    Or, if you want to use [`Ninja`][ninja]:
    ```sh
    cmake -S . -B build -G Ninja
    ninja -C build
    ```

## TODO

* Use ECS pattern for managing game objects (-> flecs)

## Credits

[<img src="https://raw.githubusercontent.com/raysan5/raylib/master/logo/raylib_96x96.png" alt="raylib" height="96">](https://github.com/raysan5/raylib)
[<img src="https://raw.githubusercontent.com/SanderMertens/flecs/master/docs/img/logo.png" alt="flecs" height="96">](https://github.com/SanderMertens/flecs)

[ninja]: https://ninja-build.org
