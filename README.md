# idf_nested_components
Attempt to build a project with nested components using ESP IDF4.1 .
Component1 uses component1a using PRIV_REQUIRES property.
Component1a resides in the components folder of component1 and could be a git submodule.
Goal is to have the idf build process automatically resolve this nesting.
Some boilerplate in component1 is allowed, but nothing that requires knowledge of folder structure of component1a.
In the root only generic code is allowed, no code that requires specific knowledge of names or paths of nested components.
In short: create a component that can be (infinitely) nested in a project.

# Folder structure

`tree`:

```
CMakeLists.txt
├── components
│   ├── component1
│   │   ├── CMakeLists.txt
│   │   ├── components
│   │   │   └── component1a
│   │   │       ├── CMakeLists.txt
│   │   │       ├── inc
│   │   │       │   └── component1a.h
│   │   │       └── src
│   │   │           └── component1a.c
│   │   ├── inc
│   │   │   └── component1.h
│   │   ├── project_include.cmake
│   │   └── src
│   │       └── component1.c
│   └── component2
│       ├── CMakeLists.txt
│       ├── inc
│       │   └── component2.h
│       └── src
│           └── component2.c
├── main
│   ├── CMakeLists.txt
│   ├── component.mk
│   └── main.cpp
├── README.md
└── sdkconfig
```

# Attempts:
* add the following line to root CMakeLists.txt: `set(EXTRA_COMPONENT_DIRS components/component1/components)` -> works, but is ugly workaround
* move component1a to root component folder -> works but is ugly workaround
* include sources and headerfiles from component1a in component1 as source files and private header files -> works but is ugly workaround
* just leave the component in a component folder of a component1 -> `Failed to resolve component 'component1a'`
* Use EXTRA_COMPONENT_DIRS in CMakeLists.txt of component1 -> `Failed to resolve component 'component1a'`
* use project_include.cmake in component1 to add component1a -> `Failed to resolve component 'component1a'`

# References
* forum: https://esp32.com/viewtopic.php?t=13991
* https://docs.espressif.com/projects/esp-idf/en/release-v4.1/api-guides/build-system.html
* https://docs.espressif.com/projects/esp-idf/en/release-v4.1/api-guides/build-system.html#requirements-in-the-build-system-implementation
* https://docs.espressif.com/projects/esp-idf/en/release-v4.1/api-guides/build-system.html#project-include-cmake
* https://docs.espressif.com/projects/esp-idf/en/release-v4.1/api-guides/build-system.html#writing-pure-cmake-components
* https://docs.espressif.com/projects/esp-idf/en/release-v4.1/api-guides/build-system.html#project-cmakelists-file
* https://docs.espressif.com/projects/esp-idf/en/release-v4.1/api-guides/build-system.html#idf-component-commands
* https://docs.espressif.com/projects/esp-idf/en/release-v4.1/api-guides/build-system.html#component-configuration
