# Lite2Sheet

Lite2Sheet is a lightweight C++ tool that converts **SQLite/LiteSQL databases** into spreadsheets. It leverages modern C++ features, CMake for build configuration, and vcpkg for dependency management. The project aims to provide a fast, reliable, and cross-platform solution for database-to-spreadsheet conversions.

---

## Features

- Convert SQLite database tables to Excel/CSV format
- Modern C++20 codebase
- Easy dependency management with vcpkg
- Cross-platform build using CMake
- Optional logging and formatting via `fmt`

---

## Dependencies

This project uses:

- [fmt](https://github.com/fmtlib/fmt) — for modern, safe string formatting
- [SQLite3](https://www.sqlite.org/index.html) — lightweight database engine (optional, if you plan to extend)
- CMake >= 3.15
- [vcpkg](https://vcpkg.io/en/) (for dependency management)
- C++20 compatible compiler (MSVC, GCC, or Clang)

---