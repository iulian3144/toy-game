## Building the project

1. Clone the repo:
    ```
    git clone --recursive <repo_url>
    ```

2. Run the following commands:
    ```sh
    cmake -S . -B build
    make -C build
    ```
    Or, if you want to use [ninja](https://ninja-build.org):
    ```sh
    cmake -S . -B build -G Ninja
    ninja -C build
    ```

## TODO

* Use ECS pattern for managing game objects

## Credits

[<img src="https://raw.githubusercontent.com/raysan5/raylib/master/logo/raylib_96x96.png" alt="raylib" height="96">](https://github.com/raysan5/raylib)
[<img src="https://raw.githubusercontent.com/SanderMertens/flecs/master/docs/img/logo.png" alt="flecs" height="96">](https://github.com/SanderMertens/flecs)