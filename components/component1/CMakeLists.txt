#set(EXTRA_COMPONENT_DIRS COMPONENT_DIR/components)
idf_component_register(SRC_DIRS "src"
                       INCLUDE_DIRS "inc"
                       PRIV_REQUIRES component1a)

