- clone vcpkg
- .\bootstrap-vcpkg.bat on terminal(windows)
- .\vcpkg install sfml

in  CMakeLists.txt replace ( set(SFML_DIR "C:/Users/Dell/Desktop/SFML_VCPKG/vcpkg/installed/x64-windows/share/sfml")) according to where you cloned vcpkg and copy the adress of sfml there

## 1 Build project
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
```
```bash
cmake --build build
```
## 2 Run(go to Debug or Release directory and run) //whichver you have
- ./build/release/game.exe

