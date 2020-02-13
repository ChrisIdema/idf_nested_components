# idf_nested_components
Attempt to build a project with nested components using ESP IDF4.1 .
Component1 uses component1a using PRIV_REQUIRES property.

# Attempts:
* add the following line to main CMakeLists.txt: `set(EXTRA_COMPONENT_DIRS components/component1/components)` -> works, but is ugly workaround
* move component1a to main component folder -> works but is ugly workaround
* just add the component in a component folder of a component1 -> `Failed to resolve component 'component1a'`
* Use EXTRA_COMPONENT_DIRS in CMakeLists.txt of component1 -> doesn't work
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

