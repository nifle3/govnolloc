lib = shared_library(
  'mylib',
  sources: 'govnolloc.c',
  include_directories: include_directories('.'),
  version: meson.project_version(),
  soversion: '1',
  install: true
)

install_headers('govnolloc.h')

lib_dep = declare_dependency(
  link_with: lib,
  include_directories: include_directories('.')
)
